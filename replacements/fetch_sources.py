#!/usr/bin/env python3
from pathlib import Path
import urllib.request,re,hashlib,json
from html.parser import HTMLParser
from html import unescape
ROOT=Path(__file__).resolve().parents[1]
class Render(HTMLParser):
 def __init__(self): super().__init__();self.out=[];self.pre=False;self.var=False
 def handle_starttag(self,t,a):
  if t=='h3':self.out.append('\n\n## ')
  if t=='p':self.out.append('\n\n')
  if t=='li':self.out.append('\n- ')
  if t=='pre':self.out.append('\n\n```\n');self.pre=True
  if t=='var' and not self.pre:self.out.append('$')
  if t=='br':self.out.append('\n')
 def handle_endtag(self,t):
  if t=='h3':self.out.append('\n\n')
  if t=='p':self.out.append('\n\n')
  if t=='li':self.out.append('\n')
  if t=='pre':self.out.append('\n```\n');self.pre=False
  if t=='var' and not self.pre:self.out.append('$')
 def handle_data(self,s):self.out.append(s)

def atcoder(pid,sid,title):
 url=f'https://atcoder.jp/contests/{pid.split("_")[0]}/tasks/{pid}?lang=en'
 folder=ROOT/'sources'/'replacement_official'/pid;folder.mkdir(parents=True,exist_ok=True)
 html=urllib.request.urlopen(url,timeout=30).read();(folder/'official_page.html').write_bytes(html)
 text=html.decode().replace('\r\n','\n').replace('\r','\n');en=text.split('<span class="lang-en">',1)[1].split('</span>',1)[0]
 en=en[en.index('<div class="part">'):]
 r=Render();r.feed(en);raw='# '+title+'\n'+''.join(r.out)
 raw=re.sub(r'\n[ \t]*\n(?:[ \t]*\n)+','\n\n',raw).strip()+'\n'
 (folder/'original_statement.md').write_text(raw)
 samples=[]
 for m in re.finditer(r'<h3>Sample Input (\d+)</h3><pre>([\s\S]*?)</pre>',en):
  k=m.group(1);o=re.search(r'<h3>Sample Output '+k+r'</h3><pre>([\s\S]*?)</pre>',en)
  samples.append({'name':'sample_'+k,'input':unescape(m.group(2)),'output':unescape(o.group(1))})
 source={'source_identity':'atcoder:'+pid,'source_dataset':'AtCoder official','source_problem_id':pid,'source_url':url,'original_statement':str((folder/'original_statement.md').relative_to(ROOT)),'source_package':str(folder.relative_to(ROOT)),'source_tests':str((folder/'source_tests.json').relative_to(ROOT)),'title':title,'statement_sha256':hashlib.sha256(raw.encode()).hexdigest(),'native_budget_seconds':2,'source_reference':None,'license_note':'AtCoder publisher copyright retained; local research source snapshot; no blanket redistribution licence asserted.'}
 (folder/'source_tests.json').write_text(json.dumps({'public_tests':{'input':[x['input']for x in samples],'output':[x['output']for x in samples]},'private_tests':{'input':[],'output':[]},'generated_tests':{'input':[],'output':[]}},indent=2)+'\n')
 (folder/'source_metadata.json').write_text(json.dumps({'source':source,'retrieval_method':'urllib official HTTPS','page_sha256':hashlib.sha256(html).hexdigest(),'render_policy':'Original English language block; HTML headings, var and pre tags rendered as Markdown with LF line endings; all narrative, constraints, sample I/O and explanations retained.'},indent=2)+'\n')
 write_raw(sid,raw,source,'official_html_rendered_without_semantic_change')
 return source

def write_raw(sid,raw,source,status):
 p=ROOT/'tasks'/sid;p.mkdir(parents=True,exist_ok=True)
 # Retain old quarantined candidate material as a recoverable audit record.
 if (p/'raw.txt').exists() and not(p/'quarantined_previous_raw.txt').exists():(p/'quarantined_previous_raw.txt').write_bytes((p/'raw.txt').read_bytes())
 if (p/'raw_provenance.json').exists() and not(p/'quarantined_previous_provenance.json').exists():(p/'quarantined_previous_provenance.json').write_bytes((p/'raw_provenance.json').read_bytes())
 (p/'raw.txt').write_text(raw)
 (p/'raw_provenance.json').write_text(json.dumps({'seed_id':sid,'source_identity':source['source_identity'],'source_snapshot':source['original_statement'],'source_snapshot_sha256':source['statement_sha256'],'raw_path':str((p/'raw.txt').relative_to(ROOT)),'raw_sha256':source['statement_sha256'],'official_url':source['source_url'],'raw_ready_for_l1':True,'status':status,'operations':['Rendered source typography as Markdown; no change to mathematical content, constraints, examples, explanations or original narrative.']},ensure_ascii=False,indent=2)+'\n')

if __name__=='__main__':
 sources={}
 sources['TM025']=atcoder('abc145_c','TM025','C - Average Length')
 sources['TM149']=atcoder('abc087_b','TM149','B - Coins')
 (ROOT/'replacements'/'atcoder_sources.json').write_text(json.dumps(sources,ensure_ascii=False,indent=2)+'\n')
 print('AtCoder official originals saved',list(sources))
