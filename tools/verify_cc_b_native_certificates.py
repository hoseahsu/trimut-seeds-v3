#!/usr/bin/env python3
"""Add independently known answers at original upper bounds; no recompilation."""
import json,sys
from pathlib import Path
BASE=Path(__file__).resolve().parents[1];sys.path[:0]=[str(BASE/'native')]
import validate,cc_b83,cc_b_extensions
def main():
 sandbox=validate.Sandbox();assert sandbox.available
 rows={int(x['seed_id'][2:]):x for x in map(json.loads,(BASE/'curation/previous_seed_index.jsonl').read_text().splitlines())}
 for k in range(138,221):
  if k==149:continue
  sid=f'TM{k:03}';out=BASE/f'validation/strict_cc_b_supplement/{sid}';rp=out/'report.json';r=json.loads(rp.read_text());assert r['finite_checks_passed'],sid
  if any(c['name']=='certified_native_upper'for c in r['cases']):continue
  inp,expected,proof=cc_b_extensions.certificate(k,False);l3_inp,l3_expected,l3_proof=cc_b_extensions.l3_native_certificate(k);assert inp==l3_inp,sid
  v=cc_b83.validate(k,inp);assert v['valid'],(sid,v)
  folder=out/'cases/certified_native_upper';folder.mkdir(parents=True,exist_ok=True);(folder/'input.txt').write_text(inp);(folder/'expected.txt').write_text(expected)
  (folder/'l3_expected.txt').write_text(l3_expected)
  c={'name':'certified_native_upper','condition':'raw','input_path':str((folder/'input.txt').relative_to(BASE)),'input_sha256':validate.sha(inp.encode()),'expected_path':str((folder/'expected.txt').relative_to(BASE)),'expected_sha256':validate.sha(expected.encode()),'expected_derivation':proof,'l3_expected_path':str((folder/'l3_expected.txt').relative_to(BASE)),'l3_expected_sha256':validate.sha(l3_expected.encode()),'l3_expected_derivation':l3_proof,'validity':v,'runs':{}}
  for role in ['raw_fast','l3_fast']:
   m=r['programs'][role];assert validate.file_hash(Path(m['source_path']))==m['source_sha256'];assert all(validate.file_hash(Path(p))==h for p,h in m.get('header_sha256',{}).items());binary=Path(m['mounts'][1]);assert validate.file_hash(binary)==m['binary_sha256']
   c['runs'][role]=sandbox.execute(m['command'],m['mounts'],inp.encode(),5,2048,128*1024**2,folder/role)
  module=validate.load_recipe(BASE/rows[k]['recipe_module']);c['raw_expected_matched']=c['runs']['raw_fast']['status']=='OK'and validate.accepted(module,rows[k]['recipe_id'],inp,validate.output(c['runs']['raw_fast']),expected,'raw')
  c['l3_expected_matched']=c['runs']['l3_fast']['status']=='OK'and validate.accepted(module,rows[k]['recipe_id'],inp,validate.output(c['runs']['l3_fast']),l3_expected,'l3')
  if not c['raw_expected_matched']or not c['l3_expected_matched']:r['failures'].append({'case':c['name'],'reason':'native_certificate_failed'});r['finite_checks_passed']=False
  r['cases'].append(c);r['extension_certificate_sha256']=validate.file_hash(BASE/'native/cc_b_extensions.py');validate.write_json(rp,r);print(sid,c['raw_expected_matched'],c['runs']['l3_fast']['status'],flush=True)
if __name__=='__main__':main()
