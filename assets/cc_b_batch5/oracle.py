"""Independent finite-input oracles: enumeration/direct simulation; no shared solver code."""
import sys,itertools,collections,functools,math,fractions,heapq
it=iter(sys.stdin.read().split());T=int(sys.argv[1]);M=sys.argv[2]=='l3'
def num():return int(next(it))
def arr(n):return[num()for _ in range(n)]
def emit(x):print(' '.join(map(str,x))if isinstance(x,list)else x)
if T==1:
 n=num();a=arr(n);best=0
 for mask in range(1<<n):
  b=[a[i]for i in range(n)if mask>>i&1]
  if all((x>=y if M else x<=y)for x,y in zip(b,b[1:])):best=max(best,len(b))
 emit(best)
elif T==2:
 s=next(it);t=next(it);c=[s]
 if M:c.append(s[::-1])
 emit('Yes'if any(w[i:]+w[:i]==t for w in c for i in range(len(w)))else'No')
elif T==3:
 n=num();a=arr(n);b=arr(n);vals=[sum(a[:i+1])+sum(b[i:])for i in range(n)];emit(min(vals)if M else max(vals))
elif T==4:
 for _ in range(num()):
  L,v,l,r=arr(4);emit(sum(x%v==0 and not(l<x<r if M else l<=x<=r)for x in range(1,L+1)))
elif T==5:
 for _ in range(num()):
  a=arr(num());emit(sum(any(y<=x if M else y<x for y in a[i+1:])for i,x in enumerate(a)))
elif T==6:
 for _ in range(num()):
  p=next(it);h=next(it);target=sorted(p)
  if M:ok=any(sorted(c)==target for c in itertools.combinations(h,len(p)))
  else:ok=any(sorted(h[i:i+len(p)])==target for i in range(len(h)-len(p)+1))
  emit('YES'if ok else'NO')
elif T==7:
 n=num();a=arr(n);best=0
 for mask in range(1,1<<n):
  ids=[i for i in range(n)if mask>>i&1]
  if all(j-i==(a[i]-a[j]if M else a[j]-a[i])for i,j in zip(ids,ids[1:])):best=max(best,sum(a[i]for i in ids))
 emit(best)
elif T==8:
 for _ in range(num()):
  n,k=arr(2);a=arr(k);t=arr(k);emit([(max if M else min)(t[j]+abs(a[j]-i)for j in range(k))for i in range(1,n+1)])
elif T==9:
 a=arr(num())
 for _ in range(num()):
  t,l,r=arr(3);l-=1
  if t==2:
   x=num()
   for i in range(l,r):a[i]^=x
  elif M:emit(functools.reduce(int.__xor__,a[l:r],0))
  else:emit(sum(a[l:r]))
elif T==10:
 s=next(it);best=0;count=1
 for i in range(len(s)):
  for j in range(i+1,len(s)+1):
   w=s[i:j];balance=0;good=True
   for c in w:
    balance+=(c==(')'if M else'('))*2-1
    if balance<0:good=False
   if good and balance==0:
    if len(w)>best:best=len(w);count=1
    elif len(w)==best:count+=1
 emit([best,count])
elif T==11:
 n,k=arr(2);a=arr(n);b=arr(n);best=0
 if M:emit(min((b[i]+k)//a[i]for i in range(n)))
 else:
  # Enumerate all allocations of the common powder, independently of feasibility search.
  def f(i,left,stock):
   global best
   if i==n:
    best=max(best,min(stock[j]//a[j]for j in range(n)));return
   for v in range(left+1):f(i+1,left-v,stock+[b[i]+v])
  f(0,k,[]);emit(best)
elif T==12:
 n=num();a=[];b=[]
 for _ in range(n):x,y=arr(2);a.append(x);b.append(y)
 start=tuple(a);seen={start};q=collections.deque([(start,0)])
 while q:
  x,d=q.popleft()
  if all(x[i]%b[i]==0 for i in range(n)):emit(d);break
  for k in range(n):
   y=tuple(v+(-1 if M else 1)*(i<=k)for i,v in enumerate(x))
   if y not in seen:seen.add(y);q.append((y,d+1))
elif T==13:
 for _ in range(num()):
  n,d=arr(2);a=arr(n)
  @functools.lru_cache(None)
  def f(mask):
   if not mask:return 0
   i=(mask&-mask).bit_length()-1;rest=mask^(1<<i);z=f(rest)
   for j in range(i+1,n):
    if rest>>j&1 and(abs(a[i]-a[j])<=d if M else abs(a[i]-a[j])<d):z=max(z,a[i]+a[j]+f(rest^(1<<j)))
   return z
  emit(f((1<<n)-1))
elif T==14:
 for _ in range(num()):
  n,l,r=arr(3);a=arr(n);emit(sum(l<x+y<r if M else l<=x+y<=r for x,y in itertools.combinations(a,2)))
elif T==15:
 n=num();m=num();spans=[arr(2)for _ in range(m)];coins=[sum(l<=i<=r for l,r in spans)for i in range(1,n+1)]
 for _ in range(num()):x=num();emit(sum(v==x if M else v>=x for v in coins))
elif T==16:
 a=tuple(arr(num()))
 @functools.lru_cache(None)
 def game(a):
  if not a:return 0
  vals=[x-game(a[:i]+a[i+1:])for i,x in enumerate(a)]
  return min(vals)if M else max(vals)
 emit(game(a))
elif T==17:
 n,m=arr(2);edges=[arr(2)for _ in range(m)];q=num();queries=[arr(2)for _ in range(q)]
 # Warshall reachability on a doubled parity graph for L3, plain graph for Raw.
 size=2*n if M else n;r=[[False]*size for _ in range(size)]
 for i in range(size):r[i][i]=True
 for a,b in edges:
  if M:r[a][b+n]=r[b+n][a]=r[a+n][b]=r[b][a+n]=True
  else:r[a][b]=r[b][a]=True
 for k in range(size):
  for i in range(size):
   for j in range(size):r[i][j]|=r[i][k]and r[k][j]
 for a,b in queries:emit('yes'if r[a][b]else'no')
elif T==18:
 n,q=arr(2);a=arr(n)
 for _ in range(q):
  l,r=arr(2);emit(int(any(sum(c)==int(M)for c in itertools.combinations(a,r-l+1))))
elif T==19:
 n,m,k=arr(3);a=arr(n);vals=[]
 for starts in itertools.combinations(range(n-m+1),k):
  if all(j-i>=m for i,j in zip(starts,starts[1:])):vals.append(sum(sum(a[i:i+m])for i in starts))
 emit(min(vals)if M else max(vals))
elif T==20:
 n,q=arr(2);apps=[];unread=[]
 for _ in range(q):
  t,x=arr(2)
  if t==1:apps.append(x);unread.append(True)
  elif t==2:unread=[v and app!=x for v,app in zip(unread,apps)]
  else:
   idx=range(len(apps)-x,len(apps))if M else range(x)
   for i in idx:unread[i]=False
  emit(sum(unread))
elif T==21:
 n=num();a=arr(n)
 for _ in range(num()):
  l,r=arr(2);l-=1;a[l:r]=a[l+1:r]+a[l:l+1]if M else a[l:r][::-1];emit('odd'if sum(x>y for i,x in enumerate(a)for y in a[i+1:])%2 else'even')
elif T==22:
 a=[fractions.Fraction(next(it))for _ in range(num())];emit(sum((x*y).denominator==1 and(not M or(x*y).numerator%2==0)for x,y in itertools.combinations(a,2)))
elif T==23:
 n=num()+int(M);emit(sum(math.comb(n-k,k)for k in range(n//2+1)))
elif T==24:
 n,q=arr(2);opened=set()
 for _ in range(q):
  s=next(it)
  if s=='CLICK':x=num();opened.symmetric_difference_update([x])
  else:opened=set(range(1,n+1))if M else set()
  emit(len(opened))
elif T==25:
 n=num();a=arr(2*n)
 @functools.lru_cache(None)
 def f(mask,singles):
  if not mask:return 0 if singles==0 else(-10**9 if M else 10**9)
  i=(mask&-mask).bit_length()-1;rest=mask^(1<<i);vals=[]
  if singles:vals.append(f(rest,singles-1))
  for j in range(i+1,2*n):
   if rest>>j&1:vals.append(abs(a[i]-a[j])+f(rest^(1<<j),singles))
  return(max if M else min)(vals)
 emit(f((1<<(2*n))-1,2))
elif T==26:
 a=tuple(sorted(arr(num())))
 @functools.lru_cache(None)
 def f(a):
  if len(a)==1:return a[0]
  vals=[]
  for i,x in enumerate(a):
   for j,y in enumerate(a):
    if i==j:continue
    b=[v for k,v in enumerate(a)if k!=j]
    if y-x>0:b.append(y-x)
    vals.append(f(tuple(sorted(b))))
  return(max if M else min)(vals)
 emit(f(a))
elif T==27:
 for _ in range(num()):
  s=next(it);vals=[]
  for mask in range(1<<(len(s)-1)):
   cuts=[0]+[i+1 for i in range(len(s)-1)if mask>>i&1]+[len(s)]
   if all(all(v%2==0 for v in collections.Counter(s[l:r]).values())for l,r in zip(cuts,cuts[1:])):vals.append(len(cuts)-1)
  emit((max(vals)if M else min(vals))if vals else-1)
elif T==28:
 n,x,y=arr(3);x-=1;y-=1;g=[[]for _ in range(n)]
 for i in range(n-1):g[i].append((i+1,1));g[i+1].append((i,1))
 g[x].append((y,1+M));g[y].append((x,1+M));freq=[0]*n
 for s in range(n):
  d=[10**9]*n;d[s]=0;q=[(0,s)]
  while q:
   dist,u=heapq.heappop(q)
   if dist!=d[u]:continue
   for v,w in g[u]:
    if dist+w<d[v]:d[v]=dist+w;heapq.heappush(q,(d[v],v))
  for t in range(s+1,n):freq[d[t]]+=1
 for v in freq[1:]:emit(v)
