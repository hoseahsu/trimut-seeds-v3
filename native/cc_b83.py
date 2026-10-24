"""Exact native input contracts for TM138..220; L2 only relaxes declared caps.
Every native input remains admitted by L2. No public program is executed here.
TM149 is quarantined for source ambiguity and is not admitted by this module.
"""
from pathlib import Path
import json,re,random,sys
sys.set_int_max_str_digits(0)
ROWS=json.loads((Path(__file__).resolve().parents[1]/'contracts/cc165_native.json').read_text())
CAPS={int(x['seed_id'][2:]):(x['native_axes'][0]['upper_inclusive'],x['native_axes'][0]['proposed_l2_upper_inclusive'])for x in ROWS if int(x['seed_id'][2:])>=138}
AXES={int(x['seed_id'][2:]):x['native_axes'][0]['name']for x in ROWS}
class Parse:
 def __init__(self,s):self.v=s.split();self.i=0
 def token(self):assert self.i<len(self.v),'unexpected end';x=self.v[self.i];self.i+=1;return x
 def integer(self,lo=None,hi=None):
  s=self.token();assert re.fullmatch(r'-?\d+',s,flags=re.ASCII),'noninteger token';x=int(s);assert lo is None or x>=lo,(x,'<',lo);assert hi is None or x<=hi,(x,'>',hi);return x
 def arr(self,n,lo=None,hi=None):return[self.integer(lo,hi)for _ in range(n)]
 def word(self,chars=None,lo=1,hi=None):
  s=self.token();assert lo<=len(s)and(hi is None or len(s)<=hi),'length';assert chars is None or set(s)<=set(chars),'alphabet';return s
 def end(self):assert self.i==len(self.v),'trailing tokens'
def check(sid,text,condition='raw'):
 k=int(str(sid).removeprefix('TM'));assert 138<=k<=220 and k!=149,'quarantined source';cap=CAPS[k][condition=='l2'];p=Parse(text);metric=0;low='abcdefghijklmnopqrstuvwxyz';up=low.upper()
 def inc(v):
  nonlocal metric
  metric=max(metric,v);return v
 def vector(lo,hi,mn=1):
  n=inc(p.integer(mn,cap));p.arr(n,lo,hi);return n
 def interval(n):l=p.integer(1,n);r=p.integer(l,n);return l,r
 if k==138:vector(None,None)
 elif k==139:
  for _ in range(p.integer(1,10)):vector(1,10**6)
 elif k in (140,147,154,158):
  n=inc(p.integer(2 if k in(140,147,158)else 1,cap))
  if k==154:p.integer(1,n)
  s=p.word(up if k==147 else'HT'if k==158 else low);assert len(s)==n
  if k==158:assert set(s)==set('HT')
 elif k==141:
  s=p.word(None,1,cap);assert re.fullmatch(r'[123](\+[123])*',s);metric=len(s)
 elif k==142:
  n=inc(p.integer(1,cap));assert all(x in(100,200)for x in p.arr(n))
 elif k==143:
  n=p.integer(2,500);m=inc(p.integer(1,cap));p.arr(n,1,100);p.arr(m,1,n)
 elif k==144:
  lines=text.splitlines();assert 0<=len(lines)<=cap;active=set()
  for line in lines:
   assert 0<len(line)<=100
   if line[0]in'+-':
    name=line[1:];assert re.fullmatch('[A-Za-z0-9]+',name)
    if line[0]=='+':assert name not in active;active.add(name)
    else:assert name in active;active.remove(name)
   else:
    name,msg=line.split(':',1);assert name in active and re.fullmatch('[A-Za-z0-9]+',name);assert re.fullmatch('[A-Za-z0-9 ]*',msg)and msg==msg.strip()
  metric=len(lines);p.i=len(p.v)
 elif k==145:
  n=inc(p.integer(1,cap));p.integer(1,min(2*10**9,n*(n+1)//2));a=p.arr(n,1,10**9);assert len(set(a))==n
 elif k==146:
  n=inc(p.integer(1,cap));m=p.integer(1,10**6);a=p.arr(n,1,n);assert len(set(a))==n;p.arr(2*m,1,n)
 elif k==148:vector(1,1000)
 elif k==150:
  s=p.word('0123456789',1,cap);assert s[0]!='0';p.integer(1,3);metric=len(s)
 elif k==151:
  n=inc(p.integer(2,cap));a=p.arr(n,1,n);assert len(set(a))==n;p.arr(n,1,50);p.arr(n-1,1,50)
 elif k==152:
  for _ in range(p.integer(1,10)):
   n=inc(p.integer(2,cap));p.integer(1,n-1);a=p.arr(n,1,10**9);assert all(x<y for x,y in zip(a,a[1:]))
 elif k in(153,177,180):
  h=inc(p.integer(1,cap));w=p.integer(1,{153:1400,177:100,180:50}[k])
  if k==153:p.arr(h*w,0,1)
  else:
   grid=[p.word(low if k==177 else'.#')for _ in range(h)];assert all(len(row)==w for row in grid)
   if k==177:
    from collections import Counter
    rc=[Counter(row)for row in grid];cc=[Counter(grid[i][j]for i in range(h))for j in range(w)]
    assert any(rc[i][grid[i][j]]==cc[j][grid[i][j]]==1 for i in range(h)for j in range(w)),'original guarantees at least one retained letter'
 elif k==155:
  n=inc(p.integer(1,cap));m=p.integer(1,n);z=p.integer(1,n);a=p.arr(n,1,n);assert len(set(a))==n;s=p.arr(n,1,m);assert len(set(s))==m;c=p.arr(z,1,n);assert len(set(c))==z
 elif k==156:
  total=0
  for _ in range(p.integer(1,100)):
   n=p.integer(1,cap);total+=n;v=p.integer(1,100);p.integer(1,n);p.arr(n,1,v)
  assert total<=cap;metric=total
 elif k==157:
  n=inc(p.integer(1,cap));p.integer(1,n);p.arr(2*n,1,50)
 elif k==159:p.arr(2,1,100);metric=p.integer(1,cap)
 elif k==160:vector(1,10**6,2)
 elif k==161:
  n=inc(p.integer(1,cap));m=p.integer(1,2000);p.arr(n+m,1,100000)
 elif k==162:
  n=inc(p.integer(1,cap));p.integer(2,10**9);p.arr(n,1,10**9)
 elif k==163:
  n=p.integer(1,100000);p.arr(n,1,100000);q=inc(p.integer(1,cap))
  for _ in range(q):assert p.integer(1,100000)!=p.integer(1,100000),'B_i equals C_i'
 elif k==164:
  n=p.integer(1,100);metric=p.integer(0,cap);p.arr(n,0,metric)
 elif k==165:
  n=inc(p.integer(1,cap));m=p.integer(1,100000);p.arr(n+m,1,10**9)
 elif k==166:
  n=inc(p.integer(1,cap));p.arr(2*n,1,10**6)
 elif k==167:vector(1,100000)
 elif k==168:
  n=inc(p.integer(1,cap));p.arr(n,1,100);m=p.integer(1,100);p.arr(m,1,100)
 elif k==169:
  n=inc(p.integer(1,cap))
  for _ in range(n):l=p.integer(0,10**18);p.integer(l,10**18)
 elif k==170:
  n=inc(p.integer(1,cap));assert all(x!=0 for x in p.arr(n,-10**9,10**9))
 elif k==171:
  n=p.integer(1,100);m=inc(p.integer(1,cap));p.arr(n,-100,100)
  for _ in range(m):interval(n)
 elif k==172:metric=len(p.word('ab',1,cap))
 elif k==173:
  n=inc(p.integer(1,cap));p.arr(2*n,0,n-1)
 elif k==174:
  total=0
  for _ in range(p.integer(1,100)):
   n=p.integer(1,cap);total+=n;p.integer(1,10**18);p.arr(n,-10**9,10**9)
  assert total<=cap;metric=total
 elif k==175:
  n=p.integer(1,150000);p.integer(1,min(6,n));q=inc(p.integer(1,cap));a=p.arr(n,1,10**9);assert len(set(a))==n;online=set();asked=0
  for _ in range(q):
   kind=p.integer(1,2);x=p.integer(1,n)
   if kind==1:assert x not in online;online.add(x)
   else:asked+=1
  assert asked
 elif k==176:
  n=inc(p.integer(1,cap));q=p.integer(1,100000);last=0
  for _ in range(q):last=p.integer(last+1,10**6);p.integer(1,n);p.integer(1,1000)
 elif k==178:vector(1,10**9)
 elif k==179:vector(0,2**60-1,2)
 elif k==181:
  cnt=0
  while p.i<len(p.v):a=p.word(up,1,cap);b=p.word(up,1,cap);inc(max(len(a),len(b)));cnt+=1
  assert cnt<=10
 elif k==182:
  n=inc(p.integer(1,cap));a=p.arr(n,1,10000);m=p.integer(1,50);b=p.arr(m,1,10000);assert all(x<y for x,y in zip(a,a[1:]))and all(x<y for x,y in zip(b,b[1:]));assert any(y%x==0 for x in a for y in b)
 elif k==183:
  n=inc(p.integer(1,cap))
  for _ in range(n):p.word(low,1,10)
 elif k==184:
  for _ in range(p.integer(1,5)):inc(p.integer(1,cap))
 elif k==185:vector(1,180)
 elif k==186:
  n=inc(p.integer(2,cap));p.arr(2*(n-1),0,3)
 elif k==187:
  for _ in range(p.integer(1,200)):
   n=inc(p.integer(1,cap));a=p.arr(n,1,n);assert len(set(a))==n
 elif k==188:a=p.integer(1,10000);p.integer(a,10000);metric=p.integer(1,cap)
 elif k==189:
  n=inc(p.integer(1,cap));m=p.integer(1,10)
  for _ in range(m):a=p.arr(p.integer(1,n),1,n);assert len(set(a))==len(a)
  p.arr(m,0,1)
 elif k==190:
  for _ in range(p.integer(1,10)):l=p.integer(1,10**9);r=p.integer(l,min(10**9,l+cap));inc(r-l)
 elif k==191:
  for _ in range(p.integer(1,20)):
   n=inc(p.integer(1,cap));z=p.integer(1,50)
   for _ in range(n):p.word(None,1,5)
   for _ in range(z):
    for _ in range(p.integer(1,50)):p.word(None,1,5)
 elif k==192:
  y=p.integer(1,10**9);v=p.integer(1,10**9);n=p.integer(1,10**9);assert n<=v*cap;metric=n/v
 elif k==193:vector(0,1)
 elif k==194:a=p.word(low,2,cap);b=p.word(low,2,cap);assert len(a)==len(b);metric=len(a)
 elif k==195:n=inc(p.integer(1,cap));p.arr(2*n,1,100)
 elif k==196:
  for _ in range(p.integer(1,10000)):n=inc(p.integer(1,cap));p.integer(1,10**9);interval(n)
 elif k in(197,206):
  total=0
  for _ in range(p.integer(1,10000)):
   n=p.integer(1,cap);total+=n
   if k==206:l=p.integer(1,10**9);p.integer(l,10**9)
   p.arr(n,1,10**6 if k==197 else 10**9)
  assert total<=cap;metric=total
 elif k==198:
  for _ in range(p.integer(1,100)):p.word(low,1,100);inc(len(p.word(low,1,cap)))
 elif k==199:vector(1,400000)
 elif k==200:
  total=0
  for _ in range(p.integer(1,10000)):
   n=p.integer(1,cap);total+=n;z=p.integer(1,n);a=p.arr(z,1,n);assert len(set(a))==z;p.arr(z,1,10**9)
  assert total<=cap;metric=total
 elif k==201:
  n=p.integer(1,100000);p.arr(n,0,10**6);q=inc(p.integer(1,cap))
  for _ in range(q):
   kind=p.integer(1,2);interval(n)
   if kind==2:p.integer(1,10**6)
 elif k==202:metric=len(p.word('()',1,cap))
 elif k==203:n=p.integer(1,1000);metric=p.integer(1,cap);p.arr(2*n,1,1000)
 elif k==204:
  n=inc(p.integer(1,cap))
  for _ in range(n):p.integer(0,10**9);p.integer(1,10**9)
 elif k==205:
  total=0
  for _ in range(p.integer(1,100000)):n=inc(p.integer(1,cap));total+=n;p.integer(1,100000);p.arr(n,1,100000)
  assert total<=500000
 elif k==207:
  n=inc(p.integer(1,cap));m=p.integer(1,1000000)
  for _ in range(m):interval(n)
  q=p.integer(1,1000000);p.arr(q,1,n)
 elif k==208:vector(1,100)
 elif k==209:
  n=p.integer(2,100000);m=p.integer(0,100000);p.arr(2*m,0,n-1);q=inc(p.integer(1,cap));p.arr(2*q,0,n-1)
 elif k==210:
  n=p.integer(1,200000);q=inc(p.integer(1,cap));assert all(x in(-1,1)for x in p.arr(n))
  for _ in range(q):interval(n)
 elif k==211:n=inc(p.integer(1,cap));m=p.integer(1,n);p.integer(1,n//m);p.arr(n,0,10**9)
 elif k==212:
  n=p.integer(1,300000);q=inc(p.integer(1,cap));made=0
  for _ in range(q):
   kind=p.integer(1,3);p.integer(1,made if kind==3 else n);made+=kind==1
 elif k==213:
  n=inc(p.integer(1,cap));a=p.arr(n,1,n);assert len(set(a))==n;q=p.integer(1,200000)
  for _ in range(q):interval(n)
 elif k==214:
  n=inc(p.integer(2,cap))
  for _ in range(n):
   s=p.token();assert re.fullmatch(r'\d+(\.\d{1,9})?',s,flags=re.ASCII);parts=s.split('.');x=int(parts[0])*10**9+(int(parts[1].ljust(9,'0'))if len(parts)==2 else 0);assert 0<x<10000*10**9
 elif k==215:metric=p.integer(0,cap)
 elif k==216:
  n=p.integer(1,1000);q=inc(p.integer(1,cap))
  for _ in range(q):
   s=p.token();assert s in('CLICK','CLOSEALL')
   if s=='CLICK':p.integer(1,n)
 elif k==217:n=inc(p.integer(2,cap));p.arr(2*n,1,1000)
 elif k==218:vector(1,10**9,2)
 elif k==219:
  total=0
  for _ in range(p.integer(1,100000)):s=p.word(low,1,cap);total+=len(s);inc(len(s))
  assert total<=1000000
 elif k==220:n=inc(p.integer(3,cap));x=p.integer(1,n-2);p.integer(x+2,n)
 else:raise KeyError(k)
 p.end();return {'axis':AXES[k],'observed':metric,'original_upper':CAPS[k][0],'l2_upper':CAPS[k][1],'outside_original':metric>CAPS[k][0]}
def validate(sid,text,condition='raw'):
 try:return {'valid':True,**check(sid,text,condition)}
 except(ValueError,IndexError,AssertionError)as e:return {'valid':False,'reason':str(e)}
def line(v):return ' '.join(map(str,v))+'\n'
def scale_case(sid,l2=False):
 k=int(str(sid).removeprefix('TM'));n=CAPS[k][l2];R=random.Random(314159+k);a=lambda z,lo,hi:[R.randint(lo,hi)for _ in range(z)]
 if k==138:return f'{n}\n'+line(a(n,-1000000,1000000))
 if k==139:return f'1\n{n}\n'+line(a(n,1,10**6))
 if k in(140,147):return f'{n}\n'+('azba'if k==140 else'AZBA')*(n//4)+('azba'if k==140 else'AZBA')[:n%4]+'\n'
 if k==141:return '+'.join(str(1+i%3)for i in range((n+1)//2))+'\n'
 if k==142:return f'{n}\n'+line([100 if i%3 else 200 for i in range(n)])
 if k==143:return f'500 {n}\n'+line(a(500,1,100))+line([i%500+1 for i in range(n)])
 if k==144:return '+user\n'+('user:a b c\n'*(n-1))
 if k==145:return f'{n} {min(2*10**9,n*(n+1)//2)}\n'+line(range(1,n+1))
 if k==146:return f'{n} 1000000\n'+line(range(n,0,-1))+''.join(f'{i%n+1} {(i+1)%n+1}\n'for i in range(1000000))
 if k==148:return f'{n}\n'+line(a(n,1,1000))
 if k==150:return '9'*n+'\n3\n'
 if k==151:return f'{n}\n'+line(range(1,n+1))+line(a(n,1,50))+line(a(n-1,1,50))
 if k==152:return f'1\n{n} {n//2}\n'+line(range(1,2*n,2))
 if k==153:return f'{n} 1400\n'+''.join(line([int((i+j)%17==0)for j in range(1400)])for i in range(n))
 if k==154:return f'{n} 10\n'+('abcdefghijklmnopqrstuvwxyz'*(n//26+1))[:n]+'\n'
 if k==155:return f'{n} {min(100,n)} {n}\n'+line(range(1,n+1))+line([i%min(100,n)+1 for i in range(n)])+line(range(1,n+1))
 if k==156:return f'1\n{n} 100 {max(1,n//2)}\n'+line([i%100+1 for i in range(n)])
 if k==157:return f'{n} {n//2}\n'+''.join(f'{i%50+1} {(i*7)%50+1}\n'for i in range(n))
 if k==158:return f'{n}\n'+('HHTT'*(n//4+1))[:n]+'\n'
 if k==159:return f'97 99 {n}\n'
 if k==160:return f'{n}\n'+line(a(n,1,10**6))
 if k==161:return f'{n} 2000\n'+line([i%7+1 for i in range(n)])+line([i%7+1 for i in range(2000)])
 if k==162:return f'{n} 999999937\n'+line(a(n,1,10**9))
 if k==163:return '100000\n'+line(range(1,100001))+f'{n}\n'+''.join(f'{i%100000+1} {(i+1)%100000+1}\n'for i in range(n))
 if k==164:return f'100 {n}\n'+line([n//30]*100)
 if k==165:return f'{n} 100000\n'+line(a(n,1,10**9))+line(a(100000,1,10**9))
 if k==166:return f'{n}\n'+line(a(n,1,10**6))+line(a(n,1,10**6))
 if k==167:return f'{n}\n'+line(a(n,1,100000))
 if k==168:return f'{n}\n'+line(a(n,1,100))+'100\n'+line(range(1,101))
 if k==169:return f'{n}\n'+''.join(f'{10**18-i*17-15} {10**18-i*17}\n'for i in range(n))
 if k==170:return f'{n}\n'+line([(-1)**i*(i%999+1)for i in range(n)])
 if k==171:return f'100 {n}\n'+line(a(100,-100,100))+''.join(f'1 {1+i%100}\n'for i in range(n))
 if k==172:return ('abba'*(n//4+1))[:n]+'\n'
 if k==173:return f'{n}\n'+line(a(n,0,n-1))+line(a(n,0,n-1))
 if k==174:return f'1\n{n} 1000000000000000000\n'+line(a(n,-10**9,10**9))
 if k==175:
  q=n;m=150000;return f'{m} 6 {q}\n'+line(range(1,m+1))+''.join(f'1 {i+1}\n'if i<min(m,q-1)else f'2 {i%m+1}\n'for i in range(q))
 if k==176:return f'{n} 100000\n'+''.join(f'{i+1} {1+i%n} {1+i%1000}\n'for i in range(100000))
 if k==177:return f'{n} 1\n'+'b\n'+'a\n'*(n-1)
 if k==178:return f'{n}\n'+line(a(n,1,10**9))
 if k==179:return f'{n}\n'+line(a(n,0,2**60-1))
 if k==180:return f'{n} 50\n'+''.join(''.join('#'if(i+j)%7==0 else'.'for j in range(50))+'\n'for i in range(n))
 if k==181:return ('ABCD'*(n//4+1))[:n]+'\n'+('CDAB'*(n//4+1))[:n]+'\n'
 if k==182:return f'{n}\n'+line(range(1,n+1))+'50\n'+line(range(9951,10001))
 if k==183:return f'{n}\n'+''.join(chr(97+i%26)+'ab'+chr(97+(i*7)%26)+'\n'for i in range(n))
 if k==184:return f'1\n{n}\n'
 if k==185:return f'{n}\n'+line(a(n,1,180))
 if k==186:
  a0=[i%4 for i in range(n)];return f'{n}\n'+line([a0[i]|a0[i+1]for i in range(n-1)])+line([a0[i]&a0[i+1]for i in range(n-1)])
 if k==187:return f'1\n{n}\n'+line(range(n,0,-1))
 if k==188:return f'1 10000 {n}\n'
 if k==189:return f'{n} 10\n'+''.join(f'{n} '+line(range(1,n+1))for _ in range(10))+line([1]*10)
 if k==190:return f'1\n{10**9-n} 1000000000\n'
 if k==191:return f'1\n{n} 1\n'+' '.join('aa'if i%2 else'bb'for i in range(n))+'\n2 aa cc\n'
 if k==192:return f'1 1 {n}\n'
 if k==193:return f'{n}\n'+line([i%2 for i in range(n)])
 if k==194:return 'a'*(n-1)+'b\n'+'b'+'a'*(n-1)+'\n'
 if k==195:return f'{n}\n'+line(a(n,1,100))+line(a(n,1,100))
 if k==196:return f'1\n{n} 2 2 {n-1}\n'
 if k==197:return f'1\n{n}\n'+line(a(n,1,10**6))
 if k==198:return '1\n'+'a'*99+'b\n'+'a'*(n-1)+'b\n'
 if k==199:return f'{n}\n'+line(a(n,1,400000))
 if k==200:return f'1\n\n{n} {n}\n'+line(range(1,n+1))+line(a(n,1,10**9))
 if k==201:return '100000\n'+line(a(100000,0,10**6))+f'{n}\n'+''.join(f'1 1 100000\n'if i%2 else f'2 1 100000 {i%1000000+1}\n'for i in range(n))
 if k==202:return '()'*(n//2)+'\n'
 if k==203:return f'1000 {n}\n'+line([1]*1000)+line([1000]*1000)
 if k==204:return f'{n}\n'+''.join(f'{i%1000000001} {i%97+1}\n'for i in range(n))
 if k==205:return f'1\n{n} 10\n'+line(a(n,1,100000))
 if k==206:return f'1\n{n} 100 1000000000\n'+line(a(n,1,10**9))
 if k==207:return f'{n}\n1000000\n'+f'1 {n}\n'*1000000+'3\n1\n1000000\n'+f'{n}\n'
 if k==208:return f'{n}\n'+line(a(n,1,100))
 if k==209:return '100000 99999\n'+''.join(f'{i} {i+1}\n'for i in range(99999))+f'{n}\n'+''.join(f'{i%100000} {(i*17)%100000}\n'for i in range(n))
 if k==210:return f'200000 {n}\n'+line([(-1)**i for i in range(200000)])+''.join(f'1 {i%200000+1}\n'for i in range(n))
 if k==211:return f'{n} 1 {n//2}\n'+line(a(n,0,10**9))
 if k==212:return f'1000 {n}\n'+''.join(f'1 {i%1000+1}\n'if i%3!=2 else f'3 {i//3+1}\n'for i in range(n))
 if k==213:return f'{n}\n'+line(range(n,0,-1))+'1000\n'+f'1 {n}\n'*1000
 if k==214:return f'{n}\n'+''.join(['0.000000001\n','9999.999999999\n','1.25\n','8\n'][i%4]for i in range(n))
 if k==215:return f'{n}\n'
 if k==216:return f'1000 {n}\n'+''.join(f'CLICK {i%1000+1}\n'if i%3 else'CLOSEALL\n'for i in range(n))
 if k==217:return f'{n}\n'+line(a(2*n,1,1000))
 if k==218:return f'{n}\n'+line(a(n,1,10**9))
 if k==219:return '1\n'+('aabb'*(n//4+1))[:n]+'\n'
 if k==220:return f'{n} 1 {n}\n'
 raise KeyError(k)
