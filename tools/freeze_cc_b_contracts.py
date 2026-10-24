#!/usr/bin/env python3
"""Freeze 82 retained full-original CodeContests tasks from executed evidence."""
import json,sys,shutil
from pathlib import Path
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'native')]
import validate,cc_b83,cc_b_samples,cc_b_extensions
def sha(p):return validate.file_hash(Path(p))
def portable(p):
 p=Path(p);return str(p.relative_to(B))if p.is_absolute()else str(p)
def ref(p):
 p=Path(p);p=p if p.is_absolute()else B/p
 return {'path':portable(p),'sha256':sha(p)}
def program(m):
 p=Path(m['source_path']);assert sha(p)==m['source_sha256']
 deps={portable(Path(p)):h for p,h in m.get('header_sha256',{}).items()}
 assert all(sha(B/p)==h for p,h in deps.items())
 return {'path':portable(p),'sha256':sha(p),'args':m.get('args',[]),'include_dirs':[portable(Path(x))for x in m.get('include_dirs',[])],'dependency_sha256':deps,'compiler_options':['-std=c++17','-O2','-pipe']if p.suffix=='.cpp'else[]}
def main():
 summary=[]
 for seed in map(json.loads,(B/'curation/previous_seed_index.jsonl').read_text().splitlines()):
  sid=seed['seed_id'];k=int(sid[2:])
  if not 138<=k<=220 or k==149:continue
  folder=B/'tasks'/sid;rp=B/f'validation/strict_cc_b/{sid}/report.json';sp=B/f'validation/strict_cc_b_supplement/{sid}/report.json';r=json.loads(rp.read_text());s=json.loads(sp.read_text());assert r['status']==s['status']=='complete'and s['finite_checks_passed'],sid
  module=validate.load_recipe(B/seed['recipe_module']);rid=seed['recipe_id'];frozen={'raw':[],'l3':[],'l2':[]};seen={x:set()for x in frozen};excluded=[]
  def add(c,target,expected,provenance,independent,kind,witness=False):
   inp=B/c['input_path'];v=cc_b83.validate(k,inp.read_text(),'l2'if target=='l2'else'raw');assert v['valid'],(sid,c['name'],v)
   h=sha(inp)
   if h in seen[target]:return
   seen[target].add(h);role='l3_fast'if target=='l3'else'raw_fast';run=c['runs'][role];assert run['status']=='OK'
   assert validate.accepted(module,rid,inp.read_text(),validate.output(run),expected.read_text(),'l3'if target=='l3'else'raw'),(sid,c['name'],target)
   name=c['name'];inf=folder/'tests'/('l2'if target=='l2'else'raw')/(name+'.in');outf=folder/'tests'/target/(name+'.out');inf.parent.mkdir(parents=True,exist_ok=True);outf.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(inp,inf);shutil.copyfile(expected,outf)
   frozen[target].append({'name':name,'kind':kind,'input_path':portable(inf),'input_sha256':h,'expected_path':portable(outf),'expected_sha256':sha(outf),'expected_provenance':provenance,'independent_expected':independent,'validity':v,'reference_run_status':run['status'],'reference_cpu_seconds':run['cpu_seconds'],'cpu_budget_seconds':5,'memory_mb':2048,'distinguishing_witness':witness})
  # Samples are first, so duplicate hidden inputs cannot displace a sample.
  for c in s['cases']:
   if c['name'].startswith('original_statement_sample_'):
    assert c['raw_expected_matched'];add(c,'raw',B/c['expected_path'],'complete_original_statement_sample',True,'original_sample');add(c,'l3',Path(c['runs']['l3_fast']['stdout_path']),'L3_reference_on_original_sample_input',False,'original_sample')
   elif c['name']=='certified_l2_upper':
    inp,ex,proof=cc_b_extensions.certificate(k);assert validate.sha(inp.encode())==c['input_sha256']and validate.sha(ex.encode())==c['expected_sha256']and c['raw_expected_matched'];add(c,'l2',B/c['expected_path'],'independently_derived_structured_expanded_certificate: '+proof,True,'expanded_upper_boundary')
   elif c['name']=='certified_native_upper':
    assert c['raw_expected_matched']and c['l3_expected_matched'];add(c,'raw',B/c['expected_path'],'independently_derived_structured_native_certificate: '+c['expected_derivation'],True,'native_upper_boundary');add(c,'l3',B/c['l3_expected_path'],'independently_derived_structured_native_mutant_certificate: '+c['l3_expected_derivation'],True,'native_upper_boundary')
   elif c['name']=='native_upper_recheck':
    assert c['raw_expected_matched'];add(c,'raw',B/c['expected_path'],'independent_corrected_source_reference; correction ledger retained',True,'native_upper_random');add(c,'l3',Path(c['runs']['l3_fast']['stdout_path']),'L3_reference_validated_by_independent_small_and_structured_native_cases',False,'native_upper_random')
  valid_witnesses=set(s['independently_checked_valid_witnesses'])
  for c in r['cases']:
   inp=B/c['input_path'];v=cc_b83.validate(k,inp.read_text(),c['condition'])
   if not v['valid']:excluded.append({'name':c['name'],'input_sha256':sha(inp),'reason':'current_native_domain_rejected','validation':v});continue
   if c['condition']=='l2':
    excluded.append({'name':c['name'],'input_sha256':sha(inp),'reason':'replaced_by_independent_expanded_certificate; source submission is not an oracle outside its declared domain'});continue
   if c['kind']=='small':
    assert c['raw_oracle_matched']and c['l3_oracle_matched'];add(c,'raw',Path(c['runs']['raw_oracle']['stdout_path']),'independent_small_oracle',True,'independent_small');add(c,'l3',Path(c['runs']['l3_oracle']['stdout_path']),'independent_small_oracle',True,'independent_small',c['name']in valid_witnesses)
   else:
    if c.get('raw_expected_matched'):add(c,'raw',B/c['raw_expected_path'],'source_test_expected_or_original_domain_source_reference',True,c['kind'])
    else:excluded.append({'name':c['name'],'input_sha256':sha(inp),'reason':'untrusted_or_unavailable_source_reference_expected; native certificate retained instead'})
    if c.get('raw_expected_matched')and c['runs'].get('l3_fast',{}).get('status')=='OK':add(c,'l3',Path(c['runs']['l3_fast']['stdout_path']),'L3_reference_validated_by_independent_small_and_structured_native_cases',False,c['kind'])
  l3_by_hash={c['input_sha256']:c for c in frozen['l3']}
  assert all(c['input_sha256']in l3_by_hash for c in frozen['raw'])
  frozen['l3']=[l3_by_hash[c['input_sha256']]for c in frozen['raw']]
  # A witness duplicated by an original example remains a witness by input hash.
  whashes={c['input_sha256']for c in r['cases']if c['name']in valid_witnesses}
  for c in frozen['l3']:
   if c['input_sha256']in whashes:c['distinguishing_witness']=True
  witness=[x['name']for x in frozen['l3']if x['distinguishing_witness']];assert witness
  assert any(x['validity']['outside_original']for x in frozen['l2'])
  frozen['l2']=frozen['raw']+frozen['l2']
  examples=cc_b_samples.extract((folder/'raw.txt').read_text());assert all(any(c['input_sha256']==validate.sha(e['input'].encode())for c in frozen['raw'])for e in examples)
  for condition,records in frozen.items():validate.write_json(folder/f'{condition}_test_manifest.json',{'schema':'trimut.frozen-tests.v1','seed_id':sid,'condition':condition,'test_scope':'selected reproducible experimental subset; not complete official hidden suite','cpu_budget_seconds':5,'memory_mb':2048,'records':records})
  shutil.copyfile(folder/'raw_test_manifest.json',folder/'l1_test_manifest.json')
  # Validate every upstream row, preserving rejected data and its exact reason.
  source=json.loads((B/seed['source']['source_tests']).read_text());ledger=[]
  for partition,batch in source.items():
   for j,inp in enumerate(batch['input']):
    v=cc_b83.validate(k,inp);h=validate.sha(inp.encode());ledger.append({'partition':partition,'index':j,'input_sha256':h,'validity':v,'included_in_raw_suite':h in seen['raw'],'exclusion_reason':None if h in seen['raw']else'invalid_native_input'if not v['valid']else'deterministic_finite_subset_not_all_hidden_tests'})
  validate.write_json(folder/'upstream_exclusion_ledger.json',{'source_tests':ref(B/seed['source']['source_tests']),'records':ledger})
  history=B/f'validation/strict_cc_b_supplement_history/{sid}_before_widening/report.json'
  resolution={'initial_main_failures':r.get('failures',[]),'first_expanded_failure_report':ref(history)if history.exists()else None,'resolution':'Complete native grammar, independently derived native and enlarged boundary certificates, full statement samples, and independent small oracles passed. Downloaded submission outputs outside their original domains are not ground truth. Three source portability/overflow repairs and two authored expanded-domain repairs are separately retained.','excluded_cases':excluded,'reference_corrections':ref(B/'cc_audit/reference_corrections.json')}
  validate.write_json(folder/'validation_resolution.json',resolution)
  l1=json.loads((folder/'l1_certificate.json').read_text());assert l1['raw_sha256']==sha(folder/'raw.txt')and l1['l1_sha256']==sha(folder/'l1.txt')and l1['exact_source_reconstruction']
  ed=json.loads((folder/'mutation_edits.json').read_text());assert ed['status']=='rendered'and ed['raw_sha256']==sha(folder/'raw.txt')
  prov=json.loads((folder/'raw_provenance.json').read_text());rawsuite=ref(folder/'raw_test_manifest.json');params=next(x for x in cc_b83.ROWS if x['seed_id']==sid)
  contract={'schema':'trimut.strict.cc_b.v1','seed_id':sid,'source_identity':seed['source_identity'],'source_url':prov.get('official_url',seed['source']['source_url']),'distinct_public_original':True,'family_split_groups':seed['family_split_groups'],
   'raw':{'statement':ref(folder/'raw.txt'),'provenance':ref(folder/'raw_provenance.json'),'tests':rawsuite,'native_upper_bound_reached':True,'unattainable_literal_cap_note':'Plus-separated single-digit sums have odd length; highest valid length under cap 100 is 99.'if k==141 else None,'all_original_examples_included':True,'native_contract':params},
   'l1':{'statement':ref(folder/'l1.txt'),'certificate':ref(folder/'l1_certificate.json'),'tests_must_equal_raw_manifest':rawsuite,'constraints_unchanged':True},
   'l2':{'statement':ref(folder/'l2.txt'),'tests':ref(folder/'l2_test_manifest.json'),'axis':cc_b83.AXES[k],'original_upper':cc_b83.CAPS[k][0],'expanded_upper':cc_b83.CAPS[k][1],'native_upper_bound_strictly_expanded':True,'all_native_inputs_remain_legal':True,'fast_program_passed_frozen_expanded_tests':True,'algorithm_resource_separation_validated':False,'separation_note':'The original upper bound is extended. No claim that every native-passing algorithm times out only after expansion.'},
   'l3':{'statement':ref(folder/'l3.txt'),'tests':ref(folder/'l3_test_manifest.json'),'operator':seed['mutation_description'],'correctness_argument':seed['proof_sketch'],'independent_small_oracle_agreement':True,'independent_small_cases':sum(c.get('l3_oracle_matched',False)and cc_b83.validate(k,(B/c['input_path']).read_text())['valid']for c in r['cases']),'independent_structured_native_upper_agreement':True,'native_domain_runs_passed':True,'distinguishing_witnesses':witness,'witness_check':'Raw output rejected by L3 semantic checker against independent oracle','native_constraints_preserved':True},
   'programs':{role:program(s['programs'][role])for role in ['raw_fast','l3_fast','raw_oracle','l3_oracle']},
   'checker':{'recipe_module':seed['recipe_module'],'recipe_id':rid},
   'validator':{'path':'native/cc_b83.py','sha256':sha(B/'native/cc_b83.py'),'function':'validate','seed_argument':k,'conditions':{'raw':'raw','l1':'raw','l2':'l2','l3':'raw'},'bounds_dependency':ref(B/'contracts/cc165_native.json')},
   'execution':{'sandbox':'bubblewrap unshare-all, no network; compilation also isolated','cpu_budget_seconds':5,'memory_mb':2048,'experimental_memory_mb':2048,'original_resource_limit_claim':False,'cpu_core':3},
   'evidence':{'finite_program_report':ref(rp),'supplement_report':ref(sp),'resolution':ref(folder/'validation_resolution.json'),'mutation_edits':ref(folder/'mutation_edits.json'),'upstream_exclusions':ref(folder/'upstream_exclusion_ledger.json'),'sample_extractor':ref(B/'native/cc_b_samples.py'),'scale_certificate_code':ref(B/'native/cc_b_extensions.py')},
   'strict_l2_l3_validation_complete':True,'universal_correctness_claim':False,'human_review_status':'not_performed','model_evaluation_status':'not_performed'}
  validate.write_json(B/'contracts/cc_b'/f'{sid}.json',contract);summary.append({'seed_id':sid,'passed':True,'test_counts':{c:len(v)for c,v in frozen.items()},'original_samples':len(examples),'valid_independent_witnesses':len(witness),'invalid_upstream':sum(not x['validity']['valid']for x in ledger)})
 validate.write_json(B/'contracts/cc_b_status.json',summary);print(json.dumps({'seeds':len(summary),'original_samples':sum(x['original_samples']for x in summary),'invalid_upstream':sum(x['invalid_upstream']for x in summary)}))
if __name__=='__main__':main()
