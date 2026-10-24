#!/usr/bin/env python3
"""Freeze selected native tests and check native L3 in bubblewrap; not official full test suite."""
from pathlib import Path
import argparse,hashlib,importlib.util,json,random,resource,shutil,sys
R=Path(__file__).resolve().parents[1];sys.path.insert(0,str(R/'tools'))
from validate import Sandbox,Programs,write_json,file_hash,accepted

def load(path):
 s=importlib.util.spec_from_file_location(path.stem,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m

def compile_cpp(box,source,build,evidence,includes=(),base=None):
 build.mkdir(parents=True,exist_ok=True);binary=build/'program'
 digest=hashlib.sha256(source.read_bytes())
 # Generator helpers carry fixed-capacity structures. Their contents must participate
 # in the cache key, otherwise a capacity-only header repair can reuse stale code.
 for root in ([base]if base else [])+list(includes):
  root=Path(root);digest.update(str(root).encode())
  for dependency in sorted(p for p in root.rglob('*')if p.is_file()and p.suffix in ('.h','.hpp','.hh','.inc')):
   digest.update(str(dependency.relative_to(root)).encode());digest.update(dependency.read_bytes())
 signature=digest.hexdigest()
 stamp=build/'signature.txt'
 if binary.exists()and stamp.exists()and stamp.read_text()==signature:return binary
 mounts=['--ro-bind',str(base or source.parent),'/source','--bind',str(build),'/work'];inside='/source/'+str(source.relative_to(base or source.parent))
 cmd=['/usr/bin/g++','-std=c++17','-O2','-pipe','-include','cstdio',inside,'-o','/work/program']
 for i,d in enumerate(includes):mounts+=['--ro-bind',str(d),f'/include{i}'];cmd+=['-I',f'/include{i}']
 res=box.execute(cmd,mounts,b'',120,2048,64*1024**2,evidence)
 assert res['status']=='OK',('compile',source,res['stderr_path']);stamp.write_text(signature);return binary

def run(box,binary,inp,prefix,seconds=5,args=()):
 return box.execute(['/program',*map(str,args)],['--ro-bind',str(binary),'/program'],inp,seconds,1024,256*1024**2,prefix)

def dimensions(id,data):
 tok=data.split();d={}
 strings={'number_of_substrings','enumerate_palindromes','zalgorithm','lyndon_factorization','wildcard_pattern_matching'}
 if id in strings:return {'N':len(tok[0]),'S_LEN':len(tok[0]),'T_LEN':len(tok[1])if len(tok)>1 else 0}
 d['N']=int(tok[0])
 if id in {'closest_pair','furthest_pair','all_furthest_neighbors','static_convex_hull'}:
  d={'T':int(tok[0]),'SUM_N':0,'MAX_CASE_N':0};i=1
  for _ in range(d['T']):
   n=int(tok[i]);d['SUM_N']+=n;d['MAX_CASE_N']=max(d['MAX_CASE_N'],n);i+=1+2*n
  return d
 if id in {'sum_of_floor_of_linear','kth_root_integer'}:return {'T':int(tok[0])}
 if id in {'set_xor_min','queue_operate_all_composite','deque_operate_all_composite','associative_array','persistent_queue'}:return {'Q':int(tok[0])}
 first=data.splitlines()[0].split()
 if len(first)>=2:d['Q']=int(first[1]);d['M']=int(first[1])
 return d

def bound_hits(item,d):
 hits=[];p=item['native_params'];id=item['id']
 for k,v in p.items():
  if 'SMALL'in k:continue
  if k in ('N_AND_Q_MAX','MAX_N_Q'):
   for dim in ('N','Q'):
    if d.get(dim)==v:hits.append({'parameter':k,'dimension':dim,'value':v})
  else:
   dm={'N_MAX':'N','MAX_N':'N','Q_MAX':'Q','MAX_Q':'Q','T_MAX':'T','SUM_N_MAX':'SUM_N','S_LEN_MAX':'S_LEN'}.get(k)
   if dm and d.get(dm)==v:hits.append({'parameter':k,'dimension':dm,'value':v})
 literal={'point_set_range_composite':('Q',500000),'queue_operate_all_composite':('Q',500000),'deque_operate_all_composite':('Q',500000),'vertex_add_subtree_sum':('Q',500000),'sum_of_floor_of_linear':('T',100000),'rectangle_sum':('Q',200000),'number_of_substrings':('N',500000),'scc':('N',500000),'minimum_spanning_tree':('M',500000),'directedmst':('M',200000)}
 if id in literal:
  dim,v=literal[id]
  if d.get(dim)==v:hits.append({'parameter':'literal','dimension':dim,'value':v})
 return hits

def additional_pressure(item):
 from pressure_cases import pressure
 return pressure(item['id'],item['native_params'])

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--ids',nargs='*');ap.add_argument('--skip-l3',action='store_true');ap.add_argument('--resume',action='store_true');args=ap.parse_args()
 items=json.loads((R/'library_work/native_strict_plan.json').read_text());box=Sandbox();assert box.available,box.probe
 resource.setrlimit(resource.RLIMIT_STACK,(256*1024**2,256*1024**2));common=R/'sources/library-checker-problems-master/common';mods={};status=[]
 for item in items:
  id=item['id'];seed=item['seed_id']
  if args.ids and id not in args.ids and seed not in args.ids:continue
  report={'id':id,'seed_id':seed,'status':'started'}
  if args.resume and (R/'tasks'/seed/'raw_test_manifest.json').exists():
   report={**report,'status':'existing_manifest'};status.append(report);continue
  try:
   original=R/item['package'];package=R/'library_work/prepared_packages'/id
   if not package.exists():shutil.copytree(original,package)
   (package/'params.h').write_text(''.join(f'#define {k} (long long){v}\n'for k,v in item['native_params'].items()))
   out=R/'validation/library_native_domain'/id;out.mkdir(parents=True,exist_ok=True)
   verifier=compile_cpp(box,package/'verifier.cpp',out/'build/verifier',out/'compile/verifier',[common],package)
   reference=R/'validation/library_native_examples'/id/'build/program';assert reference.exists()
   hashes=json.loads((original/'hash.json').read_text());inputs=[]
   for n in item['example_names']:inputs.append((n,(original/'gen'/(n+'.in')).read_bytes(),{'kind':'original_sample','official_name':n}))
   for g in item['selected_upstream_generators']:
    stem=Path(g['generator']).stem;name=stem+f'_{g["seed"]:02d}'
    binary=compile_cpp(box,package/'gen'/g['generator'],out/'build'/('gen_'+stem),out/'compile'/('gen_'+stem),[common],package)
    result=run(box,binary,b'',out/'generate'/name,90,[g['seed']]);assert result['status']=='OK',('generator',name,result['status'])
    inp=Path(result['stdout_path']).read_bytes();assert hashlib.sha256(inp).hexdigest()==hashes[name+'.in'],('generator_hash',name)
    inputs.append((name,inp,{'kind':g['role'],'official_name':name,'generator':str((original/'gen'/g['generator']).relative_to(R)),'generator_sha256':file_hash(original/'gen'/g['generator']),'seed':g['seed'],'generator_input_sha256_matches_official':True}))
   mf=item['recipe_module']
   if mf not in mods:mods[mf]=load(R/mf)
   mod=mods[mf];cfg=mod.RECIPES[id].copy();cfg['memory_mb']=1024;cfg['max_output_bytes']=256*1024**2;cfg.update(json.loads((R/'library_work/program_overrides.json').read_text()).get(id,{}))
   for mode in ('boundary','small'):
    for ix,(name,text)in enumerate(mod.cases(id,mode,random.Random(20261022))):
     if mode=='small'and ix>=8:break
     inputs.append((f'authored_{mode}_{ix:02d}',text.encode(),{'kind':'authored_'+mode,'generator_recipe':mf,'generator_recipe_sha256':file_hash(R/mf),'seed':20261022,'not_an_original_official_test':True}))
   pressure=additional_pressure(item)
   if pressure:inputs.append(('authored_native_pressure',pressure.encode(),{'kind':'authored_native_pressure','generator':str(Path(__file__).relative_to(R)),'seed':20261022,'not_an_original_official_test':True}))
   testdir=R/'tasks'/seed/'tests/raw';testdir.mkdir(parents=True,exist_ok=True);records=[];rejected=[]
   progs=None
   if not args.skip_l3:
    progs=Programs(box,(R/mf).parent,out/'l3_programs',cfg)
    for role in ('l3_fast','l3_oracle','raw_oracle'):progs.prepare(role)
   for name,inp,meta in inputs:
    ver=run(box,verifier,inp,out/'verify'/name,10)
    if ver['status']!='OK':
     if meta['kind'].startswith('authored_'):rejected.append({'name':name,'reason':'source_verifier_rejected','report':str((out/'verify'/(name+'.run.json')).relative_to(R))});continue
     raise AssertionError(('official_verifier',name,ver['status']))
    raw=run(box,reference,inp,out/'raw_reference'/name,item['native_time_seconds']);assert raw['status']=='OK',('reference',name,raw['status'])
    expected=Path(raw['stdout_path']).read_bytes();official=meta.get('official_name')
    if official:assert hashlib.sha256(expected).hexdigest()==hashes[official+'.out'],('reference_official_output_hash',name)
    (testdir/(name+'.in')).write_bytes(inp);(testdir/(name+'.out')).write_bytes(expected)
    dims=dimensions(id,inp);rec={'name':name,**meta,'input_path':str((testdir/(name+'.in')).relative_to(R)),'input_sha256':hashlib.sha256(inp).hexdigest(),'expected_path':str((testdir/(name+'.out')).relative_to(R)),'expected_sha256':hashlib.sha256(expected).hexdigest(),'dimensions':dims,'native_upper_bound_hits':bound_hits(item,dims),'source_verifier':'passed','reference_run':str((out/'raw_reference'/(name+'.run.json')).relative_to(R)),'reference_cpu_seconds':raw['cpu_seconds']}
    if official:rec['official_expected_sha256_matches']=True
    if progs:
     text=inp.decode();fast=progs.run('l3_fast',text,item['native_time_seconds'],out/'l3_fast'/name);rec['l3_native_run']={'status':fast['status'],'cpu_seconds':fast['cpu_seconds'],'report':str((out/'l3_fast'/(name+'.run.json')).relative_to(R))}
     small=meta['kind']in ('original_sample','authored_boundary','authored_small')
     if small and id=='sum_of_floor_of_linear':
      terms=sum(int(v)for v in inp.split()[1::4])
      if terms>1000000:
       small=False;rec['independent_oracle_scope']={'classification':'outside_small_oracle_domain','sum_N':terms,'maximum_direct_scan_terms':1000000,'reason':'The independent oracle enumerates every i in every test case. An original sample can contain a native-scale N and is not automatically a small case.'}
     if small and fast['status']=='OK':
      oracle=progs.run('l3_oracle',text,30,out/'l3_oracle'/name)
      ro=progs.run('raw_oracle',text,30,out/'raw_oracle'/name)
      rec['small_independent_oracles']={'l3_status':oracle['status'],'raw_status':ro['status']}
      if oracle['status']=='OK':
       good=accepted(mod,id,text,Path(fast['stdout_path']).read_text(),Path(oracle['stdout_path']).read_text(),'l3');rec['small_independent_oracles']['l3_agrees']=good
       rec['small_independent_oracles']['raw_answer_rejected_by_l3']=not accepted(mod,id,text,expected.decode(),Path(oracle['stdout_path']).read_text(),'l3')
      if ro['status']=='OK':rec['small_independent_oracles']['source_raw_agrees']=accepted(mod,id,text,expected.decode(),Path(ro['stdout_path']).read_text(),'raw')
    records.append(rec)
   manifest={'schema_version':'library-native-tests-v1','seed_id':seed,'source_id':id,'test_scope':'selected reproducible native-domain experimental subset; not complete official hidden test suite','raw_l1_policy':'Raw and L1 must reference this exact same immutable manifest and all input/expected bytes','contains_all_original_samples':sum(r['kind']=='original_sample'for r in records)==len(item['example_names']),'native_upper_bound_reached':any(r['native_upper_bound_hits']for r in records),'source_verifier_path':str((original/'verifier.cpp').relative_to(R)),'source_verifier_sha256':file_hash(original/'verifier.cpp'),'native_params':item['native_params'],'records':records,'rejected_authored_cases':rejected,'test_count':len(records),'experimental_memory_mb':1024,'memory_is_original_source_claim':False}
   write_json(R/'tasks'/seed/'raw_test_manifest.json',manifest)
   report={**report,'status':'frozen','tests':len(records),'native_upper_bound_reached':manifest['native_upper_bound_reached'],'l3_run_failures':[r['name']for r in records if r.get('l3_native_run',{}).get('status','OK')!='OK'],'oracle_disagreements':[r['name']for r in records if any(r.get('small_independent_oracles',{}).get(k) is False for k in ('l3_agrees','source_raw_agrees'))],'l3_witness_count':sum(r.get('small_independent_oracles',{}).get('raw_answer_rejected_by_l3',False)for r in records),'rejected_authored_cases':len(rejected)}
  except Exception as e:report={**report,'status':'blocked','error':repr(e)}
  status.append(report);print(json.dumps(report),flush=True);write_json(R/'library_work/native_tests_status.json',status)
if __name__=='__main__':main()
