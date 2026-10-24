import importlib.util,pathlib,subprocess,sys,hashlib,json,random,tempfile,argparse
parser=argparse.ArgumentParser();parser.add_argument("--reuse-local-cache",action="store_true",help="Reuse development binaries under /tmp; default rebuilds references from shipped sources.");args=parser.parse_args();work=tempfile.TemporaryDirectory(prefix="trimut_version_audit_")
base=pathlib.Path(__file__).resolve().parents[1];spec=importlib.util.spec_from_file_location('bounds',base/'assets/library_release_bounds.py');b=importlib.util.module_from_spec(spec);spec.loader.exec_module(b);reports={}
for id,(m,c)in b.registry().items():
 batch=m.__name__.replace('library_batch','')or'1';bin=pathlib.Path('/tmp/trimut_library'+(''if batch=='1'else batch)+'_bins')if args.reuse_local_cache else pathlib.Path(work.name)/batch;bin.mkdir(exist_ok=True)
 for role in ['raw','l3']:
  target=bin/f'{id}_{role}';declaration=c[role+'_fast'];declaration={'path':declaration}if isinstance(declaration,str)else declaration;source=(base/'recipes'/declaration['path']).resolve()
  if not args.reuse_local_cache or not target.exists():subprocess.run(['g++','-std=c++17','-O2',str(source),'-o',str(target)],check=True)
 report={'witness':None,'case_version_counts':{},'failed_source_cases':[]}
 for mode in ['small','boundary','weak','stress']:
  inside=outside=0
  for name,t in m.cases(id,mode,random.Random(123)):
   assert b.validate_version_input(id,t,'source_original'),(id,mode,name,'sourceinvalid')
   required='l2'if mode=='stress'else'raw'
   if b.validate_version_input(id,t,required):inside+=1
   else:outside+=1
  report['case_version_counts'][mode]={'inside_expected_version':inside,'supplemental_outside_expected_version':outside}
  if mode=='stress':assert outside==0,(id,'stress exceeds strong caps')
 for name,t in b.strict_witness_candidates(id):
  raw=subprocess.run([str(bin/f'{id}_raw')],input=t,text=True,capture_output=True,timeout=20);l3=subprocess.run([str(bin/f'{id}_l3')],input=t,text=True,capture_output=True,timeout=20);assert raw.returncode==l3.returncode==0
  if not (m.distinguishes(id,t,raw.stdout,l3.stdout)if hasattr(m,'distinguishes')else raw.stdout.split()!=l3.stdout.split()):continue
  outputs={}
  for cond,actual in [('raw',raw.stdout),('l3',l3.stdout)]:
   cfg=c[cond+'_oracle'];p=(base/'recipes'/cfg['path']).resolve();o=subprocess.run([sys.executable,str(p),*cfg.get('args',[])],input=t,text=True,capture_output=True,timeout=30);assert o.returncode==0,(id,name,o.stderr);assert (m.check_output(id,t,actual,o.stdout,cond)if hasattr(m,'check_output')else actual.split()==o.stdout.split()),(id,name,cond)
   outputs[cond]=o.stdout
  report['witness']={'case_name':name,'input':t,'input_sha256':hashlib.sha256(t.encode()).hexdigest(),'raw_output':raw.stdout,'l3_output':l3.stdout,'raw_oracle_output':outputs['raw'],'l3_oracle_output':outputs['l3'],'source_input_valid':True,'raw_weak_and_l3_caps_valid':True,'old_output_rejected_under_l3':True,'size_metrics':b.measure_input(id,t)};break
 assert report['witness']is not None,(id,'NO STRICT WITNESS')
 reports[id]=report;print(id,'strictwitness',report['witness']['case_name'],flush=True)
(base/'curation/library_version_audit.json').write_text(json.dumps(reports,ensure_ascii=False,indent=2)+'\n');print(len(reports),'version audits')
