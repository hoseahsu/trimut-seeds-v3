#!/usr/bin/env python3
"""Cache only public image URLs already cited in frozen Raw statements.

No statement is edited. Failed source URLs remain explicit failed entries; this
script never searches for replacements or redraws missing illustrations.
"""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
from urllib.parse import urlparse,unquote
from urllib.request import Request,urlopen
from datetime import datetime,timezone
import hashlib,json,re
R=Path(__file__).resolve().parents[1];D=R/'sources/original_illustrations';D.mkdir(parents=True,exist_ok=True)
INDEX=D/'index.json';LIMIT=10*1024**2
def sha(b):return hashlib.sha256(b).hexdigest()
def kind(b):
 if b.startswith(b'\x89PNG\r\n\x1a\n'):return 'image/png'
 if b.startswith(b'\xff\xd8\xff'):return 'image/jpeg'
 if b.startswith(b'BM'):return 'image/bmp'
 if b.startswith((b'GIF87a',b'GIF89a')):return 'image/gif'
 if b.startswith(b'RIFF')and b[8:12]==b'WEBP':return 'image/webp'
 return None
def main():
 previous={e['url']:e for e in json.loads(INDEX.read_text()).get('entries',[])}if INDEX.exists()else{}
 groups={};snapshot={}
 for p in sorted((R/'tasks').glob('TM*/raw.txt')):
  text=p.read_text();snapshot[str(p.relative_to(R))]=sha(p.read_bytes())
  for n,m in enumerate(re.finditer(r'!\[([^\]]*)\]\((https?://[^\s)]+)(?:\s+[^)]*)?\)',text),1):
   groups.setdefault(m[2],[]).append({'seed_id':p.parent.name,'occurrence':n,'alt_text':m[1],'raw_path':str(p.relative_to(R)),'raw_sha256':snapshot[str(p.relative_to(R))],'context':text[max(0,m.start()-250):min(len(text),m.end()+250)]})
 def fetch(pair):
  url,refs=pair;e={'url':url,'associated_seed_ids':sorted({q['seed_id']for q in refs}),'references':refs,'visual_review':{'status':'not_reviewed','reason':'download or file-header verification does not constitute visual review'}}
  old=previous.get(url,{})
  if old.get('status')=='downloaded'and(R/old['local_path']).exists()and sha((R/old['local_path']).read_bytes())==old.get('sha256'):
   old.update({'references':refs,'associated_seed_ids':e['associated_seed_ids']});return old
  try:
   parsed=urlparse(url)
   if parsed.scheme!='https'or parsed.hostname not in ('espresso.codeforces.com','judge.u-aizu.ac.jp'):raise ValueError('URL is not a currently reviewed original official image host')
   request=Request(url,headers={'User-Agent':'Original-statement-illustration-cache/1.0','Accept':'image/*'})
   with urlopen(request,timeout=25)as response:
    b=response.read(LIMIT+1);e.update({'http_status':response.status,'response_content_type':response.headers.get('Content-Type'),'final_url':response.geturl(),'last_modified':response.headers.get('Last-Modified'),'retrieved_at_utc':datetime.now(timezone.utc).isoformat()})
   if len(b)>LIMIT:raise ValueError('image exceeds explicit 10 MiB download limit')
   detected=kind(b)
   if not detected:raise ValueError('response is not a recognized PNG/JPEG/BMP/GIF/WebP image; no replacement downloaded')
   filename=sha(url.encode())[:16]+'_'+Path(unquote(parsed.path)).name;dest=D/filename;dest.write_bytes(b)
   e.update({'status':'downloaded','local_path':str(dest.relative_to(R)),'sha256':sha(b),'bytes':len(b),'detected_media_type':detected,'bytes_are_unmodified_source_response':True})
  except Exception as exc:e.update({'status':'unavailable','reason':repr(exc),'retrieved_at_utc':datetime.now(timezone.utc).isoformat()})
  return e
 with ThreadPoolExecutor(max_workers=4)as pool:entries=list(pool.map(fetch,groups.items()))
 unchanged=all(sha((R/p).read_bytes())==h for p,h in snapshot.items());assert unchanged,'Raw statement changed during this read/download operation'
 result={'schema':'trimut.strict.original_illustrations.v1','scope':'Only Markdown image URLs cited in tasks/*/raw.txt; no substitute images and no redrawing. Original Raw URLs and all four variant statements remain unedited.','raw_statements_scanned':len(snapshot),'raw_statement_hashes':snapshot,'url_count':len(entries),'occurrence_count':sum(len(v)for v in groups.values()),'associated_task_count':len({q['seed_id']for refs in groups.values()for q in refs}),'downloaded':sum(q['status']=='downloaded'for q in entries),'unavailable':sum(q['status']!='downloaded'for q in entries),'raw_statements_unchanged':unchanged,'entries':entries}
 INDEX.write_text(json.dumps(result,indent=2,ensure_ascii=False)+'\n');print(json.dumps({k:v for k,v in result.items()if k not in('entries','raw_statement_hashes','scope')}));print(json.dumps([{'url':e['url'],'reason':e.get('reason')}for e in entries if e['status']!='downloaded']))
if __name__=='__main__':main()
