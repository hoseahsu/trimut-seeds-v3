"""Rebuild upstream validators/references and compare all generated raw cases.
Run from any directory with Python 3.11+ and g++ installed.
"""
import importlib.util,subprocess,concurrent.futures,random,pathlib,json,sys,tempfile
base=pathlib.Path(__file__).resolve().parents[2]
spec=importlib.util.spec_from_file_location('library_batch',base/'recipes/library_batch4.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
work=tempfile.TemporaryDirectory(prefix='trimut_library_upstream_')
bin=pathlib.Path(work.name)/'bins';bin.mkdir()
import tomllib,hashlib
src=base/'sources/library-checker-problems-master';tmp=pathlib.Path(work.name)/'upstream';tmp.mkdir()
entries={id:next(src.rglob(id+'/info.toml')).parent for id in m.IDS}
def build(id):
 p=entries[id];out=tmp/id;out.mkdir(exist_ok=True);params=tomllib.loads((p/'info.toml').read_text()).get('params',{})
 (out/'params.h').write_text(''.join(f'#define {k} {v}LL\n' for k,v in params.items()))
 for kind,f in [('verifier',p/'verifier.cpp'),('official',p/'sol/correct.cpp'),('raw',base/f'assets/library_batch4/{id}_raw.cpp')]:
  r=subprocess.run(['g++','-std=c++17','-O2','-I',str(src/'common'),'-I',str(out),str(f),'-o',str(out/kind)],capture_output=True,text=True)
  if r.returncode:raise RuntimeError((id,kind,r.stderr))
with concurrent.futures.ThreadPoolExecutor(max_workers=3)as ex:list(ex.map(build,m.IDS))
print('20 upstream + 10 project reference programs compiled',flush=True);report=[]
for id in m.IDS:
 count=0
 for mode in ['small','boundary','weak']:
  for name,t in m.cases(id,mode,random.Random(123)):
   v=subprocess.run([str(tmp/id/'verifier')],input=t,text=True,capture_output=True)
   assert v.returncode==0,(id,name,v.stderr)
   a=subprocess.run([str(tmp/id/'official')],input=t,text=True,capture_output=True,timeout=20)
   o=subprocess.run([str(tmp/id/'raw')],input=t,text=True,capture_output=True,timeout=20)
   assert a.returncode==0 and m.check_output(id,t,o.stdout,a.stdout,'raw'),(id,name,a.stderr,a.stdout,o.stdout)
   count+=1
 # Validate strong input and compare complete output to upstream optimized source.
 for name,t in m.cases(id,'stress',random.Random(321)):
  v=subprocess.run([str(tmp/id/'verifier')],input=t,text=True,capture_output=True,timeout=20);assert v.returncode==0,(id,name,v.stderr)
  a=subprocess.run([str(tmp/id/'official')],input=t,text=True,capture_output=True,timeout=20)
  o=subprocess.run([str(tmp/id/'raw')],input=t,text=True,capture_output=True,timeout=20)
  assert a.returncode==0 and m.check_output(id,t,o.stdout,a.stdout,'raw'),(id,name,a.stderr)
  count+=1
 row={'source_id':id,'upstream_verified_inputs_and_reference_agreements':count,'upstream_statement_sha256':hashlib.sha256((entries[id]/'task.md').read_bytes()).hexdigest(),'upstream_solution_sha256':hashlib.sha256((entries[id]/'sol/correct.cpp').read_bytes()).hexdigest(),'upstream_verifier_sha256':hashlib.sha256((entries[id]/'verifier.cpp').read_bytes()).hexdigest()};print(row,flush=True);report.append(row)
(base/'curation/library_batch4_upstream_check.json').write_text(json.dumps(report,indent=2)+'\n')
