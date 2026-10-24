#!/usr/bin/env python3
"""Run this agent's trusted build workers serially on CPU1; all target programs remain in bubblewrap."""
from pathlib import Path
import argparse,json,os,signal,subprocess,sys,time
R=Path(__file__).resolve().parents[1];W=R/'library_work'
def stop_own_workers():
 stopped=[];names={'build_native_tests.py','build_l2_tests.py','supplement_native_tests.py'}
 for d in Path('/proc').iterdir():
  if not d.name.isdigit()or int(d.name)==os.getpid():continue
  try:
   cmd=(d/'cmdline').read_bytes().decode().split('\0');cwd=(d/'cwd').resolve()
   if cwd!=R.parents[1]:continue
   if len(cmd)>1 and Path(cmd[0]).name.startswith('python') and Path(cmd[1]).name in names and 'trimut_seed300_strict/library_work/'in cmd[1]:
    os.kill(int(d.name),signal.SIGTERM);stopped.append({'pid':int(d.name),'command':cmd})
  except (OSError,ValueError,PermissionError):continue
 print(json.dumps({'stopped_own_workers':stopped}),flush=True)
 time.sleep(1)
def main():
 p=argparse.ArgumentParser();p.add_argument('stage',choices=['native','l2','supplement','repair']);p.add_argument('--stop-old',action='store_true');p.add_argument('--ids',nargs='*');a=p.parse_args()
 assert os.sched_getaffinity(0)=={1},'Launch with taskset -c 1'
 if a.stop_old:stop_own_workers()
 script={'native':'build_native_tests.py','l2':'build_l2_tests.py','supplement':'supplement_native_tests.py','repair':'rerun_overrides.py'}[a.stage]
 cmd=[sys.executable,str(W/script)]
 if a.stage in('native','l2'):cmd+=['--resume']
 if a.ids:cmd+=['--ids',*a.ids]
 print(json.dumps({'cpu_affinity':list(os.sched_getaffinity(0)),'command':cmd}),flush=True)
 raise SystemExit(subprocess.call(cmd))
if __name__=='__main__':main()
