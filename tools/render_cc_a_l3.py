#!/usr/bin/env python3
"""Render exact L3 edits with original inputs and newly executed example outputs."""
import json,sys,re,hashlib
from pathlib import Path
B=Path(__file__).resolve().parents[1];sys.path[:0]=[str(B/'native'),str(B/'mutations')]
from cc_b_samples import extract
import cc_a82_statements as E
from render_root_mutants import apply,body
import cc_a82

def sha(s):return hashlib.sha256(s.encode()).hexdigest()
def main():
 records=[]
 for k in range(56,138):
  if k==70:continue
  sid=f'TM{k:03d}';folder=B/'tasks'/sid;raw=(folder/'raw.txt').read_text();row={'seed_id':sid,'raw_sha256':sha(raw),'status':'pending'}
  try:
   s=body(raw,k);region=[]
   for start,end,new in E.REGION_EDITS.get(k,[]):
    a=s.index(start);b=s.index(end,a);region.append({'before':s[a:b],'after':new});s=s[:a]+new+s[b:]
   s,ledger=apply(s,E.L3[k])
   if k==102:
    definition=raw.split('\nNote\n',1)[1].strip().split('\n\n',1)[0];s+='\n\nNote\n\n'+definition;region.append({'preserved_original_definition':definition})
   if k==97:s+='\n\nIf no name occurs exactly once in a test case, output no name lines for that test case.'
   if k in E.REMOVE_ILLUSTRATIONS:
    s=re.sub(r'!\[[^\]]*\]\([^)]*\)','',s)
   samples=extract(raw.split('\nExplanation')[0] if k==133 else raw)
   rp=B/'validation/strict_cc_a'/sid/'report.json';report=json.loads(rp.read_text());lookup={tuple((B/x['input_path']).read_text().split()):x for x in report['cases']}
   outputs=[]
   for j,sm in enumerate(samples,1):
    c=lookup.get(tuple(sm['input'].split()));assert c,(sid,'missing original sample',j)
    v=cc_a82.validate(k,sm['input']);assert v['valid']or k==101
    run=c['runs']['l3_fast'];assert run['status']=='OK'
    ans=Path(run['stdout_path']).read_text();s+=f'\n\nSample Input {j}\n\n```text\n{sm["input"].rstrip()}\n```\n\nSample Output {j}\n\n```text\n{ans.rstrip()}\n```'
    outputs.append({'input':sm['input'],'output':ans,'input_sha256':sha(sm['input']),'output_sha256':sha(ans),'run_report':str(rp.relative_to(B)),'case':c['name'],'input_validity':v,'original_abbreviated_sample':k==101})
   s+='\n';(folder/'l3.txt').write_text(s);row.update(status='rendered',l3_sha256=sha(s),edits=ledger,region_edits=region,illustrations_removed=k in E.REMOVE_ILLUSTRATIONS,samples=outputs,original_sample_explanations='Replaced with computed L3 sample answers; unchanged Raw retains original explanations.')
   (folder/'l3_render_provenance.json').write_text(json.dumps(row,ensure_ascii=False,indent=2)+'\n')
  except Exception as e:row['error']=repr(e)
  records.append(row)
 (B/'mutations/cc_a82_render_status.json').write_text(json.dumps(records,ensure_ascii=False,indent=2)+'\n')
 print('rendered',sum(x['status']=='rendered'for x in records),'of',len(records));print([(r['seed_id'],r['error'])for r in records if 'error'in r])
if __name__=='__main__':main()
