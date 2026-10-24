# TriMut-300 Strict: 300 Public Source Problems and Three Mutation Axes

Each of the **300 public source problems** in this package exists in four versions — Raw, L1, L2, and L3 — which gives **1,200 statements** in total. The machine-readable entry point is [prompts.jsonl](prompts.jsonl). For a per-seed listing, see [INDEX.md](INDEX.md); programs, tests, and the evidence index are in [seeds.jsonl](seeds.jsonl).

## Exact Definitions of the Four Conditions

| Condition | Statement and mathematical task | Data constraints | Official tests |
|---|---|---|---|
| Raw | Unmutated public source problem; original rules, I/O, and samples preserved | Native constraints of the source problem | Original samples, legal boundaries, small-scale differential tests, original upper-bound cases, and selected source tests |
| L1 | Narrative, entity, or formal-object reinterpretation that preserves the mathematical semantics | Exactly the same as Raw | **Raw's own test list, inputs, answers, and resource budgets, referenced directly** |
| L2 | Original rule unchanged; the scale upper bound and the dependent constraints it forces are modified | Widened relative to the true source problem | The full Raw set, plus at least one legal expanded-domain test that really does exceed the original bound |
| L3 | Comparison, logic, aggregation, and state-transition operators modified, with dependent explanations and sample answers updated to match | Source input domain unchanged | The same input list as Raw, with answers regenerated under the new logic |

For Raw, "unmutated" means we leave the semantics and the native constraints alone. Where CodeContests typesetting had dropped a superscript, a formula, or an illustration link, we restored it from the public source; we expanded Library Checker's source template with its official parameters and samples. Each repair is logged in the per-seed `raw_provenance.json`, and we do not count a format repair as a mutation. The snapshots themselves are stored unchanged in `sources/`.

L1 splits into 153 narrative/entity substitutions and 147 formal-object reinterpretations. Every seed carries a reversible edit certificate, and that certificate checks four things: numerals, mathematical symbols, protected samples, and reconstruction of the source text. A formal problem in this group is not presented as though it had received a full story rewrite.

## Verification Completed, and Its Boundaries

Three things hold across all 300 seeds: an expanded-domain witness that is real, a small-domain L3 decision program kept independent of the reference, and at least one input on which Raw and L3 disagree. The reference programs pass the recorded legal tests inside the frozen budgets. Independent L3 small cases total **6,977**, and recorded distinguishing witnesses total **4,573**. Both figures count executed cases per seed, so read them as execution counts rather than independent statistical samples.

Official evaluation case occurrences run to **11,325** for Raw, **11,325** for L1, **11,705** for L2, and **11,325** for L3. Raw and L1 use the same data; Raw and L3 use the same inputs. Adding the four figures together yields nothing meaningful, because the sum is not a count of independent inputs.

**The 300/300 for L2 covers three things only: the scale really is expanded, the inputs are legal, and the reference solution runs through. On 5 seeds we went further and confirmed that "the same slow program passes the original bound and times out on the expanded domain."** On the remaining seeds that confirmation was not made, so they do not support a claim that an algorithmic paradigm shift will occur. The per-seed flag `l2_algorithm_resource_separation_validated` records where it was made. If you are analyzing PSR or an algorithmic transition, work from the calibrated subset alone, or add your own baseline calibration.

The verification used finite tests, small-domain differential comparison against an independent program, structural-case expectations worked out mathematically, and constructive arguments. None of this guarantees an error-free result on every legal input. Some large L3 answers came from efficient reference solutions that we had verified independently on small domains; we did not enumerate those answers case by case. The per-case metadata states which kind of evidence a case actually carries. Records of upstream corrupted tests, failed attempts, reference-program capacity, and platform compatibility fixes are all retained. You will not find target-model accuracy, human blind review, or unexecuted experimental results filled in anywhere.

## Getting Started

Every line of `prompts.jsonl` carries four fields and nothing else: `seed_id`, `condition`, the full `prompt`, and the statement hash. Send the `prompt` content to the model under test, and append the same code-output instruction to every request. Leave out the answers, the mutation explanations, the programs, and the verification reports.

Run these from inside this directory. The environment needs Linux, Python 3, g++, and bubblewrap:

```bash
# Check the integrity of all statements, programs, inputs, answers, and test lists
python3 tools/audit_release.py

# Evaluate one C++17 or Python file produced by a model
python3 tools/judge.py --seed TM002 --condition l3 --source /absolute/path/answer.cpp

# Use the built-in reference program to check the entry point; --limit 2 is only for a quick trial run
python3 tools/judge.py --seed TM002 --condition l3 --reference --limit 2
```

Drop `--limit` and you evaluate every official case of that condition; `--case NAME` reruns a single case. Compilation and execution happen inside a bubblewrap sandbox with no network, and resource limits come from the frozen per-seed metadata. Per-case results, among them AC/WA/TLE/RE, are printed, and the full logs go to `runs/`. Tasks whose answers are not unique are judged by their own checker — string equality is not applied where two different constructions are both legal.

Generate the four conditions separately: Raw, L1, L2, and L3 each get their own run. L1 borrows Raw's tests; its answers do not come from Raw's run. For paired analysis the seed is the unit, and **1,200 statements are not 1,200 independent source problems**. Keep all four versions of one source problem on the same side of a train/test split, and keep related problem families together as well. The `family_split_groups` field lists the groupings we know about and defaults to `unsplit`; it does not claim to have found every semantic similarity in the set.

## File Layout

- `tasks/TM001/` … `tasks/TM300/` — four complete statements per seed, plus its provenance and edit certificates, frozen inputs, and answers.
- `evaluation/TMxxx/` — the **unified evaluation entry point**: Raw, L2, and L3 manifests. L1 points at Raw, and L2 merges the original domain with the expanded one here.
- `contracts/` — per-seed original bounds, expansion axes, L3 rules, proof sketches, execution budgets, and the bindings between programs and evidence.
- `validation/` — real execution records, independent verification, the failure history, and the whole-package integrity audit.
- `sources/` — public source problems, source tests, upstream reference code, and license notes. Snapshots here are never overwritten.
- `assets/`, `native/`, `library_work/`, `replacements/` — reference solutions, independent decision programs, strict input validators, generators, and reconstruction tools.
- `recipes/` — reused implementation and comparator helpers. The legacy weak-constraint experiment fields there are historical implementation metadata, and **this package draws nothing from them for statements, constraints, budgets, or evaluation choices**. Those are governed by `seeds.jsonl → evaluation/, contracts/`.
- `release_summary.json` — actual counts, release status, and verification hashes.

Provenance per seed keeps whatever the source gave us: the platform problem ID, the CodeContests row index, or the Library Checker identifier. Where a CodeContests platform link could not be confirmed, we give the dataset link and the source snapshot rather than a guess; a generic dataset homepage is not presented as a link to the specific problem. Each upstream item — statements, images, code — keeps its own original license and copyright, and this local research package adds no blanket redistribution permission on top.

Thirteen source problems refer to 24 original illustrations, archived in `sources/original_illustrations/`, with the URL-to-local-path and hash mapping in `url_map.json`. We opened 19 of them. The other five are BMPs the preview tool cannot open, so for those we only compared file bytes against the recorded hash; the visual check was not done. These images belong to Raw, and their presence says nothing about whether the other variants have been adapted to match their figures.

## Export Packages

Use `trimut_seed300_strict_prompts.zip` to view or import the 1,200 statements. It carries the per-seed text and `prompts.jsonl`, and no judging data. For full experiments and reproduction, take `trimut_seed300_strict_full.tar.zst` instead:

```bash
tar --zstd -xf trimut_seed300_strict_full.tar.zst
cd trimut_seed300_strict
python3 tools/audit_release.py
```

That package keeps source code, inputs and answers, contracts, and run reports, and leaves out recompilable temporary programs and Python caches. Beside it, `trimut_seed300_strict_artifacts.json` records the export sizes, hashes, and packaging verification results.

Five candidates had source descriptions with ambiguity we could not resolve, and each was replaced by a different public source problem — see `replacements/index.json`. TM101 keeps an official sample whose daily strings are deliberately shortened, and we run it separately as an illustration; the official input domain there still requires 1,440 characters per day. The per-seed contracts list the detailed exceptions.
