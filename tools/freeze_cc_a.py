from pathlib import Path
import json,sys,hashlib,re
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'native'),str(B/'recipes')]
import validate,cc_a82,cc_b_samples
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
def ref(p):p=Path(p);return {'path':str(p.relative_to(B)),'sha256':sha(p)}
def write(p,x):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,ensure_ascii=False,indent=2)+'\n')
scale={x['seed_id']:x for x in json.loads((B/'validation/cc_a_scale_audit.json').read_text())['records']};rows=[];errors=[]
for seed in map(json.loads,(B/'curation/previous_seed_index.jsonl').read_text().splitlines()):
 sid=seed['seed_id'];k=int(sid[2:])
 if not 56<=k<=137 or k==70:continue
 try:
  p=B/'tasks'/sid;rp=B/'validation/strict_cc_a'/sid/'report.json';r=json.loads(rp.read_text());assert r['status']=='complete'and scale[sid]['passed'];assert not r['failures']or(k==103 and json.loads((rp.parent/'portable_reference_audit/report.json').read_text())['passed'])
  m=validate.load_recipe(B/seed['recipe_module']);cfg=m.RECIPES[seed['recipe_id']];man={q:[]for q in('raw','l2','l3')};seen=set()
  for c in r['cases']:
   inp=B/c['input_path'];valid=cc_a82.validate(k,inp.read_text(),'l2'if c['kind']=='l2_upper'else'raw');exception=c.get('illustrative_sample_exception')
   assert valid['valid']or exception,(sid,c['name'],valid)
   group='l2'if c['kind']=='l2_upper'else'raw';h=sha(inp)
   if(group,h)in seen:continue
   seen.add((group,h));dest=p/'tests'/group;dest.mkdir(parents=True,exist_ok=True);name=c['name'];ip=dest/(name+'.in');ip.write_bytes(inp.read_bytes())
   for cond in(['l2']if group=='l2'else['raw','l3']):
    role='l3_fast'if cond=='l3'else'raw_fast';run=c['runs'][role];assert run['status']=='OK';op=p/'tests'/cond/(name+'.out');op.parent.mkdir(parents=True,exist_ok=True)
    independent=c.get('l3_oracle_matched',False)if cond=='l3'else c.get('raw_oracle_matched',False)
    if c['kind']in('native_upper','l2_upper'):
     rec=next(z for z in scale[sid]['cases']if z['name']==c['name']);assert rec['checks'][role]['match'];ep=B/rec['checks'][role]['expected_path'];independent=True
    elif cond!='l3'and c.get('raw_expected_path'):ep=B/c['raw_expected_path']
    else:ep=Path(run['stdout_path'])
    op.write_bytes(ep.read_bytes());assert validate.accepted(m,seed['recipe_id'],ip.read_text(),Path(run['stdout_path']).read_text(),op.read_text(),'l3'if cond=='l3'else'raw')
    entry={'name':name,'kind':c['kind'],'input_path':str(ip.relative_to(B)),'input_sha256':sha(ip),'expected_path':str(op.relative_to(B)),'expected_sha256':sha(op),'native_validity':valid,'reference_execution':{'status':'OK','cpu_seconds':run['cpu_seconds'],'cpu_affinity':run['cpu_affinity'],'evidence_report':str(rp.relative_to(B)),'case':name,'role':role},'independently_checked_this_input':independent,'reference_output_provenance':'independent_oracle_or_analytical_scale_expectation'if independent else'official_public_or_hidden_expected'if cond!='l3'and c.get('raw_expected_path')else'verified_fast_program_generated'}
    if exception:entry.update(illustrative_sample_exception=exception,scored=False)
    man[cond].append(entry)
  rawtext=(p/'raw.txt').read_text();samples=cc_b_samples.extract(rawtext.split('\nExplanation')[0]if k==133 else rawtext);native_inputs={''.join((B/x['input_path']).read_text().split())for x in man['raw']};missing=[j for j,x in enumerate(samples)if ''.join(x['input'].split())not in native_inputs];assert not missing,(sid,'missing_original_samples',missing)
  for cond in('raw','l2','l3'):
   header={'schema_version':'cc-native-tests-v1','seed_id':sid,'condition':cond,'test_scope':'selected reproducible experimental subset; not entire official hidden suite','cpu_budget_seconds':5,'memory_mb':2048,'budget_origin':'frozen research execution budget, not asserted to be the source judge budget','records':man[cond]}
   if cond in('raw','l3'):header.update(contains_all_original_samples=True,native_upper_bound_reached=True)
   if cond=='raw':header['raw_l1_policy']='Raw and L1 share this exact manifest and all test bytes/budgets.'
   if cond=='l2':header.update(strictly_outside_original_bound=True,algorithm_separation_claim=False)
   write(p/(cond+'_test_manifest.json'),header)
  (p/'l1_test_manifest.json').write_bytes((p/'raw_test_manifest.json').read_bytes())
  proofs=cfg.get('proof_sketch',cfg.get('spec',{}).get('proof_sketch','See authored recipe and independent oracle algorithms.'))
  contract={'schema':'trimut.strict.cc_a.v1','seed_id':sid,'source_identity':seed['source_identity'],'source_url':seed['source']['source_url'],'distinct_public_original':True,'family_split_groups':[seed['source_identity']],'raw':{'statement':ref(p/'raw.txt'),'provenance':ref(p/'raw_provenance.json'),'tests':ref(p/'raw_test_manifest.json'),'native_upper_bound_reached':True,'all_original_examples_included':True},'l1':{'statement':ref(p/'l1.txt'),'certificate':ref(p/'l1_certificate.json'),'tests_must_equal_raw_manifest':ref(p/'raw_test_manifest.json'),'constraints_unchanged':True},'l2':{'statement':ref(p/'l2.txt'),'certificate':ref(p/'l2_certificate.json'),'tests':ref(p/'l2_test_manifest.json'),'axis':cc_a82.AXES[k],'original_upper':cc_a82.CAPS[k][0],'expanded_upper':cc_a82.CAPS[k][1],'native_upper_bound_strictly_expanded':True,'fast_program_passed_frozen_expanded_tests':True,'algorithm_resource_separation_validated':False,'separation_note':'A strict original-bound expansion with measured execution, not evidence that passing the original maximum forces algorithm replacement.'},'l3':{'statement':ref(p/'l3.txt')if(p/'l3.txt').exists()else None,'tests':ref(p/'l3_test_manifest.json'),'operator':cfg.get('l3_change',cfg.get('l3_spec')),'correctness_argument':proofs,'independent_small_oracle_agreement':True,'independent_small_cases':sum(c.get('l3_oracle_matched',False)for c in r['cases']),'native_domain_runs_passed':True,'native_upper_independent_check_passed':True,'distinguishing_witnesses':[c['name']for c in r['cases']if c.get('l3_oracle_matched')and c.get('l3_distinguishes_raw')],'native_constraints_preserved':True},'programs':{role:{'path':str(Path(meta['source_path']).relative_to(B)),'sha256':meta['source_sha256'],'args':meta['args'],'include_dirs':[],'compiler_options':['-std=c++17','-O2','-pipe']}for role,meta in r['programs'].items()if role!='source_native'},'native_input_contract':ref(B/'native/cc_a82.py'),'validation':{'execution':ref(rp),'independent_scale':ref(B/'validation/cc_a_scale_audit.json'),'source_portability_adjudication':ref(rp.parent/'portable_reference_audit/report.json')if k==103 else None},'budget':{'cpu_seconds':5,'memory_mb':2048,'origin':'research protocol, identical in Raw/L1/L2/L3'},'admitted':(p/'l3.txt').exists(),'limitations':['Finite tests and constructive oracle checks do not prove correctness on all legal inputs.','Large arbitrary source inputs may use fast reference outputs; per-case independent checking is explicitly marked.','L2 expands a real original bound; no general forced algorithm-separation claim.']}
  if k==120:contract['l2']['bound_changes']={'N':{'native':100000,'expanded':300000},'M':{'native':100000,'expanded':300000}}
  contract['programs']['l2_fast']=contract['programs']['raw_fast'];contract['checker']={'recipe_module':seed['recipe_module'],'recipe_id':seed['recipe_id'],'output_comparator':'source-matching comparator in recipe; TM137 absolute tolerance<1e-6'};contract['recipe_module']=seed['recipe_module'];contract['recipe_id']=seed['recipe_id']
  assert contract['l3']['distinguishing_witnesses'];write(B/'contracts/cc_a'/f'{sid}.json',contract);rows.append({'seed_id':sid,'admitted':contract['admitted'],'tests':{q:len(v)for q,v in man.items()}})
 except Exception as e:errors.append({'seed_id':sid,'error':str(e)})
write(B/'contracts/cc_a_status.json',{'records':rows,'errors':errors});print(json.dumps({'built':len(rows),'errors':errors},ensure_ascii=False))
