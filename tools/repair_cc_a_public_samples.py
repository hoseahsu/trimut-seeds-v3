from pathlib import Path
import json,sys,re
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'native'),str(B/'recipes')]
import validate,cc_a82,cc_b_samples
sandbox=validate.Sandbox();rows=[]
if len(sys.argv)>1:
 old=B/'native/cc_a_public_sample_repairs.json'
 if old.exists():rows=[x for x in json.loads(old.read_text())['records']if x['seed_id']!=sys.argv[1]]
for seed in map(json.loads,(B/'curation/previous_seed_index.jsonl').read_text().splitlines()):
 k=int(seed['seed_id'][2:])
 if not 56<=k<=137 or k==70 or(len(sys.argv)>1 and seed['seed_id']!=sys.argv[1]):continue
 out=B/'validation/strict_cc_a'/seed['seed_id'];rp=out/'report.json';rep=json.loads(rp.read_text());source=json.loads((B/seed['source']['source_tests']).read_text());bad=[x for x in rep['upstream_ledger']if x['name'].startswith('public')and not x['valid']]
 if not bad:continue
 path=B/seed['recipe_module'];m=validate.load_recipe(path);cfg={**m.RECIPES[seed['recipe_id']],'memory_mb':2048};p=validate.Programs(sandbox,path.parent,out,cfg);raw=(B/'tasks'/seed['seed_id']/'raw.txt').read_text();rec=[]
 for role in ['raw_fast','l3_fast','raw_oracle','l3_oracle']:p.prepare(role)
 for x in bad:
  idx=int(x['name'].split('_')[-1]);orig=source['public_tests']['input'][idx];expected=source['public_tests']['output'][idx];inp=re.sub(r'\s+SAMPLE\s*$','\n',orig);assert inp!=orig or k==101
  if k==101:
   original=cc_b_samples.extract(raw)[idx];inp=original['input'];expected=original['output']
  # Confirm the recovered input is literally present in full original Raw ignoring whitespace.
  assert ''.join(inp.split())in''.join(raw.split()),(k,'not original sample')
  v=cc_a82.validate(k,inp);assert v['valid']or k==101
  name='original_sample_recovered_'+str(idx);folder=out/'cases'/name;folder.mkdir(parents=True,exist_ok=True);(folder/'input.txt').write_text(inp);(folder/'raw_expected.txt').write_text(expected);c={'name':name,'kind':'source','condition':'raw','input_path':str((folder/'input.txt').relative_to(B)),'input_sha256':validate.sha(inp.encode()),'validity':v,'runs':{},'raw_expected_path':str((folder/'raw_expected.txt').relative_to(B)),'raw_expected_sha256':validate.sha(expected.encode()),'recovery':'Removed spurious SAMPLE heading token from extracted upstream input; verified original Raw sample text.'}
  if k==101:c['illustrative_sample_exception']='Original statement explicitly abbreviates sample day length; retained and executed separately from strict native-domain scored inputs.'
  for role in ['raw_fast','l3_fast','raw_oracle','l3_oracle']:c['runs'][role]=p.run(role,inp,5,folder/role);assert c['runs'][role]['status']=='OK',(k,role)
  c['raw_expected_matched']=validate.accepted(m,seed['recipe_id'],inp,validate.output(c['runs']['raw_fast']),expected,'raw');assert c['raw_expected_matched']
  for role,fast,cond in [('raw_oracle','raw_fast','raw'),('l3_oracle','l3_fast','l3')]:c[role+'_matched']=validate.accepted(m,seed['recipe_id'],inp,validate.output(c['runs'][fast]),validate.output(c['runs'][role]),cond);assert c[role+'_matched']
  c['l3_distinguishes_raw']=validate.output(c['runs']['raw_fast']).split()!=validate.output(c['runs']['l3_fast']).split();rep['cases']=[q for q in rep['cases']if q['name']!=name]+[c];rec.append({'upstream_name':x['name'],'original_input_sha256':validate.sha(orig.encode()),'recovered_input_sha256':c['input_sha256'],'original_raw_sample_confirmed':True,'matched':True,'exception':c.get('illustrative_sample_exception')})
 rep['recovered_public_samples']=rec;validate.write_json(rp,rep);rows.append({'seed_id':seed['seed_id'],'samples':rec});print(seed['seed_id'],'samples restored',len(rec),flush=True)
validate.write_json(B/'native/cc_a_public_sample_repairs.json',{'records':rows,'upstream_source_test_files_modified':False})
