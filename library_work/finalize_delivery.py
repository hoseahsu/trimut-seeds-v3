#!/usr/bin/env python3
"""Refresh delivery hashes after successful artifact audit; does not rerun programs."""
from pathlib import Path
import hashlib,json
R=Path(__file__).resolve().parents[1]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=R/'library_work/delivery_summary.json';d=json.loads(p.read_text());a=json.loads((R/'library_work/final_integrity_report.json').read_text());assert a['passed']==80
 d['totals']=a['totals'];d['max_l2_cpu_fraction']=a['max_l2_cpu_fraction'];d['max_l3_cpu_fraction']=a['max_l3_cpu_fraction']
 for v in d['evidence'].values():v['sha256']=sha(R/v['path'])
 for v in d['contracts']:
  c=json.loads((R/v['path']).read_text());assert c['strict_l2_l3_validation_complete'];v['sha256']=sha(R/v['path'])
 p.write_text(json.dumps(d,indent=2,ensure_ascii=False)+'\n');print(json.dumps({'path':str(p.relative_to(R)),'sha256':sha(p),'contracts':len(d['contracts'])}))
if __name__=='__main__':main()
