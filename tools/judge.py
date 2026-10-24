#!/usr/bin/env python3
"""Judge one C++17/Python submission against a frozen strict seed condition.
Usage: python3 tools/judge.py --seed TM002 --condition l3 --source answer.cpp
       python3 tools/judge.py --seed TM002 --condition l3 --reference --limit 3
Requires Linux, bubblewrap, /usr/bin/g++, /usr/bin/python3. No network in sandbox.
"""
import argparse,json,sys,hashlib,time
from pathlib import Path
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'recipes'),str(B/'assets')]
import validate

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def resolve(p):return (B/p).resolve()
def prepare(sandbox,decl,out):
 source=resolve(decl['path']);assert source.is_file();expected=decl.get('sha256')or decl.get('source_sha256')
 if expected:assert sha(source)==expected,'source SHA mismatch'
 for path,h in decl.get('dependency_sha256',{}).items():
  dep=resolve(path);assert dep.is_relative_to(B) and dep.is_file(),'invalid dependency path';assert sha(dep)==h,'dependency SHA mismatch: '+path
 args=decl.get('args',[]);mounts=[];meta={'source':str(source),'source_sha256':sha(source),'args':args}
 if source.suffix in('.cpp','.cc','.cxx'):
  build=out/'build';build.mkdir(parents=True,exist_ok=True);binary=build/'program';mounts=['--ro-bind',str(source.parent),'/src','--bind',str(build),'/work'];cmd=['/usr/bin/g++','-std=c++17','-O2','-pipe']
  flags=decl.get('compiler_options',[])
  if '-include'in flags:
   idx=flags.index('-include');assert flags[idx+1]in('cstdio','cstdint','bits/stdc++.h');cmd+=['-include',flags[idx+1]]
  for i,d in enumerate(decl.get('include_dirs',[])):
   path=resolve(d);assert path.is_dir();mounts+=['--ro-bind',str(path),f'/include{i}'];cmd+=['-I',f'/include{i}']
  cmd+=['/src/'+source.name,'-o','/work/program'];r=sandbox.execute(cmd,mounts,b'',120,2048,64*1024**2,out/'compile');meta['compile']=r
  if r['status']!='OK':raise RuntimeError('Compilation failed: '+r['stderr_path'])
  return ['/program',*args],['--ro-bind',str(binary),'/program'],meta
 if source.suffix=='.py':return ['/usr/bin/python3','-I','-B','/code/'+source.name,*args],['--ro-bind',str(source.parent),'/code'],meta
 raise ValueError('Supported languages: C++17 and Python3')
def main():
 a=argparse.ArgumentParser();a.add_argument('--seed',required=True);a.add_argument('--condition',choices=['raw','l1','l2','l3'],required=True);g=a.add_mutually_exclusive_group(required=True);g.add_argument('--source');g.add_argument('--reference',action='store_true');a.add_argument('--limit',type=int);a.add_argument('--case');a.add_argument('--output');a.add_argument('--index',default=str(B/'seeds.jsonl'));args=a.parse_args()
 seeds={x['seed_id']:x for x in map(json.loads,Path(args.index).read_text().splitlines())};seed=seeds[args.seed];cfg=seed['conditions'][args.condition];manifest=resolve(cfg['tests']['path']);assert sha(manifest)==cfg['tests']['sha256'];tests=json.loads(manifest.read_text())['records']
 if args.case:tests=[x for x in tests if x['name']==args.case]
 if args.limit is not None:assert args.limit>0;tests=tests[:args.limit]
 assert tests,'No selected tests'
 out=Path(args.output).resolve()if args.output else B/'runs'/f'{args.seed}_{args.condition}_{time.time_ns()}';out.mkdir(parents=True,exist_ok=False);sandbox=validate.Sandbox();assert sandbox.available,'bubblewrap unavailable; no unsafe fallback'
 decl=dict(cfg['reference_program'])if args.reference else {'path':str(Path(args.source).resolve()),'args':[]}
 cmd,mounts,meta=prepare(sandbox,decl,out);ck=seed['checker'];module=validate.load_recipe(resolve(ck['recipe_module']));results=[]
 for j,t in enumerate(tests):
  inp=resolve(t['input_path']);expected=resolve(t['expected_path']);assert sha(inp)==t['input_sha256']and sha(expected)==t['expected_sha256'],'frozen test SHA mismatch'
  text=inp.read_text();r=sandbox.execute(cmd,mounts,inp.read_bytes(),float(cfg['cpu_budget_seconds']),int(cfg['memory_mb']),128*1024**2,out/f'{j:04d}_{t["name"]}');verdict=r['status']
  if verdict=='OK':
   try:verdict='AC'if validate.accepted(module,ck['recipe_id'],text,validate.output(r),expected.read_text(),'l3'if args.condition=='l3'else'raw')else'WA'
   except Exception as e:raise RuntimeError('Trusted checker failed: '+repr(e))
  results.append({'name':t['name'],'verdict':verdict,'input_sha256':t['input_sha256'],'run':r});print(t['name'],verdict,flush=True)
 report={'seed_id':args.seed,'condition':args.condition,'source':meta,'test_manifest':cfg['tests'],'selected_test_count':len(tests),'full_frozen_suite':len(tests)==len(json.loads(manifest.read_text())['records']),'passed':all(r['verdict']=='AC'for r in results),'results':results};validate.write_json(out/'report.json',report);print(json.dumps({'passed':report['passed'],'test_count':len(tests),'report':str(out/'report.json')},ensure_ascii=False));return 0 if report['passed']else 1
if __name__=='__main__':sys.exit(main())
