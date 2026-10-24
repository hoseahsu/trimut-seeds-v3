"""Executable release profiles for the four cc_b recipe modules.
Metric extraction is called only after complete grammatical/domain validation.
Missing metric keys fail closed. It never runs submitted code.
"""
def metrics(batch,t,text):
 tok=text.split();p=0;out={}
 def w():
  nonlocal p
  v=tok[p];p+=1;return v
 def n():return int(w())
 def skip(k):
  nonlocal p
  p+=k
 def setv(**kw):
  for k,v in kw.items():out[k]=max(out.get(k,0),v)
 def vector(key='n'):
  v=n();setv(**{key:v});skip(v);return v
 if batch==2:
  if t in(1,5,11,14):setv(n=int(tok[0]))
  elif t in(3,10):setv(n=int(tok[0]))
  elif t==2:
   q=n();setv(t=q)
   for _ in range(q):vector()
  elif t==4:setv(summands=text.count('+')+1,expression_characters=len(text.strip()))
  elif t==6:setv(n=n(),m=n())
  elif t==7:setv(commands=len(text.splitlines()),line_characters=max(map(len,text.splitlines())))
  elif t==8:setv(n=n(),k=n())
  elif t==9:setv(n=n(),m=n())
  elif t==12:setv(n=n(),q=n())
  elif t==13:a=w();setv(N=int(a),decimal_digits=len(a),k=n())
  elif t==15:
   q=n();setv(t=q)
   for _ in range(q):v=n();k=n();setv(n=v);skip(v)
 elif batch==3:
  if t==1:setv(h=n(),w=n())
  elif t in(2,3,5,6,8,14,15,18):setv(n=n())
  elif t==4:
   q=n();total=0;setv(t=q)
   for _ in range(q):v=n();k=n();d=n();setv(n=v,k=k);total+=v;skip(v)
   setv(total_n=total)
  elif t==7:setv(a=n(),b=n(),c=n())
  elif t in(9,13):setv(n=n(),m=n())
  elif t==10:setv(n=n())
  elif t==11:vector();setv(q=n())
  elif t==12:setv(n=n(),k=n())
  elif t==16:vector();vector('m')
  elif t==17:
   v=n();setv(n=v);setv(coordinate=max(int(x)for x in tok[p:]))
  elif t==19:setv(n=n(),m=n())
  elif t==20:setv(n=len(w()))
 elif batch==4:
  if t in(1,6,7,11,13,14):setv(n=n())
  elif t==2:
   q=n();setv(t=q)
   for _ in range(q):v=n();setv(n=v,k=n());skip(v)
  elif t==3:setv(n=n(),k=n(),q=n())
  elif t==4:setv(n=n(),q=n())
  elif t in(5,8):setv(h=n(),w=n())
  elif t==9:setv(length=max(map(len,tok)),datasets=len(tok)//2)
  elif t==10:vector();vector('m')
  elif t==12:q=n();setv(t=q,p=max(map(int,tok[p:])))
  elif t==15:
   q=n();setv(q=q)
   for _ in range(q):vector()
  elif t==16:setv(a=n(),b=n(),c=n())
  elif t==17:setv(n=n(),m=n())
  elif t==18:
   q=n();setv(t=q)
   for _ in range(q):l=n();r=n();setv(r=r,width=r-l)
  elif t==19:
   q=n();setv(t=q)
   for _ in range(q):
    v=n();k=n();setv(n=v,k=k);skip(v)
    for _ in range(k):size=n();setv(l=size);skip(size)
  elif t==20:setv(y=n(),k=n(),n=n())
 elif batch==5:
  if t in(1,3,7,16,23,25):setv(n=n())
  elif t==2:setv(length=len(w()))
  elif t==4:
   q=n();setv(t=q)
   for _ in range(q):setv(L=n());skip(3)
  elif t in(5,13,14):
   q=n();total=0;setv(t=q)
   for _ in range(q):v=n();total+=v;setv(n=v);skip(1 if t==13 else 2 if t==14 else 0);skip(v)
   setv(total_n=total)
  elif t==6:
   q=n();setv(t=q)
   for _ in range(q):setv(p=len(w()),h=len(w()))
  elif t==8:
   q=n();total=0;setv(t=q)
   for _ in range(q):v=n();k=n();total+=v;setv(n=v);skip(2*k)
   setv(total_n=total)
  elif t in(9,21):vector();setv(q=n())
  elif t==10:setv(length=len(w()))
  elif t==11:setv(n=n(),k=n())
  elif t==12:
   v=n();setv(n=v)
   for _ in range(v):a=n();b=n();setv(a=a,b=b,value=max(a,b))
  elif t==15:
   v=n();m=n();setv(n=v,m=m);skip(2*m);setv(q=n())
  elif t==17:
   v=n();m=n();setv(n=v,m=m);skip(2*m);setv(q=n())
  elif t in(18,20,24):setv(n=n(),q=n())
  elif t==19:setv(n=n(),m=n(),k=n())
  elif t==22:setv(n=n())
  elif t==26:setv(n=n(),value=max(map(int,tok[1:])))
  elif t==27:
   q=n();setv(t=q);lens=[len(w())for _ in range(q)];setv(length=max(lens),total_length=sum(lens))
  elif t==28:setv(n=n())
 else:raise ValueError('Unknown batch')
 return out

def bind(namespace,batch):
 import json
 from pathlib import Path
 statements=json.loads((Path(__file__).parent/'cc_b_statements.json').read_text())
 recipes=namespace['RECIPES'];infos=namespace['INFO'];base=namespace['validate_input'];tasks={row[0]:i for i,row in enumerate(infos,1)}
 def validate_version_input(id,text,condition):
  if condition=='source_original':return base(id,text,'raw')
  if condition not in('raw','weak','l2','l3'):return False
  if id not in tasks or not base(id,text,'l2'if condition=='l2'else'raw'):return False
  try:
   if id=='codenet_p02260'and any(abs(int(x))>10**9 for x in text.split()[1:]):return False
   if id=='atcoder_abc154_e'and text.split()[0].startswith('0'):return False
   observed=metrics(batch,tasks[id],text);limits=recipes[id]['strong_bounds'if condition=='l2'else'weak_bounds']
   return all(k in observed and observed[k]<=v for k,v in limits.items())
  except(ValueError,IndexError,TypeError):return False
 namespace['validate_version_input']=validate_version_input
 for id,cfg in recipes.items():
  item=statements[id]
  cfg['canonical_statement_raw']=item['template'].format(rule=item['raw_rule'])+'\n\n'+item['input_output']
  cfg['canonical_statement_l3']=item['template'].format(rule=item['l3_rule'])+'\n\n'+item['input_output']
  cfg['canonical_input_output']=item['input_output']
  cfg['invariant_constraints']=item['invariant_constraints']
  cfg['canonical_statement_raw']+='\n\nInvariant constraints: '+item['invariant_constraints']
  cfg['canonical_statement_l3']+='\n\nInvariant constraints: '+item['invariant_constraints']
  cfg['release_validator']='validate_version_input'
  cfg['canonical_statement_note']='Self-contained rules and IO; append the applicable weak/strong bounds and invariant domain constraints.'
