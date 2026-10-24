"""Reproduce weak-range L3 semantic witnesses with independently authored Python oracles."""
from pathlib import Path
import importlib.util,subprocess,random,json,hashlib,sys
ROOT=Path(__file__).resolve().parents[1];report={'note':'Weak-profile witnesses from independent oracles; reference implementation differential evidence is recorded separately.','witnesses':{},'errors':[]}
def digest(s):return hashlib.sha256(s.encode()).hexdigest()
for name in ['codecontests_batch2','cc_b_batch3','cc_b_batch4','cc_b_batch5']:
 spec=importlib.util.spec_from_file_location(name,ROOT/'recipes'/f'{name}.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
 for id,cfg in m.RECIPES.items():
  for case,text in m.cases(id,'boundary',random.Random(137)):
   assert m.validate_version_input(id,text,'raw')and m.validate_version_input(id,text,'l3')
   outputs={}
   for condition in ['raw','l3']:
    o=cfg[condition+'_oracle'];p=subprocess.run([sys.executable,o['path'],*o['args']],input=text,text=True,capture_output=True,timeout=20);assert p.returncode==0,p.stderr;outputs[condition]=p.stdout
   if not m.check_output(id,text,outputs['raw'],outputs['l3'],'l3'):
    report['witnesses'][id]={'case':case,'input':text,'raw_output':outputs['raw'],'l3_output':outputs['l3'],'input_sha256':digest(text),'raw_sha256':digest(outputs['raw']),'l3_sha256':digest(outputs['l3']),'weak_profile_admitted':True,'raw_rejected_under_l3_checker':True};break
  else:report['errors'].append(id)
(ROOT/'assets/cc_b_l3_witnesses.json').write_text(json.dumps(report,indent=2,ensure_ascii=False));print('witnesses',len(report['witnesses']),'errors',report['errors']);raise SystemExit(bool(report['errors']))
