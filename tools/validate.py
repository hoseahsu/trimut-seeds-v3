#!/usr/bin/env python3
"""Execute recorded checks for TriMut recipes; never infer unperformed validation.

Trusted recipe contract (recipe modules are local experiment code, not submissions):

    RECIPES = {"id": {
        "source_id": "platform:real-original-id",
        "raw_fast": "../assets/raw.cpp", "raw_oracle": "../assets/brute.py",
        "l3_fast": {"path": "../assets/fast.cpp", "args": ["l3"]},
        "l3_oracle": {"path": "../assets/brute.py", "args": ["l3"]},
        "slow_baseline": "../assets/slow.cpp",
        "budget_seconds": 2.0, "memory_mb": 512,
        "independent_oracles": True,
        # Optional: small_timeout_seconds (default 10), max_output_bytes (8 MiB),
        # fast_margin (0.8), slow_cpu_fraction (0.7), compile_seconds (60).
    }}

    def cases(recipe_id, mode, rng):
        # mode is small / boundary / weak / stress; rng is random.Random.
        # Return finite iterable of (unique_case_name, UTF-8_input_text).
        yield ("example", "3\\n1 2 3\\n")

    def validate_input(recipe_id, input_text, condition):
        # condition is raw / weak / l2 / l3. Strict boolean True required.
        return True

    # Optional; needed for nonunique or special outputs. Must check output
    # validity/optimality, not merely feasibility. oracle_text is a trusted
    # independently computed expected answer on small/weak cases.
    def check_output(recipe_id, input_text, candidate_text, oracle_text, condition):
        return candidate_text.split() == oracle_text.split()

    # Optional extra witness restriction. This cannot override rejection by
    # check_output(..., raw_output, l3_oracle_output, "l3").
    def distinguishes(recipe_id, input_text, raw_output, l3_output):
        return raw_output.split() != l3_output.split()

Paths are relative to the recipe module. A program is a .cpp/.cc/.cxx/.py
source, or {path, args: [...], include_dirs: [...]}. C++ is compiled with
g++ -std=c++17 -O2 -pipe. Local sibling headers are available; extra include
directories are mounted read-only. Runtime uses only source or executable,
system runtimes, and an ephemeral /tmp. Network/PID/user namespaces are
isolated using bubblewrap. There is no unsandboxed execution fallback.

Recipe import, generators, validators and checkers are trusted Python and run
in the harness process. Never load downloaded/unreviewed Python as a recipe.
Downloaded reference/submission programs run only within bubblewrap, including
compilation. The sandbox is defense in depth, not a formal security proof.

Checks: raw and L3 fast/oracle agreement on small+boundary cases; a concrete
L3 witness that is invalid under the new specification; raw fast/slow/oracle
agreement on weak cases; repeated weak-fast/weak-slow and stress-fast/stress-slow
measurements under a frozen CPU budget and a separate wall watchdog. Strong slow runs must time out with
sufficient measured CPU consumption, and fast runs must stay below a margin.
If any required evidence is absent, qualification is false. Finite checks do
not prove correctness for all inputs; independent_oracles is an author claim,
reported explicitly, and not a mathematical independence proof.

Usage:
  python3 validate.py --recipe ../recipes/batch.py --output ../validation/batch
  python3 validate.py --recipe ../recipes/batch.py --id some-id --repeats 3 ...
  python3 validate.py --probe-sandbox
"""

from __future__ import annotations

import argparse
import hashlib
import importlib.util
import json
import math
import os
from pathlib import Path
import platform
import random
import resource
import shutil
import signal
import subprocess
import sys
import tempfile
import time
import traceback
from datetime import datetime, timezone
from typing import Any


VERSION = "1.1.1"
ROLES = ("raw_fast", "raw_oracle", "l3_fast", "l3_oracle", "slow_baseline")
MODES = ("small", "boundary", "weak", "stress")


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def file_hash(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def write_json(path: Path, value: Any) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + ".tmp")
    temporary.write_text(json.dumps(value, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    temporary.replace(path)


def slug(value: str) -> str:
    prefix = "".join(c if c.isalnum() or c in "-_." else "_" for c in value)[:80]
    return (prefix or "case") + "-" + sha(value.encode())[:10]


def limits(timeout: float, memory_mb: int, output_bytes: int) -> None:
    os.setsid()
    if hasattr(os, "sched_getaffinity"):
        os.sched_setaffinity(0, {min(os.sched_getaffinity(0))})
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))
    resource.setrlimit(resource.RLIMIT_AS, (memory_mb * 1024**2, memory_mb * 1024**2))
    # /proc sampling enforces subsecond CPU budgets; this is a backstop.
    cpu = max(1, math.ceil(timeout) + 1)
    resource.setrlimit(resource.RLIMIT_CPU, (cpu, cpu + 1))
    resource.setrlimit(resource.RLIMIT_FSIZE, (output_bytes, output_bytes))
    resource.setrlimit(resource.RLIMIT_NOFILE, (128, 128))


class Sandbox:
    def __init__(self) -> None:
        self.bwrap = shutil.which("bwrap")
        self.available = False
        self.probe: dict[str, Any] = {}
        if not self.bwrap:
            self.probe = {"available": False, "reason": "bubblewrap executable not found"}
            return
        try:
            p = subprocess.run(self.base() + ["/usr/bin/true"], stdin=subprocess.DEVNULL,
                               capture_output=True, timeout=8, check=False)
            self.available = p.returncode == 0
            self.probe = {"available": self.available, "returncode": p.returncode,
                          "stderr": p.stderr.decode(errors="replace")[:4000]}
        except (OSError, subprocess.TimeoutExpired) as exc:
            self.probe = {"available": False, "reason": str(exc)}

    def base(self) -> list[str]:
        if not self.bwrap:
            raise RuntimeError("bubblewrap is unavailable")
        args = [self.bwrap, "--unshare-all", "--die-with-parent", "--new-session",
                "--clearenv", "--setenv", "PATH", "/usr/bin:/bin",
                "--setenv", "LANG", "C.UTF-8", "--setenv", "LC_ALL", "C.UTF-8",
                "--setenv", "HOME", "/tmp", "--setenv", "TMPDIR", "/tmp"]
        for directory in ("/usr", "/bin", "/lib", "/lib64"):
            if Path(directory).exists():
                args += ["--ro-bind", directory, directory]
        args += ["--proc", "/proc", "--dev", "/dev", "--tmpfs", "/tmp", "--chdir", "/tmp"]
        return args

    def execute(self, command: list[str], mounts: list[str], input_bytes: bytes,
                timeout: float, memory_mb: int, output_bytes: int,
                evidence_prefix: Path) -> dict[str, Any]:
        if not self.available:
            raise RuntimeError("Sandbox probe failed; refusing program execution")
        evidence_prefix.parent.mkdir(parents=True, exist_ok=True)
        outpath = evidence_prefix.with_suffix(".stdout")
        errpath = evidence_prefix.with_suffix(".stderr")
        before = resource.getrusage(resource.RUSAGE_CHILDREN)
        start = time.perf_counter()
        timed_out = False
        timeout_reason = None
        watchdog = max(5.0, 4.0 * timeout + 1.0)
        ticks_per_second = os.sysconf("SC_CLK_TCK")
        observed_cpu_ticks = {}

        def sample_tree_cpu(root_pid):
            pending = [root_pid]
            visited = set()
            while pending:
                pid = pending.pop()
                if pid in visited:
                    continue
                visited.add(pid)
                try:
                    stat = Path(f"/proc/{pid}/stat").read_text().rsplit(")", 1)[1].split()
                    key = (pid, int(stat[19]))  # PID and process start time.
                    observed_cpu_ticks[key] = max(observed_cpu_ticks.get(key, 0), int(stat[11]) + int(stat[12]))
                    children = Path(f"/proc/{pid}/task/{pid}/children").read_text().split()
                    pending.extend(map(int, children))
                except (OSError, ValueError, IndexError):
                    continue
            return sum(observed_cpu_ticks.values()) / ticks_per_second
        invocation = self.base() + mounts + command
        # Input is a regular file to avoid parent pipe deadlocks or unbounded
        # communicate buffers; stdout/stderr are capped by RLIMIT_FSIZE.
        with tempfile.TemporaryFile() as inp, outpath.open("wb") as out, errpath.open("wb") as err:
            inp.write(input_bytes)
            inp.seek(0)
            proc = subprocess.Popen(invocation, stdin=inp, stdout=out, stderr=err,
                                    env={}, close_fds=True,
                                    preexec_fn=lambda: limits(timeout, memory_mb, output_bytes))
            while proc.poll() is None:
                sampled_cpu = sample_tree_cpu(proc.pid)
                if sampled_cpu >= timeout:
                    timed_out = True
                    timeout_reason = "cpu_limit"
                elif time.perf_counter() - start >= watchdog:
                    timed_out = True
                    timeout_reason = "wall_watchdog"
                if timed_out:
                    try:
                        os.killpg(proc.pid, signal.SIGKILL)
                    except ProcessLookupError:
                        pass
                    proc.wait(timeout=5)
                    break
                time.sleep(0.005)
        wall = time.perf_counter() - start
        after = resource.getrusage(resource.RUSAGE_CHILDREN)
        user_cpu = max(0.0, after.ru_utime - before.ru_utime)
        system_cpu = max(0.0, after.ru_stime - before.ru_stime)
        sampled_cpu = sum(observed_cpu_ticks.values()) / ticks_per_second
        total_cpu = max(user_cpu + system_cpu, sampled_cpu)
        size = outpath.stat().st_size
        stderr_size = errpath.stat().st_size
        if timed_out:
            status = "TLE"
        elif size >= output_bytes or stderr_size >= output_bytes:
            status = "OLE"
        elif proc.returncode == 0:
            status = "OK"
        else:
            status = "RE"
        result = {"status": status, "returncode": proc.returncode,
                  "wall_seconds": wall, "cpu_user_seconds": user_cpu,
                  "cpu_system_seconds": system_cpu, "cpu_seconds": total_cpu,
                  "sampled_process_tree_cpu_seconds": sampled_cpu,
                  "timeout_reason": timeout_reason,
                  "cpu_budget_seconds": timeout, "wall_watchdog_seconds": watchdog,
                  "cpu_affinity": min(os.sched_getaffinity(0)), "memory_limit_mb": memory_mb,
                  "stdout_bytes": size, "stdout_sha256": file_hash(outpath),
                  "stderr_sha256": file_hash(errpath), "stdout_path": str(outpath),
                  "stderr_path": str(errpath),
                  "sandbox": "bubblewrap-unshare-all-no-network",
                  "measurement_note": "CPU is max(reaped child usage, cumulative /proc process-tree samples), including sandbox overhead. /proc sampling preserves evidence when namespace processes are killed. Sampling interval 5ms, clock-tick precision; peak RSS not measured."}
        write_json(evidence_prefix.with_suffix(".run.json"), result)
        return result


class Programs:
    def __init__(self, sandbox: Sandbox, module_dir: Path, root: Path, cfg: dict[str, Any]):
        self.sandbox = sandbox
        self.module_dir = module_dir
        self.root = root
        self.cfg = cfg
        self.prepared: dict[str, dict[str, Any]] = {}

    def resolve(self, path: str) -> Path:
        resolved = (self.module_dir / path).resolve()
        if not resolved.exists():
            raise ValueError(f"Program/dependency path does not exist: {resolved}")
        return resolved

    def prepare(self, role: str) -> dict[str, Any]:
        value = self.cfg.get(role)
        if isinstance(value, str):
            value = {"path": value}
        if not isinstance(value, dict) or not isinstance(value.get("path"), str):
            raise ValueError(f"Missing program declaration: {role}")
        source = self.resolve(value["path"])
        arguments = value.get("args", [])
        if not isinstance(arguments, list) or any(not isinstance(v, str) for v in arguments):
            raise ValueError(f"{role}.args must be a string list")
        includes = [self.resolve(p) for p in value.get("include_dirs", [])]
        if any(not p.is_dir() for p in includes):
            raise ValueError(f"{role}.include_dirs must contain directories")
        meta: dict[str, Any] = {"source_path": str(source), "source_sha256": file_hash(source),
                                "args": arguments, "include_dirs": [str(p) for p in includes]}
        if source.suffix in (".cpp", ".cc", ".cxx"):
            build_dir = self.root / "build" / role
            build_dir.mkdir(parents=True, exist_ok=True)
            binary = build_dir / "program"
            # Include directory manifests retain evidence of the actual header
            # assets used. Local relative headers are likewise preserved.
            deps = {}
            for directory in [source.parent, *includes]:
                for item in sorted(directory.rglob("*")):
                    if item.is_file() and item.suffix in (".h", ".hpp", ".hh", ".inc", ".cpp", ".cc", ".cxx"):
                        deps[str(item)] = file_hash(item)
            meta["header_sha256"] = deps
            mounts = ["--ro-bind", str(source.parent), "/src", "--bind", str(build_dir), "/work"]
            command = ["/usr/bin/g++", "-std=c++17", "-O2", "-pipe", "/src/" + source.name, "-o", "/work/program"]
            for i, directory in enumerate(includes):
                mounts += ["--ro-bind", str(directory), f"/include{i}"]
                command += ["-I", f"/include{i}"]
            compiled = self.sandbox.execute(command, mounts, b"", float(self.cfg.get("compile_seconds", 60)),
                                            2048, 64 * 1024**2, self.root / "compile" / role)
            meta["compile"] = compiled
            if compiled["status"] != "OK" or not binary.is_file():
                raise ValueError(f"{role} compile failed: {compiled['status']}; see {compiled['stderr_path']}")
            meta["binary_sha256"] = file_hash(binary)
            meta["command"] = ["/program", *arguments]
            meta["mounts"] = ["--ro-bind", str(binary), "/program"]
        elif source.suffix == ".py":
            if not Path("/usr/bin/python3").exists():
                raise ValueError("Sandbox Python requires /usr/bin/python3")
            meta["command"] = ["/usr/bin/python3", "-I", "-B", "/code/" + source.name, *arguments]
            meta["mounts"] = ["--ro-bind", str(source.parent), "/code"]
        else:
            raise ValueError(f"Unsupported source language: {source.suffix}")
        self.prepared[role] = meta
        return meta

    def run(self, role: str, input_text: str, timeout: float, prefix: Path) -> dict[str, Any]:
        meta = self.prepared[role]
        return self.sandbox.execute(meta["command"], meta["mounts"], input_text.encode("utf-8"),
                                    timeout, int(self.cfg["memory_mb"]),
                                    int(self.cfg.get("max_output_bytes", 8 * 1024**2)), prefix)


def output(run: dict[str, Any]) -> str:
    return Path(run["stdout_path"]).read_text(encoding="utf-8", errors="strict")


def accepted(module: Any, recipe_id: str, inp: str, candidate: str, expected: str, condition: str) -> bool:
    if hasattr(module, "check_output"):
        return module.check_output(recipe_id, inp, candidate, expected, condition) is True
    return candidate.split() == expected.split()


def valid(module: Any, recipe_id: str, inp: str, condition: str) -> bool:
    if not hasattr(module, "validate_input"):
        raise ValueError("Recipe must provide validate_input; no permissive fallback")
    return module.validate_input(recipe_id, inp, condition) is True


def validate_one(module: Any, module_path: Path, recipe_id: str, root: Path,
                 sandbox: Sandbox, seed: int, repeats: int) -> dict[str, Any]:
    cfg = module.RECIPES[recipe_id]
    result: dict[str, Any] = {
        "recipe_id": recipe_id, "source_id": cfg.get("source_id"), "harness_version": VERSION,
        "recipe_sha256": file_hash(module_path), "random_seed": seed,
        "repeat_count": repeats, "started_at_utc": datetime.now(timezone.utc).isoformat(),
        "qualified": False, "statuses": {"smoke_tested": False, "semantically_validated": False,
                                           "stress_calibrated": False},
        "independent_oracles_author_claim": cfg.get("independent_oracles") is True,
        "limitations": ["Finite differential testing is not a proof for all legal inputs.",
                        "This harness does not establish source provenance, source-statement fidelity, or human semantic review.",
                        "L2 measurements apply only to the recorded host, programs, cases, and CPU budget."],
        "failures": [], "cases": {}, "l3_witnesses": [], "programs": {},
    }
    root.mkdir(parents=True, exist_ok=True)
    report_path = root / "report.json"

    def fail(message: str) -> None:
        result["failures"].append(message)

    try:
        if not isinstance(cfg.get("source_id"), str) or not cfg["source_id"]:
            raise ValueError("source_id is required")
        budget = float(cfg["budget_seconds"])
        memory = int(cfg["memory_mb"])
        small_timeout = float(cfg.get("small_timeout_seconds", 10))
        margin = float(cfg.get("fast_margin", 0.8))
        cpu_fraction = float(cfg.get("slow_cpu_fraction", 0.7))
        if not 0 < budget <= 120 or not 32 <= memory <= 16384 or not 0 < margin <= 1 or not 0 < cpu_fraction <= 1:
            raise ValueError("Invalid budget, memory, fast_margin, or slow_cpu_fraction")
        result["frozen_budget"] = {"cpu_seconds": budget, "memory_mb": memory,
                                    "fast_margin": margin, "slow_cpu_fraction": cpu_fraction}
        if repeats < 2:
            fail("At least two repeats are required for stress qualification")
        if not result["independent_oracles_author_claim"]:
            fail("Recipe author has not explicitly asserted independently constructed oracles")
        if not sandbox.available:
            raise RuntimeError("Sandbox unavailable: " + json.dumps(sandbox.probe))
        programs = Programs(sandbox, module_path.parent, root, cfg)
        for role in ROLES:
            result["programs"][role] = programs.prepare(role)
        # Identical program+arguments cannot count as independently implemented.
        for a, b in (("raw_fast", "raw_oracle"), ("l3_fast", "l3_oracle")):
            pa, pb = result["programs"][a], result["programs"][b]
            if pa["source_sha256"] == pb["source_sha256"] and pa["args"] == pb["args"]:
                fail(f"{a} and {b} are identical; independent oracle missing")
        suites: dict[str, list[tuple[str, str, Path]]] = {}
        for mode in MODES:
            suite = []
            names = set()
            mode_seed = seed ^ int(sha((recipe_id + ":" + mode).encode())[:16], 16)
            for index, item in enumerate(module.cases(recipe_id, mode, random.Random(mode_seed))):
                if index >= 10000:
                    raise ValueError("Recipe yielded over 10,000 cases in one suite")
                if not isinstance(item, (list, tuple)) or len(item) != 2 or not all(isinstance(v, str) for v in item):
                    raise ValueError("cases() items must be (name: str, input_text: str)")
                name, inp = item
                if name in names:
                    raise ValueError(f"Duplicate case name {mode}:{name}")
                names.add(name)
                case_dir = root / "cases" / mode / (f"{index:04d}-" + slug(name))
                case_dir.mkdir(parents=True, exist_ok=True)
                input_path = case_dir / "input.txt"
                input_path.write_text(inp, encoding="utf-8")
                suite.append((name, inp, case_dir))
            suites[mode] = suite
            result["cases"][mode] = []
            if not suite:
                fail(f"Required {mode} suite is empty")
        semantic_ok = True
        witness_found = False
        smoke_successes = 0
        for mode in ("small", "boundary"):
            for name, inp, directory in suites[mode]:
                entry: dict[str, Any] = {"name": name, "input_sha256": sha(inp.encode()), "input_path": str(directory / "input.txt"), "runs": {}}
                result["cases"][mode].append(entry)
                entry["valid_raw"] = valid(module, recipe_id, inp, "raw")
                entry["valid_l3"] = valid(module, recipe_id, inp, "l3")
                if not entry["valid_raw"] or not entry["valid_l3"]:
                    semantic_ok = False
                    fail(f"Invalid input in {mode}:{name}")
                    continue
                for role in ("raw_fast", "raw_oracle", "l3_fast", "l3_oracle"):
                    entry["runs"][role] = programs.run(role, inp, small_timeout, directory / role)
                if any(run["status"] != "OK" for run in entry["runs"].values()):
                    semantic_ok = False
                    fail(f"Program execution failed in {mode}:{name}")
                    continue
                smoke_successes += 1
                texts = {role: output(run) for role, run in entry["runs"].items()}
                entry["raw_agreement"] = accepted(module, recipe_id, inp, texts["raw_fast"], texts["raw_oracle"], "raw")
                entry["l3_agreement"] = accepted(module, recipe_id, inp, texts["l3_fast"], texts["l3_oracle"], "l3")
                # Check oracle outputs themselves, catching malformed oracle output
                # in semantic checkers. Token equality alone cannot provide this.
                entry["oracle_self_validity"] = all(accepted(module, recipe_id, inp, texts[role], texts[role], condition)
                                                     for role, condition in (("raw_oracle", "raw"), ("l3_oracle", "l3")))
                if not all((entry["raw_agreement"], entry["l3_agreement"], entry["oracle_self_validity"])):
                    semantic_ok = False
                    fail(f"Differential disagreement in {mode}:{name}")
                rejected_old = not accepted(module, recipe_id, inp, texts["raw_fast"], texts["l3_oracle"], "l3")
                extra = (module.distinguishes(recipe_id, inp, texts["raw_fast"], texts["l3_fast"]) is True
                         if hasattr(module, "distinguishes") else texts["raw_fast"].split() != texts["l3_fast"].split())
                entry["distinguishing_witness"] = rejected_old and extra and entry["raw_agreement"] and entry["l3_agreement"]
                if entry["distinguishing_witness"]:
                    witness_found = True
                    result["l3_witnesses"].append({"input_path": entry["input_path"], "input_sha256": entry["input_sha256"],
                                                   "raw_output_path": entry["runs"]["raw_fast"]["stdout_path"],
                                                   "l3_output_path": entry["runs"]["l3_fast"]["stdout_path"]})
        if not witness_found:
            fail("No accepted input with an old answer rejected under the new specification")
        if len(suites["small"]) < 8:
            fail("Small suite has fewer than eight cases")
            semantic_ok = False
        if not suites["boundary"]:
            semantic_ok = False
        weak_ok = bool(suites["weak"])
        strong_ok = bool(suites["stress"])
        for name, inp, directory in suites["weak"]:
            entry = {"name": name, "input_sha256": sha(inp.encode()), "input_path": str(directory / "input.txt"), "runs": []}
            result["cases"]["weak"].append(entry)
            if not valid(module, recipe_id, inp, "weak"):
                weak_ok = False
                fail(f"Invalid weak input: {name}")
                continue
            oracle = programs.run("raw_oracle", inp, small_timeout, directory / "oracle")
            entry["oracle"] = oracle
            if oracle["status"] != "OK":
                weak_ok = False
                fail(f"Weak oracle failed: {name}")
                continue
            expected = output(oracle)
            for repeat in range(repeats):
                for role in ("raw_fast", "slow_baseline"):
                    run = programs.run(role, inp, budget, directory / f"{role}-{repeat}")
                    run["role"] = role
                    run["repeat"] = repeat
                    run["answer_accepted"] = run["status"] == "OK" and accepted(module, recipe_id, inp, output(run), expected, "weak")
                    entry["runs"].append(run)
                    if not run["answer_accepted"]:
                        weak_ok = False
                        fail(f"Weak {role} failed: {name}, repeat {repeat}")
        for name, inp, directory in suites["stress"]:
            entry = {"name": name, "input_sha256": sha(inp.encode()), "input_path": str(directory / "input.txt"), "runs": []}
            result["cases"]["stress"].append(entry)
            if not valid(module, recipe_id, inp, "l2"):
                strong_ok = False
                fail(f"Invalid strong input: {name}")
                continue
            fast_answers = []
            for repeat in range(repeats):
                # Alternate order reduces systematic first-run/cache advantage.
                order = ("raw_fast", "slow_baseline") if repeat % 2 == 0 else ("slow_baseline", "raw_fast")
                for role in order:
                    run = programs.run(role, inp, budget, directory / f"{role}-{repeat}")
                    run["role"] = role
                    run["repeat"] = repeat
                    entry["runs"].append(run)
                    if role == "raw_fast":
                        run["fast_with_margin"] = run["status"] == "OK" and run["cpu_seconds"] <= budget * margin
                        if not run["fast_with_margin"]:
                            strong_ok = False
                            fail(f"Strong fast failed or lacks timing margin: {name}, repeat {repeat}")
                        if run["status"] == "OK":
                            fast_answers.append(output(run).split())
                    else:
                        run["cpu_supported_timeout"] = run["status"] == "TLE" and run.get("timeout_reason") == "cpu_limit" and run["cpu_seconds"] >= budget * cpu_fraction
                        if not run["cpu_supported_timeout"]:
                            strong_ok = False
                            fail(f"Strong slow lacks CPU-supported timeout: {name}, repeat {repeat}")
            entry["fast_repeat_outputs_agree"] = len(fast_answers) == repeats and all(a == fast_answers[0] for a in fast_answers)
            if not entry["fast_repeat_outputs_agree"]:
                strong_ok = False
                fail(f"Strong fast outputs unstable: {name}")
            entry["correctness_note"] = "Strong result is not independently oracle-checked; semantic evidence comes from small/boundary and weak differential tests."
        result["statuses"]["smoke_tested"] = smoke_successes > 0
        result["statuses"]["semantically_validated"] = bool(semantic_ok and witness_found and result["independent_oracles_author_claim"])
        result["statuses"]["stress_calibrated"] = bool(weak_ok and strong_ok and repeats >= 2)
        result["qualified"] = all(result["statuses"].values()) and not result["failures"]
        result["qualification_scope"] = "Passed recorded finite semantic checks and measured L2 contrast; source fidelity and review are outside this harness."
    except Exception as exc:
        fail(f"{type(exc).__name__}: {exc}")
        result["error_traceback"] = traceback.format_exc()
    result["finished_at_utc"] = datetime.now(timezone.utc).isoformat()
    write_json(report_path, result)
    return result


def load_recipe(path: Path) -> Any:
    spec = importlib.util.spec_from_file_location("trimut_recipe_" + sha(str(path).encode())[:12], path)
    if spec is None or spec.loader is None:
        raise ValueError(f"Cannot load recipe: {path}")
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    if not isinstance(getattr(module, "RECIPES", None), dict):
        raise ValueError("Recipe module must export RECIPES dict")
    if not callable(getattr(module, "cases", None)) or not callable(getattr(module, "validate_input", None)):
        raise ValueError("Recipe module must define cases() and validate_input()")
    return module


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--recipe", type=Path)
    parser.add_argument("--id", action="append", dest="ids")
    parser.add_argument("--output", type=Path)
    parser.add_argument("--seed", type=int, default=20261022)
    parser.add_argument("--repeats", type=int, default=3)
    parser.add_argument("--probe-sandbox", action="store_true")
    args = parser.parse_args()
    sandbox = Sandbox()
    if args.probe_sandbox:
        print(json.dumps(sandbox.probe, ensure_ascii=False))
        return 0 if sandbox.available else 2
    if args.recipe is None or args.output is None:
        parser.error("--recipe and --output are required unless --probe-sandbox")
    if args.repeats < 1 or args.repeats > 20:
        parser.error("--repeats must be in [1,20]")
    path = args.recipe.resolve()
    root = args.output.resolve()
    root.mkdir(parents=True, exist_ok=True)
    environment = {"harness_version": VERSION, "harness_sha256": file_hash(Path(__file__).resolve()),
                   "recipe_path": str(path), "python": sys.version, "platform": platform.platform(),
                   "machine": platform.machine(), "logical_cpus": os.cpu_count(),
                   "sandbox_probe": sandbox.probe,
                   "security": "All contestant/reference execution and compilation require bubblewrap. Recipe Python is trusted local code.",
                   "time_budget_kind": "sampled CPU per process tree; separate wall watchdog; pinned CPU",
                   "started_at_utc": datetime.now(timezone.utc).isoformat()}
    if Path("/proc/cpuinfo").exists():
        text = Path("/proc/cpuinfo").read_text(errors="replace")
        environment["cpu_model"] = next((line.partition(":")[2].strip() for line in text.splitlines() if line.startswith("model name")), None)
    write_json(root / "environment.json", environment)
    if not sandbox.available:
        print("Sandbox unavailable; no recipe code or reference programs executed. See environment.json.", file=sys.stderr)
        return 2
    module = load_recipe(path)
    ids = args.ids or list(module.RECIPES)
    if len(ids) != len(set(ids)) or any(i not in module.RECIPES for i in ids):
        parser.error("Unknown or repeated recipe ID")
    reports = []
    for recipe_id in ids:
        report = validate_one(module, path, recipe_id, root / slug(recipe_id), sandbox, args.seed, args.repeats)
        reports.append({"recipe_id": recipe_id, "source_id": report.get("source_id"),
                        "qualified": report["qualified"], "statuses": report["statuses"],
                        "report_path": str(root / slug(recipe_id) / "report.json"),
                        "failures": report["failures"]})
        write_json(root / "summary.json", {"complete": False, "requested_count": len(ids), "processed_count": len(reports),
                                           "qualified_count": sum(r["qualified"] for r in reports), "recipes": reports})
        print(json.dumps(reports[-1], ensure_ascii=False), flush=True)
    source_ids = [r["source_id"] for r in reports]
    summary = {"complete": True, "requested_count": len(ids), "processed_count": len(reports),
               "qualified_count": sum(r["qualified"] for r in reports),
               "unique_source_id_count": len(set(source_ids)), "duplicate_source_ids": sorted({x for x in source_ids if source_ids.count(x) > 1}),
               "recipes": reports}
    write_json(root / "summary.json", summary)
    return 0 if reports and all(r["qualified"] for r in reports) and not summary["duplicate_source_ids"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
