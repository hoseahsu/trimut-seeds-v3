"""Extract the original sample bytes from full, faithfully restored Raw text.
Blank framing and code fences are not part of stdin/stdout. Malformed source
test snapshots are not silently repaired; this uses the independently retained
statement sample sections and records that provenance.
"""
import re
def marker(raw):
 m=re.search(r'(?im)^(?:Examples?|Sample Input(?: \d+)?)\s*$|SAMPLE INPUT',raw)
 assert m,'No original sample boundary'
 return m
def clean(s):
 s=re.sub(r'(?m)^```(?:text)?\s*$','',s)
 return s.strip()+'\n'
def extract(raw):
 tail=raw[marker(raw).start():]
 heads=list(re.finditer(r'(?mi)(?:Sample Input \d+|SAMPLE INPUT|^\s*Input:?[ \t]*$)|(?:Sample Output \d+|SAMPLE OUTPUT|^\s*Output:?[ \t]*$)',tail))
 result=[]
 for j,h in enumerate(heads):
  if 'input'not in h.group().lower():continue
  assert j+1<len(heads)and'output'in heads[j+1].group().lower()
  o=heads[j+1];end=heads[j+2].start()if j+2<len(heads)else len(tail)
  out=tail[o.end():end]
  out=re.split(r'(?mi)^\s*(?:Note\b|Explanation\b|Explanations\b|Definitions\b|Constraints\b|Warning\b|For example\b|It is possible\b)|(?<=\d)Explanation',out)[0]
  result.append({'input':clean(tail[h.end():o.start()]),'output':clean(out)})
 assert result
 return result
def statement_body(raw,k):
 cut=marker(raw).start();s=raw[:cut].rstrip();removed=[]
 if k==181:
  a=s.index('Examples explained');b=s.index('\ninput\n',a);old=s[a:b];s=s[:a]+s[b:];removed.append({'before':old,'after':'','reason':'The original common-substring illustration does not define common subsequences.'})
 if k==200:
  a=s.index("Let's look at an example.");b=s.index('For each cell from 1 to n',a);old=s[a:b];s=s[:a]+s[b:];removed.append({'before':old,'after':'','reason':'The inline numerical minimum illustration is superseded by recomputed maximum samples.'})
 if k==172:s+='\n\n'+raw[raw.index('Definitions\n',cut):]
 if k==205:s+='\n\n'+raw[raw.index('Note:\n',cut):]
 if k==190:s+='\n\n'+raw[raw.index('Warning:',cut):]
 return s,removed
