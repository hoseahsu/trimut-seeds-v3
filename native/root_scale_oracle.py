#!/usr/bin/env python3
"""Separate Python implementation for native/expanded scale validation.
Small exhaustive C++ oracles remain the independent-algorithm evidence.
For fixed scale cases keys use a documented geometric closed-form certificate.
"""
import sys,math,bisect,itertools
from collections import Counter,defaultdict,deque

def solve(k,mut,s):
 t=iter(s.split());num=lambda:int(next(t));arr=lambda n:[num()for _ in range(n)];out=[]
 if k==2:
  for _ in range(num()):
   l,r,d=arr(3);x=(l+d-1)//d*d if mut else(d if d<l else(r//d+1)*d);out.append(x if not mut or x<=r else -1)
 elif k==3:
  n=num();a,b,c=arr(n),arr(n-1),arr(n-2)
  for x,y in[(a,b),(b,c)]:v=next(iter(Counter(x)-Counter(y)));out.append(x.index(v)+1 if mut else v)
 elif k==4:
  n,m=arr(2);basis={};cover=0
  for _ in range(n):
   row=0
   for x in arr(num()):row|=1<<(x-1)
   cover|=row
   while row:
    b=row.bit_length()-1
    if b not in basis:basis[b]=row;break
    row^=basis[b]
  z=(1<<m)-1
  if mut:
   while z and z.bit_length()-1 in basis:z^=basis[z.bit_length()-1]
   out=['YES'if z==0 else'NO']
  else:out=['YES'if cover==z else'NO']
 elif k==5:
  n,x=arr(2);v=[x//a for a in arr(n)if x%a==0];out=[max(v)if mut else min(v)]
 elif k==6:
  a=arr(num());lo=max(a);total=sum(a)
  while (len(a)*lo<2*total if mut else len(a)*lo<=2*total):lo+=1
  out=[lo]
 elif k==7:
  n=num();a=[arr(2)for _ in range(n)];h=Counter(x for x,y in a);away=Counter(y for x,y in a);out=[sum(v*(v-1)for v in h.values())if mut else sum(v*away[x]for x,v in h.items())]
 elif k==8:
  n,q,p=arr(3);a,b=arr(n),arr(q)
  # The generated scale case puts every key between every person and the office.
  assert max(a)<=min(b)<=max(b)<=p
  out=[sum(p-x for x in a)if mut else p-min(a)]
 elif k in(9,15):
  a=arr(num());hi,lo=a[0],a[0];z=1 if k==9 else 0
  for x in a[1:]:z+=(x>hi if mut else x>=hi)if k==9 else(x>hi or(not mut and x<lo));hi=max(hi,x);lo=min(lo,x)
  out=[z]
 elif k==10:
  a=arr(num());p=[0]+list(itertools.accumulate(a))
  if not mut:out=[sum(c*(c-1)//2 for c in Counter(p).values())]
  else:
   # Merge-sort counts strictly increasing pairs without a Fenwick tree.
   def count(v):
    if len(v)<=1:return v,0
    j=len(v)//2;a,x=count(v[:j]);b,y=count(v[j:]);r=0;cross=0
    for z in b:
     while r<len(a)and a[r]<z:r+=1
     cross+=r
    return list(__import__('heapq').merge(a,b)),x+y+cross
   out=[count(p)[1]]
 elif k==11:
  n,W=arr(2);items=[arr(2)for _ in range(n)];V=sum(v for v,w in items);d=[[10**30]*2 for _ in range(V+1)];d[0][0]=0
  for v,w in items:
   for z in range(V,v-1,-1):
    d[z][0]=min(d[z][0],d[z-v][1]+w);d[z][1]=min(d[z][1],d[z-v][0]+w)
  out=[max((v for v,x in enumerate(d)if(x[1]if mut else min(x))<=W),default=-1)]
 elif k==12:
  a=set(arr(num()));b=set(arr(num()));out=sorted(a^b if mut else a&b)
 elif k==13:
  a=next(t);b=next(t);z=''.join(sorted(a,reverse=bool(mut)))
  if not mut and len(z)>1 and z[0]=='0':
   p=next(i for i,x in enumerate(z)if x!='0');z=z[p]+z[:p]+z[p+1:]
  out=['OK'if z==b else'WRONG_ANSWER']
 elif k==14:
  for _ in range(num()):
   a,b,q=arr(3);period=math.lcm(a,b);bad=[int((x%a)%b!=(x%b)%a)for x in range(period)];pref=[0]+list(itertools.accumulate(bad));F=lambda x:(x//period)*pref[-1]+pref[x%period]
   for _ in range(q):l,r=arr(2);v=F(r+1)-F(l);out.append(r-l+1-v if mut else v)
 elif k==16:
  n,d=arr(2);a=sorted(tuple(arr(2))for _ in range(n));money=[x for x,y in a];pref=[0]+list(itertools.accumulate(y for x,y in a));out=[max(pref[(bisect.bisect_right if mut else bisect.bisect_left)(money,x+d)]-pref[i]for i,(x,y)in enumerate(a))]
 elif k==18:
  n,K=arr(2);K-=bool(mut);a=arr(n);S=1<<19;tree=[0]*(2*S);ans=0
  for x in a:
   l,r=max(0,x-K)+S,min(300000,x+K)+S+1;z=0
   while l<r:
    if l&1:z=max(z,tree[l]);l+=1
    if r&1:r-=1;z=max(z,tree[r])
    l//=2;r//=2
   v=z+1;ans=max(ans,v);i=x+S
   while i:tree[i]=max(tree[i],v);i//=2
  out=[ans]
 elif k==19:
  n=num();ans=0
  # Enumerate digit tuples by length, independently of recursive numeric DFS.
  for length in range(1,len(str(n))+1):
   for digits in itertools.product('357',repeat=length):
    if len(set(digits))>=(2 if mut else 3) and int(''.join(digits))<=n:ans+=1
  out=[ans]
 elif k==20:
  n,q=arr(2);items=sorted((b,a)for a,b in [arr(2)for _ in range(n)]);import heapq
  if not mut:items.reverse()
  heap=[];total=0;best=0
  for b,a in items:
   best=max(best,(total+a)*b);heapq.heappush(heap,a);total+=a
   if len(heap)==q:total-=heapq.heappop(heap)
  out=[best]
 elif k==21:
  for _ in range(num()):
   n,m=arr(2);z=n-m
   if mut:lost=z*(z+1)//2
   else:q,r=divmod(z,m+1);lost=(m+1-r)*q*(q+1)//2+r*(q+1)*(q+2)//2
   out.append(n*(n+1)//2-lost)
 elif k==22:
  for _ in range(num()):
   n,q=arr(2);a=sorted(arr(n),reverse=not bool(mut));v=a[q-1];out.append(math.comb(a.count(v),a[:q].count(v))%1000000007)
 elif k==23:out=[pow(1378,num(),100 if mut else 10)]
 elif k==24:
  a=arr(num());stack=[];best=0
  for i,h in enumerate(a+[0]):
   start=i
   while stack and stack[-1][1]>=h:
    start,old=stack.pop();w=i-start;best=max(best,min(w,old)**2 if mut else w*old)
   stack.append((start,h))
  out=[best]
 elif k==26:
  n=num();a=arr(n);out=[sum(4*x*(n-1 if mut else i)for i,x in enumerate(a))]
 elif k==27:
  for _ in range(num()):
   s=next(t);a=deque(x for x in s if int(x)%2);b=deque(x for x in s if int(x)%2==0);z=[]
   while a and b:z.append((a if(a[0]>b[0]if mut else a[0]<b[0])else b).popleft())
   out.append(''.join(z)+''.join(a)+''.join(b))
 elif k==28:
  for _ in range(num()):
   n,m,x,y=arr(4);total=0
   for _ in range(n):
    for run in next(t).split('*'):
     # Every run permits j dominoes for 0<=j<=floor(length/2).
     L=len(run);j=L//2 if(y>2*x if mut else y<2*x)else 0;total+=j*y+(L-2*j)*x
   out.append(total)
 elif k==29:
  n,K=arr(2);K+=bool(mut);a=arr(n);where=defaultdict(deque);left=0;answer=0
  for i,x in enumerate(a):
   q=where[x];q.append(i)
   if len(q)>=K:left=max(left,q.popleft()+1)
   answer+=left
  out=[answer]
 elif k==30:
  n,k=arr(2);target=n-1
  if target>k*(k-1)//2:out=[-1]
  elif mut:out=[min(k-1,(math.isqrt(1+8*target)-1)//2)]
  else:
   # Solve c(2k-c-1)/2>=target using an integer square-root bound.
   c=max(0,(2*k-1-math.isqrt((2*k-1)**2-8*target))//2)
   while c*(2*k-c-1)//2<target:c+=1
   while c and(c-1)*(2*k-c)//2>=target:c-=1
   out=[c]
 elif k==31:
  for _ in range(num()):
   a=arr(num());prior=a[0];need=0
   for i,x in enumerate(a):z=x-i if mut else x;prior=max(prior,z);need=max(need,prior-z)
   out.append(need.bit_length())
 elif k==32:
  for _ in range(num()):
   n=num();u=arr(n);skills=arr(n);g=defaultdict(list)
   for v,x in zip(u,skills):g[v].append(x)
   ans=[0]*n
   for values in g.values():
    values.sort(reverse=not bool(mut));pref=[0]+list(itertools.accumulate(values));s=len(values)
    for q in range(1,s+1):ans[q-1]+=pref[s-s%q]
   out.extend(ans)
 elif k==33:
  for _ in range(num()):
   a=arr(num());b=sorted(a);out.append('YES'if Counter((x,i%2)for i,x in enumerate(a))==Counter((x,(i%2)^bool(mut))for i,x in enumerate(b))else'NO')
 elif k==34:
  a=arr(num());bad=[i for i in range(len(a))if(a[i]<a[(i+1)%len(a)]if mut else a[i]>a[(i+1)%len(a)])];out=[-1 if len(bad)>1 else 0 if not bad else(len(a)-1-bad[0])%len(a)]
 elif k==35:
  s=next(t);a=s.find('AB');b=s.find('BA');ok=(a>=0 and s.find('BA',a+2)>=0)or(not mut and b>=0 and s.find('AB',b+2)>=0);out=['YES'if ok else'NO']
 elif k==36:
  n,m=arr(2);a=arr(n)
  if not mut and n>=m:out=['YES']
  else:
   e,o=1,0;mask=(1<<m)-1;nonempty=False
   for x in a:
    v=x%m;re=((e<<v)|(e>>(m-v)))&mask;ro=((o<<v)|(o>>(m-v)))&mask;nonempty|=bool((re|ro)&1);e|=ro;o|=re
   out=['YES'if(o&1 if mut else nonempty)else'NO']
 elif k==37:
  n,q=arr(2);offset=[0,0]
  for _ in range(q):
   if num()==1:x=num();offset=[(v+x)%n for v in offset]
   else:offset=[(v+(1 if(i+v)%2==bool(mut)else -1))%n for i,v in enumerate(offset)]
  a=[0]*n
  for i in range(n):a[(i+offset[i%2])%n]=i+1
  out=a
 elif k==38:
  n,m,z=arr(3)
  if mut:n,m=m,n
  if z<n:x,y=z+1,1
  else:q,r=divmod(z-n,m-1);x=n-q;y=m-r if q%2 else r+2
  out=[y,x]if mut else[x,y]
 elif k==39:
  for _ in range(num()):n,q=arr(2);out.append(math.comb(q-1,n-1)if mut and q>=n else 0 if mut else math.comb(n+q-1,n-1))
 elif k==40:
  s=next(t);pay,carry=0,1
  # Prefix DP (opposite traversal direction from the C++ suffix DP).
  for c in s:
   d=int(c);pay,carry=min(pay+d,carry+(10-d)*(2 if mut else 1)),min(pay+d+1,carry+(9-d)*(2 if mut else 1))
  out=[pay]
 elif k==41:
  n,m=arr(2);x=arr(n+m);flags=arr(n+m);taxi=[v for v,b in zip(x,flags)if b];a=[0]*m
  for v,b in zip(x,flags):
   if b:continue
   j=bisect.bisect_left(taxi,v);cand=[i for i in (j-1,j)if 0<=i<m];best=min(cand,key=lambda i:(abs(taxi[i]-v),-taxi[i]if mut else taxi[i]));a[best]+=1
  out=a
 elif k==42:
  n,m=arr(2);a=arr(n);b=sorted(tuple(arr(2))for _ in range(m));p=[0]+list(itertools.accumulate(g for d,g in b));keys=[d for d,g in b];out=[p[(bisect.bisect_left if mut else bisect.bisect_right)(keys,x)]for x in a]
 elif k==43:
  for _ in range(num()):
   n=num();f=Counter(arr(n));out.append(sum(v%2 for v in f.values())if mut else max(n%2,2*max(f.values())-n))
 elif k==44:
  n,m=arr(2);a=[next(t)for _ in range(n)];out=[len(set(a))if mut else math.prod(len(set(col))for col in zip(*a))%1000000007]
 elif k==45:
  n,m=arr(2);a=[set(arr(num()))for _ in range(n)];counts=Counter(x for v in a for x in v)
  if mut:out=[n-max(counts.values(),default=0)]
  elif not counts:out=[n]
  else:
   # Build the language graph, instead of the C++ employee-incidence DSU.
   graph=[set()for _ in range(m+1)];empty=0;used=set()
   for languages in a:
    if not languages:empty+=1;continue
    u=next(iter(languages));used|=languages
    for v in languages:graph[u].add(v);graph[v].add(u)
   components=empty
   while used:
    components+=1;stack=[used.pop()]
    while stack:
     v=stack.pop();nxt=graph[v]&used;used-=nxt;stack.extend(nxt)
   out=[components-1]
 elif k==46:
  A,B,q=arr(3)
  for _ in range(q):
   l,time_limit,m=arr(3);first=A+(l-1)*B;cap=time_limit*m-int(bool(mut));maxlen=max(0,(time_limit-first)//B+1);C=2*first-B
   z=max(0,(math.isqrt(C*C+8*B*max(0,cap))-C)//(2*B));z=min(z,maxlen)
   while z and z*(2*first+(z-1)*B)//2>cap:z-=1
   while z<maxlen and(z+1)*(2*first+z*B)//2<=cap:z+=1
   out.append(l+z-1 if z else -1)
 elif k==47:
  n,m=arr(2);a=arr(n);b=arr(m)
  if mut:out=[max(abs(a[0]-b[-1]),abs(a[-1]-b[0]))]
  else:
   j=0;best=0
   for x in a:
    while j+1<m and abs(b[j+1]-x)<=abs(b[j]-x):j+=1
    best=max(best,abs(b[j]-x))
   out=[best]
 elif k==48:
  a=arr(num());left=0;last={};answer=0
  for r,x in enumerate(a):
   last[x]=r
   for y,p in list(last.items()):
    if abs(y-x)>(1 if mut else 0):left=max(left,p+1);del last[y]
   answer+=r-left+1
  out=[answer]
 elif k==49:
  a=arr(num());n=len(a)
  if mut:a.sort();out=[sum((2*i-n+1)*x for i,x in enumerate(a))%1000000007]
  else:out=[((sum(a)**2-sum(x*x for x in a))//2)%1000000007]
 elif k==50:
  n=num();a=arr(n)
  if mut:a.reverse()
  want=1
  for x in a:
   if x==want:want+=1
  out=[n-(want-1)if want>1 else -1]
 elif k==51:
  a,b=next(t),next(t);groups=defaultdict(set)
  for x,y in zip(a,b):groups[x].add(y)
  ok=all(len(v)==1 for v in groups.values())and(mut or len({next(iter(v))for v in groups.values()})==len(groups));out=['Yes'if ok else'No']
 elif k==52:n,m=arr(2);out=[''.join(sorted([next(t)for _ in range(n)],reverse=bool(mut)))]
 elif k==53:
  for n in map(int,t):
   if n==0:break
   # Factor divisors of 2N, then test the implied first term.
   z=0;d=1
   while d*d<=2*n:
    if 2*n%d==0:
     for length in ({d,2*n//d}):
      first2=2*n//length-length+1
      if length>=2 and first2%2==0 and first2>=(0 if mut else 2):z+=1
    d+=1
   out.append(z)
 elif k==54:
  for _ in range(num()):
   n=num();a=arr(n);b=arr(n);start=Counter(a);end=Counter(b);cur=best=0
   for z in sorted(start.keys()|end.keys()):
    if not mut:cur-=end[z]
    cur+=start[z];best=max(best,cur)
    if mut:cur-=end[z]
   out.append(best)
 elif k==55:
  for _ in range(num()):a=num();out.append(2**(a.bit_count()-(int(bool(a&1))if mut else 0)))
 else:raise KeyError(k)
 return '\n'.join(map(str,out))+'\n'
if __name__=='__main__':print(solve(int(sys.argv[1]),bool(int(sys.argv[2])),sys.stdin.read()),end='')
