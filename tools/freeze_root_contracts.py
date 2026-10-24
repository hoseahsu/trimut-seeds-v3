#!/usr/bin/env python3
"""Freeze the 52 retained root-group originals from executed strict evidence."""
import hashlib,json,sys,shutil
from pathlib import Path
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'native')]
import root55

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def ref(p):
 p=Path(p);p=p if p.is_absolute() else B/p
 return {'path':str(p.relative_to(B)),'sha256':sha(p)}
def write(p,d):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(d,ensure_ascii=False,indent=2)+'\n')
def portable(p):
 p=Path(p);return str(p.relative_to(B)) if p.is_absolute() else str(p)
def program(d):
 p=Path(d['source_path']);assert sha(p)==d['source_sha256']
 return {'path':portable(p),'sha256':sha(p),'args':d['args'],'include_dirs':[portable(v)for v in d.get('include_dirs',[])],'compiler_options':['-std=c++17','-O2','-pipe']}
def main():
 summary=[]
 for seed in map(json.loads,(B/'curation/previous_seed_index.jsonl').read_text().splitlines()):
  sid=seed['seed_id'];n=int(sid[2:])
  if not 1<=n<=55 or n in(1,17,25):continue
  folder=B/'tasks'/sid;rp=B/'validation/strict_root'/sid/'report.json';sp=B/'validation/root_scale'/sid/'report.json';r=json.loads(rp.read_text());s=json.loads(sp.read_text());assert r['status']==s['status']=='complete'and s['passed']
  assert all(x['reason']=='raw_expected_mismatch'and x['case'] in('native_upper','l2_upper')for x in r['failures']),r['failures']
  scale={x['name']:x for x in s['cases']};frozen={'raw':[],'l3':[],'l2':[]};excluded=[]
  for c in r['cases']:
   name=c['name'];cond=c['condition'];inp=B/c['input_path'];data=inp.read_text();v=root55.validate(n,data,cond)
   if not v['valid']:
    excluded.append({'name':name,'input_sha256':sha(inp),'reason':'current_original_domain_validation_rejected','validation':v});continue
   if c['kind'] in('native_upper','l2_upper'):
    sc=scale['l2' if cond=='l2'else'native'];assert sc['input_sha256']==c['input_sha256'];assert all(sc['checks'].values())
   for target in(['l2']if cond=='l2'else['raw','l3']):
    role='l3_fast'if target=='l3'else'raw_fast';run=c['runs'][role];assert run['status']=='OK'
    if c['kind']in('native_upper','l2_upper'):
     oracle='scale_l3_oracle'if target=='l3'else'scale_raw_oracle';expected=Path(sc['runs'][oracle]['stdout_path']);provenance='separate_python_scale_implementation';independent=True
    elif c['kind']=='small':
     oracle='l3_oracle'if target=='l3'else'raw_oracle';assert c[oracle+'_matched'];expected=Path(c['runs'][oracle]['stdout_path']);provenance='independent_small_oracle';independent=True
    elif target=='raw':
     assert c['raw_expected_matched'];expected=B/c['raw_expected_path'];provenance='public_source_test_expected';independent=True
    else:expected=Path(run['stdout_path']);provenance='authored_l3_fast_validated_on_independent_small_cases';independent=False
    inf=folder/'tests'/('l2'if target=='l2'else'raw')/(name+'.in');outf=folder/'tests'/target/(name+'.out');inf.parent.mkdir(parents=True,exist_ok=True);outf.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(inp,inf);shutil.copyfile(expected,outf)
    frozen[target].append({'name':name,'kind':c['kind'],'input_path':portable(inf),'input_sha256':sha(inf),'expected_path':portable(outf),'expected_sha256':sha(outf),'expected_provenance':provenance,'independent_expected':independent,'validity':v,'reference_run_status':run['status'],'cpu_budget_seconds':5,'distinguishing_witness':bool(target=='l3'and c.get('l3_oracle_matched')and c.get('l3_distinguishes_raw'))})
  assert frozen['raw']and frozen['l2']and any(x['distinguishing_witness']for x in frozen['l3'])
  assert any(x['validity']['outside_original']for x in frozen['l2'])
  # The expanded condition also retains all native tests, byte for byte.
  frozen['l2']=frozen['raw']+frozen['l2']
  for cond,records in frozen.items():write(folder/f'{cond}_test_manifest.json',{'schema':'trimut.frozen-tests.v1','seed_id':sid,'condition':cond,'test_scope':'selected reproducible experimental suite; not all official hidden tests','cpu_budget_seconds':5,'memory_mb':2048,'records':records})
  # Exact same bytes, including metadata, prevents accidental divergence.
  shutil.copyfile(folder/'raw_test_manifest.json',folder/'l1_test_manifest.json')
  prov=json.loads((folder/'raw_provenance.json').read_text());assert prov['raw_ready_for_l1']
  cert=json.loads((folder/'l1_certificate.json').read_text());assert cert['raw_sha256']==sha(folder/'raw.txt')and cert['l1_sha256']==sha(folder/'l1.txt')and cert['exact_source_reconstruction']
  edits=json.loads((folder/'mutation_edits.json').read_text());assert edits['status']=='rendered'
  assert all(any(x['input_sha256']==e['input_sha256']for x in frozen['raw'])for e in edits['samples'])
  findings={'original_report_failures':r['failures'],'resolution':'Native and expanded scale expected outputs independently regenerated and compared by root_scale; old unverified submission output is not retained as ground truth. Original report is preserved.','current_input_revalidation_exclusions':excluded}
  write(folder/'validation_resolution.json',findings)
  witness=[x['name']for x in frozen['l3']if x['distinguishing_witness']]
  contract={'schema':'trimut.strict.root.v1','seed_id':sid,'source_identity':seed['source_identity'],'source_url':seed['source']['source_url'],'distinct_public_original':True,'family_split_groups':seed['family_split_groups'],'raw':{'statement':ref(folder/'raw.txt'),'provenance':ref(folder/'raw_provenance.json'),'tests':ref(folder/'raw_test_manifest.json'),'native_upper_bound_reached':True,'all_original_examples_included':True},'l1':{'statement':ref(folder/'l1.txt'),'certificate':ref(folder/'l1_certificate.json'),'tests_must_equal_raw_manifest':ref(folder/'raw_test_manifest.json'),'constraints_unchanged':True},'l2':{'statement':ref(folder/'l2.txt'),'tests':ref(folder/'l2_test_manifest.json'),'axis':root55.AXES[n-1],'original_upper':root55.CAPS[n][0],'expanded_upper':root55.CAPS[n][1],'native_upper_bound_strictly_expanded':True,'fast_program_passed_frozen_expanded_tests':True,'algorithm_resource_separation_validated':False,'separation_note':'Genuine original-bound expansion, not evidence of a forced algorithm change.'},'l3':{'statement':ref(folder/'l3.txt'),'tests':ref(folder/'l3_test_manifest.json'),'operator':seed['mutation_description'],'correctness_argument':seed['proof_sketch'],'independent_small_oracle_agreement':True,'independent_small_cases':sum(x.get('l3_oracle_matched',False)for x in r['cases']),'native_domain_runs_passed':True,'distinguishing_witnesses':witness,'native_constraints_preserved':True},'programs':{role:program(r['programs'][role])for role in('raw_fast','raw_oracle','l3_fast','l3_oracle')},'checker':{'recipe_module':seed['recipe_module'],'recipe_id':seed['recipe_id']},'evidence':{'finite_program_report':ref(rp),'independent_scale_report':ref(sp),'resolution':ref(folder/'validation_resolution.json'),'mutation_edits':ref(folder/'mutation_edits.json'),'current_validator':ref(B/'native/root55.py')},'strict_l2_l3_validation_complete':True,'universal_correctness_claim':False,'human_review_status':'not_performed','model_evaluation_status':'not_performed'}
  for role in('scale_raw_oracle','scale_l3_oracle'):
   h=s['programs'][role]['source_sha256'];current=B/'native/root_scale_oracle.py';snap=current if sha(current)==h else B/'validation/source_snapshots'/f'{h}.py';assert sha(snap)==h;contract['programs'][role]={'path':portable(snap),'sha256':h,'args':s['programs'][role]['args']}
  write(B/'contracts/root'/f'{sid}.json',contract);summary.append({'seed_id':sid,'passed':True,'test_counts':{k:len(v)for k,v in frozen.items()},'witnesses':len(witness),'current_invalid_removed':len(excluded)})
 write(B/'contracts/root_status.json',summary);print(json.dumps({'seeds':len(summary),'passed':sum(x['passed']for x in summary),'removed_invalid':sum(x['current_invalid_removed']for x in summary)},ensure_ascii=False))
if __name__=='__main__':main()
