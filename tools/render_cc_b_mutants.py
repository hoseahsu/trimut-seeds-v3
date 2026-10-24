#!/usr/bin/env python3
"""Apply recorded local edits to full originals and regenerate every L3 sample."""
import json,sys
from pathlib import Path
BASE=Path(__file__).resolve().parents[1];sys.path[:0]=[str(BASE/'mutations'),str(BASE/'native')]
import cc_b83_statements as edits,cc_b_samples,cc_b83,validate
def apply(s,pairs):
 ledger=[]
 for a,b in pairs:
  count=s.count(a);assert count,'missing original span '+repr(a)
  s=s.replace(a,b);ledger.append({'old':a,'new':b,'occurrences':count})
 return s,ledger
def main():
 results=[]
 for k in edits.L2:
  sid=f'TM{k:03}';folder=BASE/'tasks'/sid;raw=(folder/'raw.txt').read_text();rec={'seed_id':sid,'raw_sha256':validate.sha(raw.encode()),'status':'pending'}
  try:
   l2,ed2=apply(raw,edits.L2[k]);(folder/'l2.txt').write_text(l2)
   body,removed=cc_b_samples.statement_body(raw,k);l3,ed3=apply(body,edits.L3[k]);rp=BASE/f'validation/strict_cc_b_supplement/{sid}/report.json';report=json.loads(rp.read_text());assert report['finite_checks_passed'],report['failures']
   cases={c['name']:c for c in report['cases']};samples=cc_b_samples.extract(raw);cert=[]
   for j,x in enumerate(samples,1):
    c=cases[f'original_statement_sample_{j}'];assert c['raw_expected_matched'];assert c['input_sha256']==validate.sha(x['input'].encode());r=c['runs']['l3_fast'];assert r['status']=='OK';output=Path(r['stdout_path']).read_text()
    l3+=f'\n\nSample Input {j}\n\n```text\n{x["input"].rstrip()}\n```\n\nSample Output {j}\n\n```text\n{output.rstrip()}\n```'
    cert.append({'original_input_sha256':c['input_sha256'],'l3_output_sha256':validate.sha(output.encode()),'run_report':str(rp.relative_to(BASE)),'case':c['name']})
   l3+='\n';(folder/'l3.txt').write_text(l3);rec.update(status='rendered',l2_edits=ed2,l3_edits=ed3,dependent_inline_examples_replaced=removed,original_samples=cert,l2_sha256=validate.sha(l2.encode()),l3_sha256=validate.sha(l3.encode()),sample_explanation_policy='Original sample inputs retained in full. Outputs regenerated using isolated L3 reference. Old output-dependent explanations replaced; post-sample definitions and constraints retained.')
  except Exception as e:rec['error']=str(e)
  validate.write_json(folder/'mutation_edits.json',rec);results.append(rec)
 validate.write_json(BASE/'mutations/cc_b_render_status.json',results)
 print('rendered',sum(x['status']=='rendered'for x in results),'of',len(results))
 for r in results:
  if r['status']!='rendered':print(r['seed_id'],r.get('error'))
if __name__=='__main__':main()
