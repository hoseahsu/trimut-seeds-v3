#!/usr/bin/env python3
"""Export the audited dataset; omit caches and reproducible ELF executables."""
import hashlib,json,subprocess,tempfile,zipfile,sys
from pathlib import Path
B=Path(__file__).resolve().parents[1]

def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for block in iter(lambda:f.read(4*1024**2),b''):h.update(block)
 return h.hexdigest()

def main():
 summary=json.loads((B/'release_summary.json').read_text())
 assert summary['release_status']=='validated_finite_cases_integrity_passed'
 assert sha(B/summary['integrity_audit']['path'])==summary['integrity_audit']['sha256']
 seeds=[json.loads(l) for l in (B/'seeds.jsonl').read_text().splitlines()]
 assert len(seeds)==300
 prefix=B.name;parent=B.parent
 promptzip=parent/(prefix+'_prompts.zip')
 with zipfile.ZipFile(promptzip,'w',compression=zipfile.ZIP_DEFLATED,compresslevel=6) as z:
  z.writestr(prefix+'/PROMPT_PACKAGE_README.txt',
   '本包是300道公开原题的1200份题面，Raw/L1/L2/L3各300份。\n'
   '调用模型时仅发送 prompts.jsonl 的 prompt 字段。source_index.jsonl 是研究元数据，不随题面发送。\n'
   '本题面包不含判题数据。完整说明README中的验证、合同等链接需在完整实验包内打开。\n'
   '完整实验包：trimut_seed300_strict_full.tar.zst；其中包含测试、参考程序、运行证据和判题入口。\n')
  for f in ('README.md','INDEX.md','prompts.jsonl','release_summary.json'):z.write(B/f,prefix+'/'+f)
  metadata=[]
  for seed in seeds:
   metadata.append({k:seed[k] for k in ('seed_id','title','source_identity','source','l1_kind','l2_bound_changes','l3_operator','family_split_groups')})
   for cfg in seed['conditions'].values():
    rel=cfg['statement']['path'];assert sha(B/rel)==cfg['statement']['sha256'];z.write(B/rel,prefix+'/'+rel)
  z.writestr(prefix+'/source_index.jsonl',''.join(json.dumps(x,ensure_ascii=False)+'\n' for x in metadata))
 with zipfile.ZipFile(promptzip) as z:
  assert z.testzip() is None
  assert sum(n.endswith(('/raw.txt','/l1.txt','/l2.txt','/l3.txt')) for n in z.namelist())==1200
 print('Prompt ZIP CRC passed',flush=True)

 entries=[];excluded=[]
 for p in sorted(B.rglob('*')):
  assert not p.is_symlink(),'Unexpected symlink: '+str(p)
  if not p.is_file():continue
  rel=str(p.relative_to(B))
  if rel=='PACKAGE_FILES.jsonl':continue
  if '__pycache__' in p.parts or p.suffix=='.pyc':excluded.append(rel);continue
  with p.open('rb') as f:magic=f.read(4)
  if magic==b'\x7fELF':excluded.append(rel);continue
  entries.append({'path':rel,'bytes':p.stat().st_size,'sha256':sha(p)})
 manifest=B/'PACKAGE_FILES.jsonl';manifest.write_text(''.join(json.dumps(x,ensure_ascii=False)+'\n' for x in entries))
 names=[prefix+'/'+e['path'] for e in entries]+[prefix+'/PACKAGE_FILES.jsonl']
 archive=parent/(prefix+'_full.tar.zst');partial=Path(str(archive)+'.part')
 print(json.dumps({'archived_files':len(names),'uncompressed_bytes':sum(e['bytes'] for e in entries),'excluded_reproducible_files':len(excluded)}),flush=True)
 with tempfile.NamedTemporaryFile(prefix='trimut-package-',suffix='.list',dir=parent) as listing:
  listing.write(b'\0'.join(n.encode() for n in names)+b'\0');listing.flush()
  subprocess.run(['tar','--use-compress-program=zstd -T2 -3','-cf',str(partial),'-C',str(parent),'--null','--verbatim-files-from','--files-from',listing.name],check=True)
 subprocess.run(['zstd','-t','--quiet',str(partial)],check=True)
 listed=subprocess.run(['tar','--zstd','-tf',str(partial)],check=True,capture_output=True,text=True).stdout.splitlines()
 assert len(listed)==len(names) and set(listed)==set(names)
 partial.replace(archive)
 print('Archive frame and member checks passed; verifying a fresh extraction',flush=True)
 # /tmp may be a small tmpfs; the experiment filesystem must hold the full suite.
 with tempfile.TemporaryDirectory(prefix='trimut-release-verify-',dir=parent) as temp:
  subprocess.run(['tar','--zstd','-xf',str(archive),'-C',temp],check=True,capture_output=True,text=True)
  extracted=Path(temp)/prefix
  audit=subprocess.run([sys.executable,'tools/audit_release.py'],cwd=extracted,check=True,capture_output=True,text=True)
  extracted_audit=json.loads(audit.stdout.strip().splitlines()[-1]);assert extracted_audit['passed']
  smoke=subprocess.run([sys.executable,'tools/judge.py','--seed','TM221','--condition','raw','--reference','--limit','1'],cwd=extracted,check=True,capture_output=True,text=True)
  extracted_smoke=json.loads(smoke.stdout.strip().splitlines()[-1]);assert extracted_smoke['passed']
  # The temporary tree is deliberately removed; keep its outcomes, not a dead log path.
  extracted_smoke.pop('report',None)
 artifacts={'schema':'trimut.artifacts.v1','seed_count':300,'prompt_count':1200,
  'integrity_audit':summary['integrity_audit'],'full_package_file_manifest_sha256':sha(manifest),
  'archives':[{'file':p.name,'bytes':p.stat().st_size,'sha256':sha(p)} for p in (promptzip,archive)],
  'checks':{'prompt_zip_crc':True,'prompt_zip_statement_count':1200,'full_zstd_frame_integrity':True,'full_tar_exact_member_list':True,'fresh_extraction_core_audit':extracted_audit,'fresh_extraction_reference_smoke':extracted_smoke},
  'archive_file_count':len(names),'excluded_reproducible_file_count':len(excluded),
  'exclusion_policy':'Python caches and ELF build executables only; original text/code, formal tests and historical execution reports retained.'}
 out=parent/(prefix+'_artifacts.json');out.write_text(json.dumps(artifacts,ensure_ascii=False,indent=2)+'\n')
 print(json.dumps(artifacts,ensure_ascii=False),flush=True)

if __name__=='__main__':main()
