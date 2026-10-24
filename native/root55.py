"""Original-domain validators and strictly expanded scale cases for TM001..055.

A failed parser rejects the input; upstream malformed cases are never repaired.
The selected scale changes leave every other native restriction unchanged.
"""
from collections import Counter
import random
import re

# Primary changed upper bound; shared/aggregate bounds follow this cap only where
# explicitly declared below. These are native, not legacy standardized bounds.
CAPS={1:(100,1000000),2:(500,50000),3:(100000,500000),4:(100,100000),5:(100,100000),6:(100,100000),7:(30,200000),8:(2000,10000),9:(20,100000),10:(200000,600000),11:(100,200),12:(200000,600000),13:(10**9,10**18),14:(500,2000),15:(1000,100000),16:(100000,400000),17:(100000,400000),18:(300000,600000),19:(999999999,999999999999),20:(300000,600000),21:(10**9,2*10**9),22:(1000,2000),23:(10**9,10**18),24:(100000,600000),25:(10000,100000),26:(100,100000),27:(300000,600000),28:(100,200),29:(400000,800000),30:(10**9,2*10**9),31:(100000,400000),32:(200000,600000),33:(100000,400000),34:(100000,400000),35:(100000,400000),36:(1000000,2000000),37:(2000000,3000000),38:(10**9,2*10**9),39:(19,25),40:(1000000,2000000),41:(100000,400000),42:(100000,400000),43:(200000,600000),44:(100,10000),45:(100,10000),46:(100000,300000),47:(100000,400000),48:(100000,400000),49:(200000,600000),50:(200000,600000),51:(200000,600000),52:(100,10000),53:(1000,10**10),54:(100,10000),55:(2**30-1,2**60-1)}
AXES=['n','q','n','n','n','n','n','k','N','N','N','n','n and m numeric value','q per test case','n','n','n','N','N','n','n','n per test case','n','N','N per test case','n','per-case and total string length','n and aggregate grid area','n','k','per-case and total n','per-case and total n','per-case and total n','n','string length','n','q','m','k','decimal exponent bound','n','s','per-case and total n','n','n','query count','n','n','N','N','string length','N','N','N per test case','a']

class Parse:
 def __init__(self,s):self.v=s.split();self.i=0
 def token(self):
  assert self.i<len(self.v),'unexpected end'
  x=self.v[self.i];self.i+=1;return x
 def integer(self,lo=None,hi=None):
  s=self.token();assert re.fullmatch(r'-?\d+',s,flags=re.ASCII),'invalid integer token'
  x=int(s);assert lo is None or x>=lo,(x,'below',lo);assert hi is None or x<=hi,(x,'above',hi);return x
 def arr(self,n,lo,hi):return [self.integer(lo,hi) for _ in range(n)]
 def string(self,chars,lo=1,hi=None):
  s=self.token();assert lo<=len(s) and (hi is None or len(s)<=hi),'invalid length';assert all(c in chars for c in s),'invalid alphabet';return s
 def end(self):assert self.i==len(self.v),'trailing tokens'

def check(sid,text,condition='raw'):
 k=int(str(sid).removeprefix('TM')); cap=CAPS[k][condition=='l2'];p=Parse(text);metric=None
 if k==1:
  n=p.integer(1,cap);assert len(p.string('0123456789'))==n;metric=n
 elif k==2:
  q=p.integer(1,cap);metric=q
  for _ in range(q):l=p.integer(1,10**9);p.integer(l,10**9);p.integer(1,10**9)
 elif k==3:
  n=p.integer(3,cap);a=Counter(p.arr(n,1,10**9));b=Counter(p.arr(n-1,1,10**9));c=Counter(p.arr(n-2,1,10**9));assert not b-a and not c-b and sum((a-b).values())==sum((b-c).values())==1;metric=n
 elif k in (4,45):
  n=p.integer(1 if k==4 else 2,cap);m=p.integer(1 if k==4 else 2,100);metric=n
  for _ in range(n):
   a=p.arr(p.integer(0,m),1,m)
   if k==45:assert len(set(a))==len(a),'duplicate language'
 elif k==5:
  n=p.integer(1,cap);x=p.integer(1,100);a=p.arr(n,1,100);assert any(x%v==0 for v in a);metric=n
 elif k in (6,9,15,24,26,34,48,49,50):
  limits={6:(1,1,100),9:(1,1,100),15:(1,0,10000),24:(1,0,10**9),26:(1,0,100),34:(2,1,100000),48:(1,-10**9,10**9),49:(2,0,10**9),50:(1,1,None)}
  mn,lo,hi=limits[k];n=p.integer(mn,cap);p.arr(n,lo,n if hi is None else hi);metric=n
 elif k==7:
  n=p.integer(2,cap);metric=n
  for _ in range(n):a,b=p.arr(2,1,100);assert a!=b
 elif k==8:
  n=p.integer(1,1000);q=p.integer(n,cap);p.integer(1,10**9);a=p.arr(n,1,10**9);b=p.arr(q,1,10**9);assert len(set(a))==n and len(set(b))==q;metric=q
 elif k==10:n=p.integer(1,cap);p.arr(n,-10**9,10**9);metric=n
 elif k==11:
  n=p.integer(1,cap);p.integer(1,10**9);metric=n
  for _ in range(n):p.integer(1,100);p.integer(1,10**7)
 elif k==12:
  n=p.integer(1,cap);a=p.arr(n,0,10**9);m=p.integer(1,200000);b=p.arr(m,0,10**9);assert all(x<y for x,y in zip(a,a[1:])) and all(x<y for x,y in zip(b,b[1:]));metric=n
 elif k==13:
  a=p.string('0123456789');b=p.string('0123456789');assert len(a)==1 or a[0]!='0';bn=b.lstrip('0')or'0';assert len(a)<=len(str(cap)) and len(bn)<=len(str(cap));assert int(a)<=cap and int(bn)<=cap;metric=max(int(a),int(bn))
 elif k==14:
  T=p.integer(1,100);metric=0
  for _ in range(T):
   p.integer(1,200);p.integer(1,200);q=p.integer(1,cap);metric=max(metric,q)
   for _ in range(q):l=p.integer(1,10**18);p.integer(l,10**18)
 elif k==16:
  n=p.integer(1,cap);p.integer(1,10**9);metric=n
  for _ in range(n):p.arr(2,0,10**9)
 elif k==17:
  T=p.integer(1,50);metric=0
  for _ in range(T):
   n=p.integer(1,cap);metric=max(metric,n)
   for z in range(2):a=p.arr(n,1,10**12);assert all(x>=y for x,y in zip(a,a[1:]))
 elif k==18:n=p.integer(1,cap);p.integer(0,300000);p.arr(n,0,300000);metric=n
 elif k in (19,23):metric=p.integer(1 if k==19 else 0,cap)
 elif k==20:
  n=p.integer(1,cap);p.integer(1,n);metric=n
  for _ in range(n):p.arr(2,1,10**6)
 elif k==21:
  T=p.integer(1,100000);metric=0
  for _ in range(T):n=p.integer(1,cap);p.integer(0,n);metric=max(metric,n)
 elif k==22:
  T=p.integer(1,1000);metric=0
  for _ in range(T):n=p.integer(1,cap);p.integer(1,n);p.arr(n,1,n);metric+=n
  assert metric<=cap
 elif k==25:
  T=p.integer(1,100);metric=0
  for _ in range(T):n=p.integer(1,cap);a=p.arr(n,1,2**31-1);assert len(set(a))==n;metric=max(metric,n)
 elif k==27:
  T=p.integer(1,10000);total=0
  for _ in range(T):total+=len(p.string('0123456789',1,cap))
  assert total<=cap;metric=total
 elif k==28:
  T=p.integer(1,500);total=0;metric=0
  for _ in range(T):
   n=p.integer(1,cap);m=p.integer(1,1000);p.arr(2,1,1000);metric=max(metric,n);total+=n*m
   for _ in range(n):assert len(p.string('.*'))==m
  assert total<=cap*1000
  metric=max(metric,total/1000)
 elif k==29:n=p.integer(1,cap);p.integer(1,n);p.arr(n,1,10**9);metric=n
 elif k==30:p.integer(1,10**18);metric=p.integer(2,cap)
 elif k in (31,32,33,43):
  T=p.integer(1,{31:10000,32:1000,33:50,43:10000}[k]);total=0
  for _ in range(T):
   n=p.integer(1,cap);total+=n
   if k==32:p.arr(n,1,n)
   p.arr(n,-10**9 if k==31 else 1,100000 if k==33 else 10**9)
  assert total<=cap;metric=total
 elif k==35:metric=len(p.string('ABCDEFGHIJKLMNOPQRSTUVWXYZ',1,cap))
 elif k==36:n=p.integer(1,cap);p.integer(2,1000);p.arr(n,0,10**9);metric=n
 elif k==37:
  n=p.integer(2,1000000);assert n%2==0;q=p.integer(1,cap);metric=q
  for _ in range(q):
   if p.integer(1,2)==1:p.integer(-n,n)
 elif k==38:n=p.integer(2,10**9);assert n%2==0;m=p.integer(2,cap);p.integer(0,n*m-1);metric=m
 elif k==39:
  T=p.integer(1,100000);metric=0
  for _ in range(T):p.integer(1,19);metric=max(metric,p.integer(1,cap))
 elif k==40:
  s=p.string('0123456789',1,cap+1);assert s[0]!='0';assert len(s)<=cap or s=='1'+'0'*cap;metric=len(s)-1 if s=='1'+'0'*(len(s)-1) else len(s)
 elif k==41:
  n=p.integer(1,cap);m=p.integer(1,100000);a=p.arr(n+m,1,10**9);flags=p.arr(n+m,0,1);assert sum(flags)==m and all(x<y for x,y in zip(a,a[1:]));metric=n
 elif k==42:
  n=p.integer(1,cap);m=p.integer(1,100000);p.arr(n,0,10**9);metric=n
  for _ in range(m):p.integer(0,10**9);p.integer(0,10000)
 elif k in (44,52):
  n=p.integer(1,cap);m=p.integer(1,100);metric=n
  for _ in range(n):assert len(p.string('ABCDEFGHIJKLMNOPQRSTUVWXYZ'if k==44 else'abcdefghijklmnopqrstuvwxyz'))==m
 elif k==46:
  p.arr(2,1,10**6);q=p.integer(1,cap);metric=q
  for _ in range(q):p.arr(3,1,10**6)
 elif k==47:
  n=p.integer(1,cap);m=p.integer(1,100000);a=p.arr(n,-10**9,10**9);b=p.arr(m,-10**9,10**9);assert all(x<=y for x,y in zip(a,a[1:])) and all(x<=y for x,y in zip(b,b[1:]));metric=n
 elif k==51:
  a=p.string('abcdefghijklmnopqrstuvwxyz',1,cap);b=p.string('abcdefghijklmnopqrstuvwxyz',1,cap);assert len(a)==len(b);metric=len(a)
 elif k==53:
  metric=0
  while True:
   n=p.integer(0,cap)
   if n==0:break
   metric=max(metric,n)
 elif k==54:
  T=p.integer(1,100);metric=0
  for _ in range(T):n=p.integer(1,cap);a=p.arr(n,1,1000);b=p.arr(n,1,1000);assert all(x<y for x,y in zip(a,b));metric=max(metric,n)
 elif k==55:
  T=p.integer(1,1000);metric=max(p.arr(T,0,cap))
 else:raise KeyError(k)
 p.end();return {'axis':AXES[k-1],'observed':metric,'original_upper':CAPS[k][0],'l2_upper':CAPS[k][1],'outside_original':metric>CAPS[k][0]}

def validate(sid,text,condition='raw'):
 try:return {'valid':True,**check(sid,text,condition)}
 except (ValueError,IndexError,AssertionError) as e:return {'valid':False,'reason':str(e)}

def line(a):return ' '.join(map(str,a))+'\n'
def scale_case(sid,l2=False):
 k=int(str(sid).removeprefix('TM'));n=CAPS[k][l2];R=random.Random(97531+k);a=lambda count,lo,hi:[R.randint(lo,hi)for _ in range(count)]
 if k==1:return f'{n}\n'+('80012345678'*(n//11+1))[:n]+'\n'
 if k==2:return f'{n}\n'+''.join(line((i%100+1,10**9,1+i%200))for i in range(n))
 if k==3:
  x=a(n,1,10**9);return f'{n}\n'+line(x)+line(x[1:])+line(x[2:])
 if k==4:return f'{n} 100\n'+''.join(f'2 {i%100+1} {(i+1)%100+1}\n'for i in range(n))
 if k==5:return f'{n} 100\n'+line([1]+a(n-1,1,100))
 if k in (6,9,15,24,26,34,48,49,50):
  lo,hi={6:(1,100),9:(1,100),15:(0,10000),24:(0,10**9),26:(0,100),34:(1,100000),48:(-10**9,10**9),49:(0,10**9),50:(1,n)}[k]
  x=a(n,lo,hi)
  if k==48:x=[i//13%3 for i in range(n)]
  if k==50:x=[i+1 for i in range(n)]
  return f'{n}\n'+line(x)
 if k==7:return f'{n}\n'+''.join(f'{i%100+1} {(i+17)%100+1}\n'for i in range(n))
 if k==8:return f'1000 {n} 1000000000\n'+line(range(1,1001))+line(range(10001,10001+n))
 if k==10:return f'{n}\n'+line([(-1)**i*(i%7)for i in range(n)])
 if k==11:return f'{n} 1000000000\n'+''.join(f'{1+i%100} {10**7-i}\n'for i in range(n))
 if k==12:return f'{n}\n'+line(range(0,2*n,2))+'200000\n'+line(range(100000,300000))
 if k==13:return f'{n}\n'+str(n)+'\n'
 if k==14:return f'1\n199 200 {n}\n'+''.join(f'{1+i} {10**18-i}\n'for i in range(n))
 if k==16:return f'{n} 1000000000\n'+''.join(f'{i} {10**9-i}\n'for i in range(n))
 if k==17:return f'1\n{n}\n'+line(range(n,0,-1))+line(range(n,0,-1))
 if k==18:return f'{n} 101\n'+line([i*97%300001 for i in range(n)])
 if k==19:return f'{n}\n'
 if k==20:return f'{n} {n//2}\n'+''.join(f'{i%10**6+1} {(i*97)%10**6+1}\n'for i in range(n))
 if k==21:return f'3\n{n} {n//2}\n{n} 0\n{n} {n}\n'
 if k==22:return f'1\n{n} {n//2}\n'+line([n//2]*n)
 if k==23:return f'{n}\n'
 if k==25:return f'1\n{n}\n'+line(range(n,0,-1))
 if k==27:return '1\n'+('9876543210'*(n//10+1))[:n]+'\n'
 if k==28:return f'1\n{n} 1000 999 1000\n'+('.'*1000+'\n')*n
 if k==29:return f'{n} 13\n'+line([i%97+1 for i in range(n)])
 if k==30:return f'1000000000000000000 {n}\n'
 if k in (31,32,33,43):
  x=a(n,-10**9 if k==31 else 1,100000 if k==33 else 10**9)
  return f'1\n{n}\n'+(line([i%1000+1 for i in range(n)])if k==32 else'')+line(x)
 if k==35:return ('ABBA'*(n//4+1))[:n]+'\n'
 if k==36:return f'{n} 1000\n'+line([1]*n)
 if k==37:return f'1000000 {n}\n'+('2\n1 -999999\n'*(n//2))+('2\n'if n%2 else'')
 if k==38:return f'1000000000 {n} {10**9*n-1}\n'
 if k==39:return f'2\n19 {n}\n1 {n}\n'
 if k==40:return '1'+'0'*n+'\n'
 if k==41:
  m=100000;flags=[int(i%(1+n//m)==0)for i in range(n+m)];assert sum(flags)==m
  return f'{n} {m}\n'+line(range(1,n+m+1))+line(flags)
 if k==42:return f'{n} 100000\n'+line(a(n,0,10**9))+''.join(f'{i*10000} {i%10001}\n'for i in range(100000))
 if k==44:return f'{n} 100\n'+''.join((chr(65+i%26)*100+'\n')for i in range(n))
 if k==45:return f'{n} 100\n'+''.join(f'2 {i%100+1} {(i+1)%100+1}\n'for i in range(n))
 if k==46:return f'1 1 {n}\n'+''.join(f'{1+i%100} 1000000 1000000\n'for i in range(n))
 if k==47:return f'{n} 100000\n'+line(range(n))+line(range(0,300000,3))
 if k==51:return 'a'*n+'\n'+'b'*n+'\n'
 if k==52:return f'{n} 100\n'+''.join(chr(97+i%26)*100+'\n'for i in range(n))
 if k==53:return f'{n}\n0\n'
 if k==54:return f'1\n{n}\n'+line([1+i%500 for i in range(n)])+line([501+i%500 for i in range(n)])
 if k==55:return f'2\n{n}\n{n-1}\n'
 raise KeyError(k)
