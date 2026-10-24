#!/usr/bin/env python3
"""Read-only artifact verification, apart from the audit report itself.

This audit checks frozen evidence and bindings. It does not rerun solutions and
does not describe these finite tests as a proof over every legal input.
"""
from pathlib import Path
import hashlib,json,re,sys,tomllib
R=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(R/'library_work'));sys.path.insert(0,str(R/'tools'))
from build_native_raw import english_template,KEYWORDS
from render_variants import split_constraints
from build_native_tests import load
from validate import accepted

cache={}
def sha(path):
 p=Path(path);s=p.stat();key=(str(p),s.st_size,s.st_mtime_ns)
 if key not in cache:
  h=hashlib.sha256()
  with p.open('rb')as f:
   for part in iter(lambda:f.read(4*1024**2),b''):h.update(part)
  cache[key]=h.hexdigest()
 return cache[key]

def read(path):return json.loads(Path(path).read_text())
def require(value,reason):
 if not value:raise AssertionError(reason)
def binding(path,value):require(sha(R/path)==value,('sha256',path))

def original_text(x,prov):
 package=R/x['package'];info=tomllib.loads((package/'info.toml').read_text())
 text=english_template((package/'task.md').read_text())
 text=re.sub(r'@\{param\.([^}]+)\}',lambda m:str(info['params'][m[1]]),text)
 text=re.sub(r'@\{keyword\.([^}]+)\}',lambda m:KEYWORDS[m[1]],text)
 records={s['example']:s for s in prov['samples']};index=0
 def sample(m):
  nonlocal index
  index+=1;s=records[m[1]];inp=(R/s['input_path']).read_text();out=(R/s['output_path']).read_text()
  return f'## Sample Input {index}\n\n```\n{inp.rstrip()}\n```\n\n## Sample Output {index}\n\n```\n{out.rstrip()}\n```'
 text=re.sub(r'@\{example\.([^}]+)\}',sample,text)
 require('@{'not in text,('unresolved_source_template',x['id']))
 return '# '+info['title']+'\n\n'+text.strip()+'\n'

def main():
 plan=read(R/'library_work/native_strict_plan.json');rows=[];modules={};totals={'source_originals':len(plan),'official_samples':0,'raw_cases':0,'l2_cases':0,'l3_cases':0,'independent_small_cases':0,'distinguishing_witnesses':0};max_l2=(0,None,None);max_l3=(0,None,None)
 require(len(plan)==80 and len({x['id']for x in plan})==80 and len({x['seed_id']for x in plan})==80,'80 distinct public identities')
 for x in plan:
  row={'seed_id':x['seed_id'],'source_id':x['id']};td=R/'tasks'/x['seed_id']
  try:
   prov=read(td/'raw_provenance.json');raw=(td/'raw.txt').read_text();l2text=(td/'l2.txt').read_text();l3text=(td/'l3.txt').read_text();native=read(td/'raw_test_manifest.json');l2=read(td/'l2_test_manifest.json');l3=read(td/'l3_test_manifest.json');contract=read(R/'contracts/library'/(x['seed_id']+'.json'))
   binding(prov['raw_path'],prov['raw_sha256']);require(raw==original_text(x,prov),'Raw must be full source template expansion')
   for prefix in ('source_task','source_info','source_hash'):binding(prov[prefix+'_path'],prov[prefix+'_sha256'])
   info=tomllib.loads((R/x['package']/'info.toml').read_text());require(info.get('params',{})==prov['native_params']==native['native_params']==x['native_params'],'native parameters frozen')
   require(info['timelimit']==x['native_time_seconds'],'native CPU budget')
   official=read(R/x['package']/'hash.json');samples=[r for r in native['records']if r['kind']=='original_sample']
   require({r['name']for r in samples}==set(x['example_names']),'all original examples included')
   for r in samples:
    require(r['input_sha256']==official[r['name']+'.in']and r['expected_sha256']==official[r['name']+'.out'],'official sample input/output hashes')
   totals['official_samples']+=len(samples)
   a,c,b=split_constraints(raw);la,lc,lb=split_constraints(l2text)
   require(a==la and b==lb and c!=lc,'L2 only constraint text changes')
   require(c==split_constraints(l3text)[1],'L3 keeps original Constraints bytes')
   for variant in ('l2','l3'):
    p=read(td/(variant+'_render_provenance.json'));require(p['raw_sha256']==sha(td/'raw.txt')and p[variant+'_sha256']==sha(td/(variant+'.txt')),'variant text provenance hashes')
   require(native['contains_all_original_samples']and native['native_upper_bound_reached'],'native coverage requirements')
   require(any(r['native_upper_bound_hits']for r in native['records']),'actual exact native upper-bound input')
   require(l2['scale_expansion_valid']and l2['fast_reference_validated']and not l2['algorithm_resource_separation_validated'],'separate scale validity from algorithm separation')
   require(all(v['expanded']>v['native']for v in l2['changes'].values()),'strict native bound increase')
   for label,manifest in [('raw',native),('l2',l2),('l3',l3)]:
    totals[label+'_cases']+=len(manifest['records'])
    require(len({q['name']for q in manifest['records']})==len(manifest['records']),'unique case names')
    for q in manifest['records']:
     binding(q['input_path'],q['input_sha256']);binding(q['expected_path'],q['expected_sha256'])
   require({(q['input_path'],q['input_sha256'])for q in native['records']}=={(q['input_path'],q['input_sha256'])for q in l3['records']},'L3 uses same native-domain input manifest')
   for q in l2['records']:
    require(q['strictly_exceeds_native']and q['expanded_verifier_passed']and q['fast_answer_agrees_with_source_reference'],'expanded input verified and fast answer accepted')
    for hit in q['strictly_exceeds_native']:require(hit['native_upper_bound']<hit['actual']<=hit['expanded_upper_bound'],'actual input between original and expanded upper bounds')
    rr=read(R/q['fast_run']);require(rr['status']=='OK','L2 fast run status');ratio=rr['cpu_seconds']/x['native_time_seconds'];max_l2=max(max_l2,(ratio,x['seed_id'],q['name']))
    require(rr['cpu_seconds']<=x['native_time_seconds'],'L2 fast within native CPU budget')
   for q in native['records']:
    rr=read(R/q['l3_native_run']['report']);require(q['l3_native_run']['status']=='OK'and rr['status']=='OK','L3 native run status');ratio=rr['cpu_seconds']/x['native_time_seconds'];max_l3=max(max_l3,(ratio,x['seed_id'],q['name']))
    require(rr['cpu_seconds']<=x['native_time_seconds'],'L3 within native CPU budget')
   outside=[q for q in native['records']if (q.get('independent_oracle_scope')or{}).get('classification')=='outside_small_oracle_domain']
   for q in outside:
    require(x['id']=='sum_of_floor_of_linear','only documented large original sample exclusion')
    require(sum(map(int,(R/q['input_path']).read_text().split()[1::4]))>1000000,'excluded sample really exceeds direct-scan small-case scope')
    require(q['small_independent_oracles']['l3_status']=='RE'and q['small_independent_oracles']['raw_status']=='RE','original failed oracle attempts retained')
   sm=[q for q in native['records']if q.get('small_independent_oracles')and q not in outside];require(len(sm)>=8,'at least eight independent small cases')
   require(all(q['small_independent_oracles']['l3_agrees']and q['small_independent_oracles']['source_raw_agrees']for q in sm),'independent small oracle agreement')
   witness=[q for q in sm if q['small_independent_oracles']['raw_answer_rejected_by_l3']];require(witness,'at least one distinguishing witness')
   cp=contract['output_checker']['module_path'];require('release_repairs'not in cp and 'root_repair'not in cp,'base checker only')
   if cp not in modules:modules[cp]=load(R/cp)
   l3by={q['name']:q for q in l3['records']}
   for q in witness:
    text=(R/q['input_path']).read_text();old=(R/q['expected_path']).read_text();new=(R/l3by[q['name']]['expected_path']).read_text()
    require(not accepted(modules[cp],x['id'],text,old,new,'l3'),'stored Raw answer must be rejected by L3 checker')
   totals['independent_small_cases']+=len(sm);totals['distinguishing_witnesses']+=len(witness)
   require(contract['strict_l2_l3_validation_complete'],'strict per-task contract complete')
   for label in ('raw','l1','l2','l3'):
    stm=contract[label]['statement']
    if stm:binding(stm['path'],stm['sha256'])
   for label in ('raw','l2','l3'):
    m=contract[label]['tests'];binding(m['path'],m['sha256'])
   require(contract['l1']['tests_must_equal_raw_manifest']==contract['raw']['tests'],'L1 must use exact frozen Raw manifest')
   for key,prog in contract['programs'].items():
    if 'source_sha256'in prog:binding(prog['path'],prog['source_sha256'])
    if 'params_sha256'in prog:binding(prog['params_path'],prog['params_sha256'])
    if prog.get('source_edit_log'):binding(prog['source_edit_log']['path'],prog['source_edit_log']['sha256'])
    for path,value in prog.get('local_cpp_header_snapshot_sha256',{}).items():binding(path,value)
   row.update({'status':'passed','official_samples':len(samples),'raw_cases':len(native['records']),'l2_cases':len(l2['records']),'independent_small_cases':len(sm),'distinguishing_witnesses':len(witness),'original_sample_oracle_attempts_outside_small_domain':[q['name']for q in outside],'raw_sha256':sha(td/'raw.txt'),'l2_sha256':sha(td/'l2.txt'),'l3_sha256':sha(td/'l3.txt'),'contract_sha256':sha(R/'contracts/library'/(x['seed_id']+'.json'))})
  except Exception as e:row.update({'status':'failed','error':repr(e)})
  rows.append(row)
 report={'schema':'trimut.strict.library.integrity.v1','reviewer':'library_l3_audit','blind':False,'review_type':'automated artifact integrity and evidence-binding review; no new solution runs','totals':totals,'passed':sum(q['status']=='passed'for q in rows),'max_l2_cpu_fraction':{'fraction':max_l2[0],'seed_id':max_l2[1],'case':max_l2[2]},'max_l3_cpu_fraction':{'fraction':max_l3[0],'seed_id':max_l3[1],'case':max_l3[2]},'limitations':['Frozen native tests are a selected reproducible experimental subset, not the full official hidden suite.','Finite small-oracle and native-scale runs do not prove correctness for every legal input.','Large L3 expected outputs are produced by the optimized L3 program; independently constructed oracles cover small cases.','L2 scale validity and fast-program acceptance are established on frozen inputs; algorithm resource separation is not established.','Experimental 1024 MiB memory is not asserted to be an original source memory limit.'],'entries':rows}
 (R/'library_work/final_integrity_report.json').write_text(json.dumps(report,indent=2,ensure_ascii=False)+'\n')
 print(json.dumps({k:v for k,v in report.items()if k not in('entries','limitations')},ensure_ascii=False));print(json.dumps([r for r in rows if r['status']!='passed'],ensure_ascii=False))
 return 0 if report['passed']==80 else 1
if __name__=='__main__':raise SystemExit(main())
