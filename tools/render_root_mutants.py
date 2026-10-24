#!/usr/bin/env python3
import json,re,sys
from pathlib import Path
BASE=Path(__file__).resolve().parents[1];sys.path[:0]=[str(BASE/'mutations'),str(BASE/'native')]
import root55_statements as edits
import validate,root55

def apply(s,pairs):
 ledger=[]
 for old,new in pairs:
  count=s.count(old)
  if not count:raise ValueError('missing expected original span: '+old)
  s=s.replace(old,new);ledger.append({'old':old,'new':new,'occurrences':count})
 return s,ledger

def body(raw,k):
 mark=re.search(r'(?mi)^(?:Examples?|Sample Input(?: \d+)?|SAMPLE INPUT)\s*$',raw)
 assert mark,(k,'sample boundary not found')
 s=raw[:mark.start()].rstrip()
 # CodeChef puts its constraints after the samples: preserve this native section.
 if k==54:s+='\n\n'+raw[raw.index('Constraints',mark.start()):]
 return s

def main():
 seeds={int(x['seed_id'][2:]):x for x in map(json.loads,(BASE/'curation/previous_seed_index.jsonl').read_text().splitlines())};results=[]
 for k in edits.L2:
  sid=f'TM{k:03d}';folder=BASE/'tasks'/sid;raw=(folder/'raw.txt').read_text();record={'seed_id':sid,'status':'pending','raw_sha256':validate.sha(raw.encode())}
  try:
   l2,l2ledger=apply(raw,edits.L2[k]);(folder/'l2.txt').write_text(l2);record['l2_edits']=l2ledger
   l3,l3ledger=apply(body(raw,k),edits.L3[k]);record['l3_edits']=l3ledger
   source=json.loads((BASE/seeds[k]['source']['source_tests']).read_text())['public_tests'];rp=BASE/'validation/strict_root'/sid/'report.json';report=json.loads(rp.read_text())if rp.exists()else{};cases={x['input_sha256']:x for x in report.get('cases',[])}
   if k==39:source={'input':['1\n2 2\n']}
   samples=[]
   for j,inp in enumerate(source['input']):
    validity=root55.validate(k,inp)
    if not validity['valid']:raise ValueError('original public sample invalid: '+str(validity))
    c=cases.get(validate.sha(inp.encode()));run=c.get('runs',{}).get('l3_fast')if c else None
    if not run or run['status']!='OK':raise ValueError(f'sample {j+1} L3 execution pending')
    output=Path(run['stdout_path']).read_text();samples.append({'input':inp,'output':output,'input_sha256':validate.sha(inp.encode()),'output_sha256':validate.sha(output.encode()),'run_path':str((rp).relative_to(BASE))})
   for j,x in enumerate(samples,1):l3+=f'\n\nSample Input {j}\n\n```text\n{x["input"].rstrip()}\n```\n\nSample Output {j}\n\n```text\n{x["output"].rstrip()}\n```'
   (folder/'l3.txt').write_text(l3+'\n');record.update(status='rendered',l2_sha256=validate.sha(l2.encode()),l3_sha256=validate.sha((l3+'\n').encode()),samples=samples,original_sample_explanations='Replaced together with samples because logical mutation may invalidate their answers or explanations; original source retains them.')
  except Exception as e:record['error']=str(e)
  validate.write_json(folder/'mutation_edits.json',record);results.append(record)
 validate.write_json(BASE/'mutations/root_render_status.json',results)
 for x in results:
  if x['status']!='rendered':print(x['seed_id'],x.get('error'))
 print('rendered',sum(x['status']=='rendered'for x in results),'of',len(results))
if __name__=='__main__':main()
