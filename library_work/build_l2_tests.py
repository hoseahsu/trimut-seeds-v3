#!/usr/bin/env python3
"""Strict L2: only increase native scale bounds; independently report resource separation as unestablished."""
from pathlib import Path
import argparse,hashlib,json,random,re,resource,shutil,sys,tomllib
R=Path(__file__).resolve().parents[1];sys.path.insert(0,str(R/'tools'));sys.path.insert(0,str(R/'library_work'))
from validate import Sandbox,Programs,write_json,file_hash,accepted
from build_native_tests import compile_cpp,run,load,dimensions
from build_native_raw import english_template,KEYWORDS
from render_variants import split_constraints

def expanded_params(x):
 p=x['native_params'].copy()
 for key,v in x['l2_proposed_changes'].items():
  if key!='literal_upper_bound':p[key]=v['expanded']
 return p

def render_l2(x):
 raw=(R/'tasks'/x['seed_id']/'raw.txt').read_text();a,c,b=split_constraints(raw)
 src=english_template((R/x['package']/'task.md').read_text());src=re.sub(r'@\{keyword\.([^}]+)\}',lambda m:KEYWORDS[m[1]],src)
 origc=split_constraints(src)[1];newc=re.sub(r'@\{param\.([^}]+)\}',lambda m:str(expanded_params(x)[m[1]]),origc)
 # Original hard-coded scale literals remain exact except the specified upper bounds.
 for key,v in x['l2_proposed_changes'].items():
  if key=='literal_upper_bound' or x['id'] in ('kth_root_integer','dynamic_tree_vertex_add_path_sum','general_weighted_matching'):
   old=str(v['native']);oldcomma=f'{v["native"]:,}';new=str(v['expanded'])
   pat=r'(?<![0-9])(?:'+re.escape(oldcomma)+'|'+re.escape(old)+r')(?![0-9])'
   newc,count=re.subn(pat,new,newc);assert count,(x['id'],'scale_literal_not_found')
 assert newc!=c,(x['id'],'unchanged_constraints')
 result=a+newc+b;dest=R/'tasks'/x['seed_id'];(dest/'l2.txt').write_text(result)
 log={'seed_id':x['seed_id'],'id':x['id'],'changes':x['l2_proposed_changes'],'raw_constraint_text':c,'l2_constraint_text':newc,'only_constraint_bytes_changed':a==split_constraints(result)[0]and b==split_constraints(result)[2],'raw_sha256':hashlib.sha256(raw.encode()).hexdigest(),'l2_sha256':hashlib.sha256(result.encode()).hexdigest(),'l2_algorithm_resource_separation':'not_established','native_parameters_immutable':x['native_params'],'expanded_parameters':expanded_params(x)}
 write_json(dest/'l2_render_provenance.json',log);return log

def exceeds(x,d):
 hits=[]
 for key,v in x['l2_proposed_changes'].items():
  if key=='literal_upper_bound':ds=v['dimension'].replace('|S|','N').split(',')
  elif key in ('N_AND_Q_MAX','MAX_N_Q'):ds=['N','Q']
  elif key=='SUM_N_MAX':ds=['SUM_N']
  elif key=='S_LEN_MAX':ds=['S_LEN']
  elif key in ('N_MAX','MAX_N'):ds=['N']+(['M']if x['id']in('minimum_spanning_tree','directedmst')else[])
  elif key in ('Q_MAX','MAX_Q'):ds=['Q']
  elif key=='M_MAX':ds=['M']
  elif key=='T_MAX':ds=['T']
  else:raise ValueError(key)
  for dm in ds:
   if d.get(dm,0)>v['native']:hits.append({'parameter':key,'dimension':dm,'native_upper_bound':v['native'],'actual':d[dm],'expanded_upper_bound':v['expanded']})
 return hits

def prepare(x):
 orig=R/x['package'];dest=R/'library_work/l2_packages'/x['id']
 if not dest.exists():shutil.copytree(orig,dest)
 (dest/'params.h').write_text(''.join(f'#define {k} (long long){v}\n'for k,v in expanded_params(x).items()))
 repairs=[]
 if 'literal_upper_bound'in x['l2_proposed_changes'] or x['id']=='kth_root_integer':
  v=x['l2_proposed_changes'].get('literal_upper_bound',x['l2_proposed_changes'].get('T_MAX'));old=f'{v["native"]:,}'.replace(',','\'');new=str(v['expanded'])
  for file in [dest/'verifier.cpp',*list((dest/'gen').glob('*.cpp'))]:
   source=(orig/file.relative_to(dest)).read_text();changed=re.sub(r'(?<![\d\'])'+re.escape(old)+r'(?![\d\'])',new,source)
   if changed!=source:file.write_text(changed);repairs.append({'path':str(file.relative_to(R)),'replace':old,'with':new,'reason':'specified size upper bound only'})
 # A few upstream generators/verifiers hard-code the same size literal instead of using params.h.
 explicit={
  'vertex_add_path_sum':[('gen/max_random.cpp',"500'000",'1000000')],
  'majority_voting':[('gen/max_random.cpp',"int Q = 500'000;",'int Q = 1000000;')],
  'zalgorithm':[('verifier.cpp',"n <= 500'000",'n <= 1000000')],
  'general_weighted_matching':[('gen/max_random.cpp','int n = 500;','int n = 1000;')],
 }
 for rel,old,new in explicit.get(x['id'],[]):
  f=dest/rel;source=(orig/rel).read_text();assert old in source;(dest/rel).write_text(source.replace(old,new));repairs.append({'path':str(f.relative_to(R)),'replace':old,'with':new,'reason':'original hard-coded size equivalent to expanded parameter; non-size values unchanged'})
 if x['id'] in ('dynamic_tree_vertex_add_path_sum','dynamic_tree_vertex_set_path_composite'):
  f=dest/'gen/toptree.hpp';source=(orig/'gen/toptree.hpp').read_text();assert source.count('ns[1010101]')==2;f.write_text(source.replace('ns[1010101]','ns[2020202]'));repairs.append({'path':str(f.relative_to(R)),'replace':'ns[1010101]','with':'ns[2020202]','reason':'double the generator node-pool capacity to match the doubled N,Q limit; topology and random-generation algorithm unchanged'})
 if x['id']=='dynamic_tree_vertex_add_path_sum':
  f=dest/'sol/correct.cpp';source=(orig/'sol/correct.cpp').read_text();assert source.count('ns[2020202]')==2;f.write_text(source.replace('ns[2020202]','ns[4040404]'));repairs.append({'path':str(f.relative_to(R)),'replace':'ns[2020202]','with':'ns[4040404]','reason':'double the source-reference node-pool capacity to match the doubled N,Q limit; no algorithm change'})
 if x['id']=='dynamic_sequence_range_affine_range_sum':
  f=dest/'sol/correct.cpp';source=(orig/'sol/correct.cpp').read_text();assert source.count('new Node[1000001]')==1;f.write_text(source.replace('new Node[1000001]','new Node[2000001]'));repairs.append({'path':str(f.relative_to(R)),'replace':'new Node[1000001]','with':'new Node[2000001]','reason':'increase the reference AVL pool to N_max+Q_max+1 for the expanded domain; no algorithm change'})
 if x['id']=='maximum_independent_set':
  f=dest/'sol/correct.cpp';source=(orig/'sol/correct.cpp').read_text();new=source.replace('MaxClique<40, E>','MaxClique<42, E>');assert new!=source;f.write_text(new);repairs.append({'path':str(f.relative_to(R)),'reason':'increase fixed clique bitset capacity40 to42 only; no algorithm change'})
 if x['id']=='wildcard_pattern_matching':
  f=dest/'sol/correct.cpp';source=(orig/'sol/correct.cpp').read_text();new=source.replace('static char buf[(1 << 19) + 1]','static char buf[(1 << 20) + 1]');assert new!=source;f.write_text(new);repairs.append({'path':str(f.relative_to(R)),'reason':'increase fixed input buffer from2^19+1 to2^20+1 only; convolution algorithm unchanged'})
 if x['id']=='subset_convolution':
  f=dest/'sol/correct.cpp';source=(orig/'sol/correct.cpp').read_text();new=source.replace('array<Mint, 21>','array<Mint, 22>').replace('assert(n <= 20)','assert(n <= 21)');assert new!=source;f.write_text(new);repairs.append({'path':str(f.relative_to(R)),'reason':'increase rank-vector capacity21 to22 and input assertion20 to21 only; no algorithm change'})
 if x['id']=='chromatic_number':
  f=dest/'sol/correct.cpp';source=(orig/'sol/correct.cpp').read_text();new=source.replace('es[20],dp[1<<20]','es[21],dp[1<<21]');assert new!=source;f.write_text(new);repairs.append({'path':str(f.relative_to(R)),'reason':'increase fixed array capacity to21 only; no algorithm change'})
 write_json(dest/'strict_edit_log.json',repairs);return dest

def special_input(x,trial):
 from pressure_cases import pressure
 return pressure(x['id'],expanded_params(x),x['l2_proposed_changes'].get('literal_upper_bound',{}).get('expanded'),trial)

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--ids',nargs='*');ap.add_argument('--resume',action='store_true');ap.add_argument('--render-only',action='store_true');args=ap.parse_args()
 items=json.loads((R/'library_work/native_strict_plan.json').read_text());box=None if args.render_only else Sandbox();assert args.render_only or box.available,box.probe
 resource.setrlimit(resource.RLIMIT_STACK,(256*1024**2,256*1024**2));common=R/'sources/library-checker-problems-master/common';mods={};status=[]
 for x in items:
  id=x['id'];seed=x['seed_id']
  if args.ids and id not in args.ids and seed not in args.ids:continue
  report={'id':id,'seed_id':seed}
  try:
   renderlog=render_l2(x)
   if args.render_only:report['status']='rendered';status.append(report);continue
   if args.resume and(R/'tasks'/seed/'l2_test_manifest.json').exists():report['status']='existing_manifest';status.append(report);continue
   package=prepare(x);out=R/'validation/library_l2_expanded'/id;out.mkdir(parents=True,exist_ok=True)
   verifier=compile_cpp(box,package/'verifier.cpp',out/'build/verifier',out/'compile/verifier',[common],package)
   reference=compile_cpp(box,package/'sol/correct.cpp',out/'build/source_reference',out/'compile/source_reference',[common],package)
   mf=x['recipe_module']
   if mf not in mods:mods[mf]=load(R/mf)
   mod=mods[mf];cfg=mod.RECIPES[id].copy();cfg['memory_mb']=1024;cfg['max_output_bytes']=256*1024**2;cfg.update(json.loads((R/'library_work/program_overrides.json').read_text()).get(id,{}))
   progs=Programs(box,(R/mf).parent,out/'candidate_program',cfg);progs.prepare('raw_fast')
   g=next(g for g in x['selected_upstream_generators']if g['role']=='native_scale_candidate')
   custom=special_input(x,0);gen=None
   if custom is None:gen=compile_cpp(box,package/'gen'/g['generator'],out/'build/generator',out/'compile/generator',[common],package)
   records=[]
   for trial in range(2):
    name=f'expanded_{trial:02d}'
    if custom is not None:inp=special_input(x,trial).encode();origin={'kind':'authored_expanded_pressure','seed':20261022+trial,'generator_program':str(Path(__file__).relative_to(R))}
    else:
     gs=g['seed']+trial;res=run(box,gen,b'',out/'generate'/name,90,[gs]);assert res['status']=='OK',('generator',res['status']);inp=Path(res['stdout_path']).read_bytes();origin={'kind':'upstream_generator_with_only_expanded_size_constants','generator':str((package/'gen'/g['generator']).relative_to(R)),'generator_sha256':file_hash(package/'gen'/g['generator']),'seed':gs,'not_an_original_official_test':True}
    dim=dimensions(id,inp);hits=exceeds(x,dim);assert hits,(id,'case_does_not_exceed_native',dim)
    ver=run(box,verifier,inp,out/'verify'/name,20);assert ver['status']=='OK',('expanded_verifier',name,ver['status'])
    ref=run(box,reference,inp,out/'source_reference'/name,max(60,12*x['native_time_seconds']));assert ref['status']=='OK',('reference_expected_generation',name,ref['status'])
    expected=Path(ref['stdout_path']).read_text();fast=progs.run('raw_fast',inp.decode(),x['native_time_seconds'],out/'fast'/name)
    good=fast['status']=='OK'and accepted(mod,id,inp.decode(),Path(fast['stdout_path']).read_text(),expected,'raw')
    td=R/'tasks'/seed/'tests/l2';td.mkdir(parents=True,exist_ok=True);(td/(name+'.in')).write_bytes(inp);(td/(name+'.out')).write_text(expected)
    records.append({'name':name,**origin,'dimensions':dim,'strictly_exceeds_native':hits,'expanded_verifier_passed':True,'input_path':str((td/(name+'.in')).relative_to(R)),'input_sha256':file_hash(td/(name+'.in')),'expected_path':str((td/(name+'.out')).relative_to(R)),'expected_sha256':file_hash(td/(name+'.out')),'source_reference_run':str((out/'source_reference'/(name+'.run.json')).relative_to(R)),'source_reference_cpu_seconds':ref['cpu_seconds'],'fast_status':fast['status'],'fast_cpu_seconds':fast['cpu_seconds'],'fast_answer_agrees_with_source_reference':good,'fast_run':str((out/'fast'/(name+'.run.json')).relative_to(R))})
   manifest={'schema_version':'library-l2-expanded-v1','id':id,'seed_id':seed,'changes':x['l2_proposed_changes'],'scale_expansion_valid':all(r['strictly_exceeds_native']and r['expanded_verifier_passed']for r in records),'fast_reference_validated':all(r['fast_answer_agrees_with_source_reference']for r in records),'algorithm_resource_separation_validated':False,'algorithm_resource_separation_reason':'No natural baseline has yet been shown to pass native upper bounds and fail only in this expanded domain. Old weak-domain comparisons are inapplicable.','cpu_budget_seconds':x['native_time_seconds'],'experimental_memory_mb':1024,'memory_is_original_source_claim':False,'records':records,'source_code_edits':json.loads((package/'strict_edit_log.json').read_text())}
   write_json(R/'tasks'/seed/'l2_test_manifest.json',manifest);report.update({'status':'validated'if manifest['fast_reference_validated']else 'needs_fast_repair','scale_expansion_valid':manifest['scale_expansion_valid'],'fast_reference_validated':manifest['fast_reference_validated'],'fast_statuses':[r['fast_status']for r in records]})
  except Exception as e:report.update({'status':'blocked','error':repr(e)})
  status.append(report);print(json.dumps(report),flush=True);write_json(R/'library_work/l2_tests_status.json',status)
 write_json(R/'library_work/l2_tests_status.json',status)
if __name__=='__main__':main()
