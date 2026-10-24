from pathlib import Path
import json,sys,hashlib
B=Path(__file__).resolve().parents[1];sys.path.insert(0,str(B/'recipes'));import replacements as m
index=json.loads((B/'replacements/index.json').read_text());rows=[]
for rec in index['records']:
 rid=rec['recipe_id'];paths=list((B/rec['validation_directory']).glob(rid+'-*/report.json'));assert len(paths)==1
 p=paths[0];rep=json.loads(p.read_text());assert rep['qualified'];public=[]
 for n,(inp,expected)in enumerate(m.source_samples(rid),1):
  found=[]
  for cases in rep['cases'].values():
   for c in cases:
    if Path(c['input_path']).read_text().split()==inp.split() and 'raw_fast'in c.get('runs',{}):found.append(c)
  assert found,(rid,n)
  c=found[0];run=c['runs']['raw_fast'];actual=Path(run['stdout_path']).read_text();assert run['status']=='OK'and m.check_output(rid,inp,actual,expected,'raw')
  public.append({'sample':n,'case_input_path':str(Path(c['input_path']).relative_to(B)),'actual_output_path':str(Path(run['stdout_path']).relative_to(B)),'official_expected':expected,'match':True})
 strong=[]
 for c in rep['cases']['stress']:
  inp=Path(c['input_path']).read_text();assert m.validate_input(rid,inp,'l2');assert not m.validate_input(rid,inp,'raw');strong.append({'input_path':str(Path(c['input_path']).relative_to(B)),'valid_l2':True,'invalid_raw_because_expanded_upper_bound':True})
 rec.update(status='finite_validation_passed',validation_report=str(p.relative_to(B)),public_samples_executed_match=True,strict_scale_witnesses=strong,l1_certificate=f"tasks/{rec['seed_id']}/l1_certificate.json")
 rows.append({'seed_id':rec['seed_id'],'recipe_id':rid,'public_samples':public,'strict_l2_witnesses':strong,'qualified':rep['qualified'],'l3_witness_count':len(rep['l3_witnesses'])})
index['validation_scope']='Finite public/sample/random/boundary/scale differential tests; no proof over all possible inputs or guarantee of model performance.'
(B/'replacements/index.json').write_text(json.dumps(index,ensure_ascii=False,indent=2)+'\n')
(B/'replacements/execution_audit.json').write_text(json.dumps({'records':rows,'first_cpu0_attempt_retained':'validation/replacements','clean_isolated_cpu':2},ensure_ascii=False,indent=2)+'\n')
print('audited',len(rows))
