"""Full native contracts transcribed from original statements TM056..137.
L2 relaxes only the named upper bound and coupled aggregate bound. TM070 quarantined.
"""
from pathlib import Path
from collections import Counter
import json,re,random
from cc_b83 import Parse
ROWS=json.loads((Path(__file__).resolve().parents[1]/'contracts/cc165_native.json').read_text())
CAPS={int(x['seed_id'][2:]):(x['native_axes'][0]['upper_inclusive'],x['native_axes'][0]['proposed_l2_upper_inclusive'])for x in ROWS if int(x['seed_id'][2:])<=137}
AXES={int(x['seed_id'][2:]):x['native_axes'][0]['name']for x in ROWS}
AXES[120]='N_and_M'
def check(sid,text,condition='raw'):
 k=int(str(sid).removeprefix('TM'));assert 56<=k<=137 and k!=70,'quarantined';cap=CAPS[k][condition=='l2'];p=Parse(text);metric=0;low='abcdefghijklmnopqrstuvwxyz'
 def inc(v):
  nonlocal metric
  metric=max(metric,v);return v
 def vector(lo,hi,mn=1):n=inc(p.integer(mn,cap));return p.arr(n,lo,hi)
 def interval(n):l=p.integer(1,n);return l,p.integer(l,n)
 def perm(n):a=p.arr(n,1,n);assert len(set(a))==n;return a
 if k==56:n=inc(p.integer(2,cap));a=p.arr(n,1,10**8);assert len(set(a))==n;p.arr(n,-10**8,10**8)
 elif k==57:
  n=inc(p.integer(1,cap));p.integer(1,n)
  for _ in range(n):p.integer(1,10000);p.arr(2,0,1)
 elif k==58:
  n=inc(p.integer(1,cap));last=0
  for _ in range(n):last=p.integer(last+1,10**9);p.integer(1,10**9)
 elif k==59:
  n=p.integer(1,200000);z=p.integer(1,n);a=p.integer(2,10000);p.integer(1,a-1);q=inc(p.integer(1,cap));answered=0
  for _ in range(q):
   typ=p.integer(1,2)
   if typ==1:p.integer(1,n);p.integer(1,10000)
   else:p.integer(1,n-z+1);answered+=1
  assert answered>0,'at least one type2 query is guaranteed'
 elif k==60:
  n=inc(p.integer(1,cap));m=p.integer(0,n-1);a=p.arr(m,1,n-1);assert all(x<y for x,y in zip(a,a[1:]))
 elif k==61:n=inc(p.integer(1,cap));m=p.integer(1,50);p.arr(2*(n+m),-10**8,10**8)
 elif k==62:
  count=0
  while True:
   n=p.integer(0,cap)
   if not n:break
   inc(n);p.arr(n,1,10**6);count+=1
  assert 1<=count<=20
 elif k==63:
  for _ in range(p.integer(1,10)):n=inc(p.integer(1,cap));p.integer(0,n);p.arr(n,0,10**5)
 elif k==64:n=inc(p.integer(1,cap));q=p.integer(1,100000);p.arr(n+q,1,10**9)
 elif k==65:
  for _ in range(p.integer(1,100)):
   n=inc(p.integer(1,cap));m=p.integer(1,50000)
   for z in(n,m):a=p.arr(z,0,10**9);assert all(x>=y for x,y in zip(a,a[1:]))
 elif k==66:
  n=inc(p.integer(1,cap));p.arr(n,1,10**9)
  for _ in range(p.integer(1,100)):z=p.integer(1,n);p.integer(1,z)
 elif k==67:
  sn=sm=0
  for _ in range(p.integer(1,10000)):
   n=p.integer(1,cap);m=p.integer(1,200000);sn+=n;sm+=m;p.arr(n,-10**9,10**9);p.arr(m,1,10**9)
  assert sn<=cap and sm<=200000;metric=sn
 elif k==68:
  for _ in range(p.integer(1,200000)):p.integer(1,10**9);inc(p.integer(1,cap))
 elif k==69:metric=p.integer(1,cap)
 elif k==71:
  for _ in range(p.integer(1,999)):n=inc(p.integer(1,cap));p.integer(1,999);p.arr(n,0,99999)
 elif k==72:
  for _ in range(p.integer(1,10**6)):n=inc(p.integer(1,cap));p.integer(1,n)
 elif k==73:
  for _ in range(p.integer(1,10)):inc(len(p.word('47',1,cap)))
 elif k==74:n=inc(p.integer(1,cap));assert n%2;p.integer(1,10**9);p.arr(n,1,10**9)
 elif k==75:
  n=inc(p.integer(1,cap));m=p.integer(1,10**9);a=p.arr(n,0,m-1);b=p.arr(n,0,m-1)
  # Sorted cyclic-gap words characterize multiset translation. KMP avoids O(n^2) validator cost.
  a.sort();b.sort();da=[(a[(i+1)%n]-a[i])%m for i in range(n)];db=[(b[(i+1)%n]-b[i])%m for i in range(n)];pi=[0]*n
  for i in range(1,n):
   j=pi[i-1]
   while j and db[i]!=db[j]:j=pi[j-1]
   if db[i]==db[j]:j+=1
   pi[i]=j
  j=0;found=False
  for x in da+da[:-1]:
   while j and x!=db[j]:j=pi[j-1]
   if x==db[j]:j+=1
   if j==n:found=True;break
  assert found,'no multiset translation exists'
 elif k==76:
  sn=sm=0
  for _ in range(p.integer(1,10000)):
   n=p.integer(2,cap);m=p.integer(1,200000);sn+=n;sm+=m;s=p.word(low);assert len(s)==n;ps=p.arr(m,1,n-1);freq=Counter(ps);times=m+1;counts=Counter()
   for i,ch in enumerate(s):times-=freq[i];counts[ch]+=times
   assert max(counts.values())<=2*10**9,'original prefix count guarantee'
  assert sn<=cap and sm<=200000;metric=sn
 elif k==77:
  metric=sum(len(p.word(low,1,cap))for _ in range(p.integer(1,100000)));assert metric<=cap
 elif k in(78,100):
  for _ in range(p.integer(1,100 if k==78 else None)):n=inc(p.integer(1,cap));perm(n)
 elif k==79:
  n=inc(p.integer(2,cap));m=p.integer(2,10);a=p.arr(n,1,m);c=Counter(a);assert len(c)==m,'every genre appears';assert (n*n-sum(z*z for z in c.values()))//2<=2*10**9,'original different-genre count guarantee'
 elif k==80:
  n=p.integer(1,1500);s=p.word(low);assert len(s)==n;q=inc(p.integer(1,cap))
  for _ in range(q):p.integer(1,n);p.word(low,1,1)
 elif k==81:vector(1,200000,2)
 elif k in(82,90):metric=len(p.word('01'if k==82 else'+-',1,cap))
 elif k==83:
  n=inc(p.integer(1,cap));q=p.integer(1,200000);a=p.arr(n,1,2*10**9);assert all(x&(x-1)==0 for x in a);p.arr(q,1,10**9)
 elif k==84:n=inc(p.integer(2,cap));p.arr(2*n,0,2*10**9)
 elif k in(85,87,107,109,115,123):
  total=0
  for _ in range(p.integer(1,1000 if k in(107,115)else 10000)):
   n=p.integer(1,cap);total+=n
   if k==87:p.integer(1,10**9);p.arr(n,1,10**9);p.arr(n,1,2)
   else:
    a=p.arr(n,-10**9 if k in(85,109)else 1,10**9 if k in(85,109)else 2*n if k==123 else n)
    if k==109:assert all(a)
    if k==123:assert all(x<=y for x,y in zip(a,a[1:]))
  assert total<=cap;metric=total
 elif k==86:
  for _ in range(p.integer(1,1000)):inc(p.integer(0,cap));p.integer(0,10**9)
 elif k==88:n=inc(p.integer(2,cap));a=p.arr(n,0,1);assert sum(a)<=n//2
 elif k==89:vector(1,10**9)
 elif k==91:
  n=inc(p.integer(1,cap));m=p.integer(0,2000);p.arr(n,0,100000);edges=set()
  for _ in range(m):u=p.integer(1,n);v=p.integer(1,n);assert u!=v;edge=tuple(sorted((u,v)));assert edge not in edges;edges.add(edge)
 elif k==92:metric=p.integer(2,cap)
 elif k==93:p.arr(3,1,5000);metric=p.integer(1,cap);p.integer(1,100000)
 elif k==94:n=inc(p.integer(2,cap));p.integer(1,n-1);p.arr(n,1,999999999)
 elif k==95:
  for _ in range(p.integer(1,250)):n=inc(p.integer(1,cap));p.integer(0,n-1);p.arr(n,-10**9,10**9)
 elif k==96:
  n=inc(p.integer(1,cap));a=[p.word(low,1,30)for _ in range(n)];assert len(set(a))==n
 elif k==97:
  for _ in range(p.integer(1,10)):
   n=inc(p.integer(1,cap))
   for _ in range(n):p.word(None,1,100000)
 elif k==98:
  for _ in range(p.integer(1,100)):
   n=inc(p.integer(1,cap));p.integer(1,n);a=p.arr(n,0,2*10**9);assert len(set(a))==n
 elif k==99:n=inc(p.integer(1,cap));l=p.integer(0,n);p.integer(l,n)
 elif k==101:
  n=inc(p.integer(1,cap))
  for _ in range(n):p.word('ESC',1440,1440)
 elif k==102:vector(1,100000)
 elif k==103:
  n=inc(p.integer(1,cap));q=p.integer(1,200000);p.arr(n,1,10**6)
  for _ in range(q):interval(n)
 elif k==104:n=inc(p.integer(1,cap));p.integer(1,n);p.arr(n,1,1000)
 elif k==105:
  n=p.integer(1,100);metric=p.integer(1,cap);a=p.arr(n,1,metric);assert all(x<y for x,y in zip(a,a[1:]))
 elif k==106:
  n=inc(p.integer(3,cap));ds=list(range(n+1))
  def find(x):
   while ds[x]!=x:ds[x]=ds[ds[x]];x=ds[x]
   return x
  for _ in range(n-1):u=find(p.integer(1,n));v=find(p.integer(1,n));assert u!=v;ds[u]=v;p.integer(1,10**9)
  q=p.integer(1,100000);z=p.integer(1,n)
  for _ in range(q):u=p.integer(1,n);v=p.integer(1,n);assert len({u,v,z})==3
 elif k==108:n=inc(p.integer(2,cap));p.arr(2*n,1,10**9)
 elif k==110:
  total=0
  for _ in range(p.integer(1,20000)):
   n=inc(p.integer(1,cap));total+=n;assert n&(n-1)==0;s=p.word(low);assert len(s)==n
  assert total<=(400000 if condition=='l2'else 200000)
 elif k==111:
  sa=sb=sk=0
  for _ in range(p.integer(1,10000)):
   a=p.integer(1,200000);b=p.integer(1,200000);z=p.integer(1,cap);sa+=a;sb+=b;sk+=z;left=p.arr(z,1,a);right=p.arr(z,1,b);assert len(set(zip(left,right)))==z
  assert sa<=200000 and sb<=200000 and sk<=cap;metric=sk
 elif k==112:vector(1,200000)
 elif k==113:n=inc(p.integer(1,cap));p.integer(1,10**9);a=p.arr(n,-10**9,10**9);assert all(x<y for x,y in zip(a,a[1:]))
 elif k==114:
  n=p.integer(1,200000);p.arr(n,0,10**9);q=inc(p.integer(1,cap))
  for _ in range(q):
   z=p.integer(1,2)
   if z==1:p.integer(1,n)
   p.integer(0,10**9)
 elif k==116:
  metric=sum(len(p.word(low,1,cap))for _ in range(p.integer(1,10000)));assert metric<=cap
 elif k==117:p.word('BSC',1,100);p.arr(6,1,100);metric=p.integer(1,cap)
 elif k==118:vector(0,20000)
 elif k==119:
  n=inc(p.integer(1,cap));m=p.integer(1,2000);s=[p.word('01',m,m)for _ in range(n)];assert all(any(row[j]=='1'for row in s)for j in range(m))
 elif k==120:
  n=inc(p.integer(2,cap));m=p.integer(1,cap);edges=set();ds=list(range(n+1));components=n
  def find(x):
   while ds[x]!=x:ds[x]=ds[ds[x]];x=ds[x]
   return x
  for _ in range(m):
   u=p.integer(1,n-1);v=p.integer(u+1,n);assert(u,v)not in edges;edges.add((u,v));u=find(u);v=find(v)
   if u!=v:ds[u]=v;components-=1
  assert components==1,'the complete bridge set must connect all islands'
 elif k==121:
  n=inc(p.integer(1,cap))
  for _ in range(n):p.word(low,1,10)
  for _ in range(p.integer(1,100)):p.word(low,1,10)
 elif k==122:
  for _ in range(p.integer(1,100)):n=inc(p.integer(2,cap));m=p.integer(1,n-1);p.arr(n,1,100);a=p.arr(m,1,n-1);assert len(set(a))==m
 elif k==124:
  total=0
  for _ in range(p.integer(1,100)):
   n=p.integer(1,cap);total+=n
   for _ in range(n):l=p.integer(1,10**9);p.integer(l,10**9)
  assert total<=cap;metric=total
 elif k==125:
  for _ in range(p.integer(1,500)):n=inc(p.integer(1,cap));p.arr(2*n,0,1000)
 elif k==126:metric=p.integer(1,cap)
 elif k in(127,135):
  for _ in range(p.integer(1,10000 if k==127 else 100)):inc(p.integer(1,cap))
 elif k==128:n=inc(p.integer(1,cap));a=p.integer(1,10000);p.integer(1,a);p.arr(n,1,10000)
 elif k==129:
  n=inc(p.integer(1,cap));p.integer(1,10**9)
  for _ in range(n):a=p.integer(1,10**9);p.integer(a,10**9)
 elif k==130:
  n=inc(p.integer(1,cap));m=p.integer(1,1000)
  for _ in range(n):p.word('.*',m,m)
 elif k==131:
  n=inc(p.integer(2,cap));m=p.integer(0,n*n);edges=set()
  for _ in range(m):u=p.integer(0,n-1);v=p.integer(0,n-1);p.integer(0,1000);assert(u,v)not in edges;edges.add((u,v))
 elif k==132:n=inc(p.integer(1,cap));m=p.integer(1,1400);p.arr(n*m,0,1)
 elif k==133:
  for _ in range(p.integer(1,100)):n=inc(p.integer(1,cap));p.arr(2*n,1,100000)
 elif k==134:n=inc(p.integer(1,cap));p.integer(1,2000);p.integer(0,n-1)
 elif k==136:
  n=inc(p.integer(1,cap));c=Counter()
  for _ in range(n):s=p.word(low,1,32);c[s]+=p.integer(-1000,1000)
  assert max(c.values())>0
 elif k==137:n=inc(p.integer(1,cap));p.integer(1,n);p.arr(n,1,5000)
 else:raise KeyError(k)
 p.end();return {'axis':AXES[k],'observed':metric,'original_upper':CAPS[k][0],'l2_upper':CAPS[k][1],'outside_original':metric>CAPS[k][0]}
def validate(sid,text,condition='raw'):
 try:return {'valid':True,**check(sid,text,condition)}
 except(ValueError,IndexError,AssertionError)as e:return {'valid':False,'reason':str(e)}
def line(a):return ' '.join(map(str,a))+'\n'
def word(i):
 s=''
 while True:
  s+=chr(97+i%26);i//=26
  if not i:return s
def scale_case(sid,l2=False):
 k=int(str(sid).removeprefix('TM'));n=CAPS[k][l2]
 if k==56:return f'{n}\n'+line(range(1,n+1))+line([0]*n)
 if k==57:return f'{n} {n}\n'+'1 1 1\n'*n
 if k==58:return f'{n}\n'+''.join(f'{2*i+1} 1\n'for i in range(n))
 if k==59:return f'10 2 3 2 {n}\n'+'2 2\n'*n
 if k==60:return f'{n} 0\n'
 if k==61:return f'{n} 2\n'+'0 0\n'*n+'0 0\n10 0\n'
 if k==62:return f'{n}\n'+''.join(f'{x}\n'for x in range(n,0,-1))+'0\n'
 if k==63:return f'1\n{n} {n}\n'+line([7]*n)
 if k==64:return f'{n} 2\n'+line([1]*n)+'1\n2\n'
 if k==65:return f'1\n{n} 50\n'+line([1]*n)+line([1]*50)
 if k==66:return f'{n}\n'+line(range(1,n+1))+f'2\n1 1\n{n} {n}\n'
 if k==67:return f'1\n{n} 2\n'+line([1]*n)+f'{n} {n+1}\n'
 if k==68:return f'1\n1 {n}\n'
 if k==69:return f'{n}\n'
 if k==71:return f'1\n{n} 999\n'+line([1]*n)
 if k==72:return f'1\n{n} 3\n'
 if k==73:return '1\n'+'4'*n+'\n'
 if k==74:return f'{n} 2\n'+line([1]*n)
 if k==75:return f'{n} 1000000000\n'+line([0]*n)+line([999999999]*n)
 if k==76:return f'1\n{n} 1\n'+'a'*(n-1)+'b\n1\n'
 if k==77:return '1\n'+'a'*n+'\n'
 if k==78:return f'1\n{n}\n'+line(range(1,n+1))
 if k==79:return f'{n} 2\n'+line([1]*(n-1)+[2])
 if k==80:return f'3\naaa\n{n}\n'+'1 a\n'*n
 if k==81:return f'{n}\n'+line([7]*n)
 if k==82:return '0'*n+'\n'
 if k==83:return f'{n} 2\n'+line([1]*n)+f'{n}\n{n+1}\n'
 if k==84:return f'{n}\n'+line([7]*n)+line([7]*n)
 if k==85:return f'1\n{n}\n'+line([0]*n)
 if k==86:return f'1\n{n} 1000000000\n'
 if k==87:return f'1\n{n} {n}\n'+line([1]*n)+line([2]*n)
 if k==88:return f'{n}\n'+line([1]*(n//2)+[0]*(n-n//2))
 if k==89:return f'{n}\n'+line([1]*n)
 if k==90:return '+'*n+'\n'
 if k==91:return f'{n} 1\n'+line([1,2]+[1]*(n-2))+'1 2\n'
 if k==92:return f'{n}\n'
 if k==93:return f'3 5 1 {n} 1\n'
 if k==94:return f'{n} 2\n'+line(range(1,n+1))
 if k==95:return f'1\n{n} 1\n'+line([1]*n)
 if k==96:return f'{n}\n'+''.join(word(i)+'\n'for i in range(n))
 if k==97:return f'1\n{n}\n'+'alice\n'*(n-1)+'bob\n'
 if k==98:return f'1\n{n} 2\n'+line(range(n))
 if k==99:return f'{n} 0 0\n'
 if k==100:return f'1\n{n}\n'+line(range(1,n+1))
 if k==101:return f'{n}\n'+('C'*720+'S'*720+'\n')*n
 if k==102:return f'{n}\n'+line([2]*n)
 if k==103:return f'{n} 1\n'+line([1000000]*n)+f'1 {n}\n'
 if k==104:return f'{n} {n//2}\n'+line([1]*n)
 if k==105:return f'1 {n}\n1\n'
 if k==106:return f'{n}\n'+''.join(f'{i} {i+1} 1\n'for i in range(1,n))+f'1 1\n2 {n}\n'
 if k==107:return f'1\n{n}\n'+line([1]*n)
 if k==108:return f'{n}\n'+line([1]*n)+line([1]*n)
 if k==109:return f'1\n{n}\n'+line([1+i%2 for i in range(n)])
 if k==110:return f'1\n{n}\n'+'a'*n+'\n'
 if k==111:
  a=200000;b=2;left=[i//2+1 for i in range(n)];right=[i%2+1 for i in range(n)];return f'1\n{a} {b} {n}\n'+line(left)+line(right)
 if k==112:return f'{n}\n'+line([200000]*n)
 if k==113:return f'{n} 2\n'+line(range(n))
 if k==114:return f'2\n0 10\n{n}\n'+'2 5\n'*n
 if k==115:return f'1\n{n}\n'+line([1]*n)
 if k==116:return '1\n'+'a'*(n-1)+'b\n'
 if k==117:return f'BSC\n1 1 1\n1 1 1\n{n}\n'
 if k==118:return f'{n}\n'+line([2]*(n//2)+[0]*(n-n//2))
 if k==119:return f'{n} 1\n'+'1\n'*n
 if k==120:return f'{n} {n-1}\n'+''.join(f'{i} {i+1}\n'for i in range(1,n))
 if k==121:return f'{n}\n'+'a\n'*n+'1\nb\n'
 if k==122:return f'1\n{n} 1\n'+line([1]*(n-1)+[2])+'1\n'
 if k==123:return f'1\n{n}\n'+line([1]*n)
 if k==124:return f'1\n{n}\n'+'1 2\n'*n
 if k==125:return f'1\n{n}\n'+'1 0\n'*n
 if k==126:return f'{n}\n'
 if k==127:return f'1\n{n}\n'
 if k==128:return f'{n} 1 1\n'+line([1]*n)
 if k==129:return f'{n} 1000000000\n'+'1 1\n'*n
 if k==130:return f'{n} 1000\n'+('*'*1000+'\n')*n
 if k==131:return f'{n} {n*(n-1)}\n'+''.join(f'{u} {v} 1\n'for u in range(n)for v in range(n)if u!=v)
 if k==132:return f'{n} 1400\n'+(' '.join(['0']*1400)+'\n')*n
 if k==133:return f'1\n{n}\n'+line([1]*(2*n))
 if k==134:return f'{n} 2 {n-1}\n'
 if k==135:return f'1\n{n}\n'
 if k==136:return f'{n}\n'+'alice 1\n'*(n-1)+'bob 1\n'
 if k==137:return f'{n} 1\n'+line([7]*n)
 raise KeyError(k)
if __name__=='__main__':
 for k in CAPS:
  if k==70:continue
  for expanded in(False,True):
   s=scale_case(k,expanded);v=validate(k,s,'l2'if expanded else'raw');assert v['valid'],(k,expanded,v);assert v['outside_original']==expanded,(k,v)
 print('All 162 scale cases pass original/expanded contracts.')
