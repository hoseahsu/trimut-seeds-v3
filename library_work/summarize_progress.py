from pathlib import Path
import json
R=Path(__file__).resolve().parents[1];rows=[]
for x in json.loads((R/'library_work/native_strict_plan.json').read_text()):
 d=R/'tasks'/x['seed_id'];r={'id':x['id'],'seed_id':x['seed_id'],'raw':(d/'raw.txt').exists(),'l2_text':(d/'l2.txt').exists(),'l3_text':(d/'l3.txt').exists()}
 p=d/'raw_test_manifest.json'
 if p.exists():
  a=json.loads(p.read_text());r.update({'native_tests':a['test_count'],'native_upper_bound_reached':a['native_upper_bound_reached'],'l3_native_failures':[q['name']for q in a['records']if q.get('l3_native_run',{}).get('status','NOT_RUN')!='OK'],'oracle_disagreements':[q['name']for q in a['records']if any(q.get('small_independent_oracles',{}).get(k)is False for k in ('l3_agrees','source_raw_agrees'))],'independent_small_case_count':sum(q.get('small_independent_oracles',{}).get('l3_agrees',False)for q in a['records']),'l3_witness_count':sum(q.get('small_independent_oracles',{}).get('raw_answer_rejected_by_l3',False)for q in a['records']),'native_small_rejected':len(a.get('rejected_authored_cases',[]))})
 p=d/'l2_test_manifest.json'
 if p.exists():
  a=json.loads(p.read_text());r.update({'l2_expansion_valid':a['scale_expansion_valid'],'l2_fast_valid':a['fast_reference_validated'],'l2_algorithm_resource_separation':a['algorithm_resource_separation_validated']})
 rows.append(r)
(R/'library_work/progress.json').write_text(json.dumps(rows,indent=2)+'\n')
print({'raw':sum(x['raw']for x in rows),'native_tests':sum('native_tests'in x for x in rows),'native_upper':sum(x.get('native_upper_bound_reached',False)for x in rows),'native_l3_failures':sum(bool(x.get('l3_native_failures'))for x in rows),'oracle_disagreements':sum(bool(x.get('oracle_disagreements'))for x in rows),'l2_expansion':sum(x.get('l2_expansion_valid',False)for x in rows),'l2_fast':sum(x.get('l2_fast_valid',False)for x in rows),'l3_text':sum(x['l3_text']for x in rows)})
print([x for x in rows if x.get('l3_native_failures')or x.get('oracle_disagreements')or('native_tests'in x and(not x['native_upper_bound_reached']or x['independent_small_case_count']<8 or not x['l3_witness_count']))or('l2_fast_valid'in x and not x['l2_fast_valid'])])
