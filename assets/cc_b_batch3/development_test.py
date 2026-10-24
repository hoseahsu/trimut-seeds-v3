"""Development tests for locally authored programs; formal sandbox report is separate."""
import importlib.util,sys,subprocess,tempfile,time,json,random,concurrent.futures
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
spec=importlib.util.spec_from_file_location('cc2',ROOT/'recipes/cc_b_batch3.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
BUILD=Path(tempfile.mkdtemp(prefix='trimut-ccb3-dev-'))
rows={e['row_idx']:e['row']for f in ['0500','0600','0700','0800']for e in json.load(open('/tmp/trimut_public_downloads/codecontests_'+f+'.json'))['rows']}
def run(command,text,timeout=20):
 start=time.monotonic()
 try:
  p=subprocess.run(command,input=text,text=True,capture_output=True,timeout=timeout)
  return {'status':'OK'if p.returncode==0 else'RE','wall_seconds':time.monotonic()-start,'out':p.stdout,'stderr':p.stderr[:500]}
 except subprocess.TimeoutExpired:return {'status':'TLE','wall_seconds':time.monotonic()-start}
def compile_one(item):
 id,role= item;src=mod.RECIPES[id][role];binary=BUILD/(id+'_'+role)
 p=subprocess.run(['/usr/bin/g++','-std=c++17','-O2',src,'-o',str(binary)],capture_output=True,text=True)
 if p.returncode:raise RuntimeError(p.stderr)
 return(id,role),str(binary)
jobs=[(id,role)for id in mod.RECIPES for role in('raw_fast','l3_fast','slow_baseline')]
with concurrent.futures.ThreadPoolExecutor(max_workers=3)as pool:binaries=dict(pool.map(compile_one,jobs))
report={'note':'Development checks run locally authored references, not downloaded code. These are preliminary wall-time observations; formal harness provides isolated runtime and CPU evidence.','build_directory':str(BUILD),'recipes':{}}
for id,cfg in mod.RECIPES.items():
 item={'differential_cases':0,'source_tests':0,'source_extraction_repairs':[],'errors':[]};report['recipes'][id]=item
 for mode in('small','boundary','weak'):
  for name,text in mod.cases(id,mode,random.Random(137)):
   cond='weak'if mode=='weak'else'raw'
   assert mod.validate_input(id,text,cond),(id,name)
   for role,condition in [('raw_fast','raw'),('l3_fast','l3')]:
    fast=run([binaries[id,role]],text);o=cfg['raw_oracle'if role=='raw_fast'else'l3_oracle'];oracle=run(['/usr/bin/python3',o['path'],*o['args']],text)
    if fast['status']!='OK'or oracle['status']!='OK'or not mod.check_output(id,text,fast.get('out',''),oracle.get('out',''),condition):item['errors'].append({'case':name,'condition':condition,'fast':fast,'oracle':oracle,'input':text})
    else:item['differential_cases']+=1
   if mode=='weak':
    slow=run([binaries[id,'slow_baseline']],text,cfg['budget_seconds']);fast=run([binaries[id,'raw_fast']],text)
    if slow['status']!='OK'or not mod.check_output(id,text,slow.get('out',''),fast['out'],'weak'):item['errors'].append({'case':name,'slow_weak':slow})
 for testkind in('public_tests','private_tests'):
  tests=rows[cfg['source_row_index']][testkind]
  for i,(text,expected)in enumerate(zip(tests['input'],tests['output'])):
   if not mod.validate_input(id,text,'raw')and text.rstrip().endswith('SAMPLE'):
    fixed=text.rstrip()[:-6].rstrip()+'\n'
    if mod.validate_input(id,fixed,'raw'):text=fixed;item['source_extraction_repairs'].append({'kind':testkind,'index':i,'repair':'Removed exact terminal SAMPLE extraction marker; original snapshot retained unchanged.'})
   if not mod.validate_input(id,text,'raw'):
    item['errors'].append({'kind':testkind,'index':i,'error':'Invalid source test input'});continue
   fast=run([binaries[id,'raw_fast']],text,10)
   if fast['status']=='OK'and mod.check_output(id,text,fast['out'],expected,'raw'):item['source_tests']+=1
   else:item['errors'].append({'kind':testkind,'index':i,'expected':expected[:500],'actual':fast})
 for name,text in mod.cases(id,'stress',random.Random(137)):
  assert mod.validate_input(id,text,'l2'),id
  item['stress']={}
  for role in('raw_fast','l3_fast','slow_baseline'):
   result=run([binaries[id,role]],text,cfg['budget_seconds']);result.pop('out',None);item['stress'][role]=result
  if item['stress']['raw_fast']['status']!='OK'or item['stress']['l3_fast']['status']!='OK'or item['stress']['slow_baseline']['status']!='TLE':item['errors'].append({'error':'Timing separation failed','stress':item['stress']})
 print(id,json.dumps({k:v for k,v in item.items()if k not in('source_extraction_repairs','errors')}), 'errors',len(item['errors']),flush=True)
 (Path(__file__).parent/'development_validation.json').write_text(json.dumps(report,indent=2))
if any(x['errors']for x in report['recipes'].values()):sys.exit(1)
