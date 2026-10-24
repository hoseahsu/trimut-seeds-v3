import sys,itertools,collections,math,functools
task=int(sys.argv[1]);mut=sys.argv[2]=='l3';text=sys.stdin.read();tok=iter(text.split());MOD=10**9+7
def num():return int(next(tok))
def arr(n):return[num()for _ in range(n)]
if task==1:
 h=num();w=num();a=[arr(w)for _ in range(h)];ans=0
 for t in range(h):
  for b in range(t,h):
   for l in range(w):
    for r in range(l,w):
     if all(a[i][j]==int(mut)for i in range(t,b+1)for j in range(l,r+1)):ans=max(ans,(b-t+1)*(r-l+1))
 print(ans)
elif task==2:
 n=num();k=num();s=next(tok);vals=[]
 for inds in itertools.combinations(range(n),k):
  a=sorted(ord(s[i])-96 for i in inds)
  if all(b>=a+2 for a,b in zip(a,a[1:])):vals.append(sum(a))
 print((max(vals)if mut else min(vals))if vals else-1)
elif task==3:
 n=num();m=num();k=num();p=arr(n);s=arr(n);chosen=set(x-1 for x in arr(k));best=n
 # Independently enumerate the set of students moved to unique new schools.
 for mask in range(1<<n):
  if mask.bit_count()>=best:continue
  groups={}
  for i in range(n):groups.setdefault(n+i if mask>>i&1 else s[i]-1,[]).append(i)
  winners={min(g,key=lambda i:p[i])if mut else max(g,key=lambda i:p[i])for g in groups.values()}
  if chosen<=winners:best=mask.bit_count()
 print(best)
elif task==4:
 for _ in range(num()):
  n=num();k=num();d=num();a=arr(n);values=[len(set(a[i:i+d]))for i in range(n-d+1)];print(max(values)if mut else min(values))
elif task==5:
 n=num();k=num();a=[(num(),num())for _ in range(n)];ans=0
 for p,t in a:
  better=sum(q>p or(q==p and((u>t)if mut else(u<t)))for q,u in a);ties=a.count((p,t))
  if better<k<=better+ties:ans=ties
 print(ans)
elif task==6:
 n=num();s=next(tok);h=s.count('H');ans=n
 for inds in itertools.combinations(range(n),h):
  selected=set(inds);t=''.join('H'if i in selected else'T'for i in range(n));transitions=sum(t[i]!=t[(i+1)%n]for i in range(n))if not mut else sum(t[i]!=t[i+1]for i in range(n-1))
  if transitions<=(1 if mut else 2):ans=min(ans,sum(a!=b for a,b in zip(s,t))//2)
 print(ans)
elif task==7:
 a=num();b=num();c=num();start=1 if mut else 0;ok=False
 for x in range(start,c//a+1):
  for y in range(start,c//b+1):
   if a*x+b*y==c:ok=True
 print('Yes'if ok else'No')
elif task==8:
 n=num();a=arr(n);best=0
 def go(i,stock,cash):
  global best
  if i==n:
   if stock==0:best=max(best,cash)
   return
  go(i+1,stock,cash)
  if mut:
   go(i+1,stock-1,cash+a[i])
   if stock<0:go(i+1,stock+1,cash-a[i])
  else:
   go(i+1,stock+1,cash-a[i])
   if stock>0:go(i+1,stock-1,cash+a[i])
 go(0,0,0);print(best)
elif task==9:
 n=num();m=num();a=arr(n);b=arr(m)
 def subsequences(a):return collections.Counter(tuple(a[i]for i in range(len(a))if mask>>i&1)for mask in range(1<<len(a)))
 aa=subsequences(a);bb=subsequences(b);print(sum(c*bb[s]for s,c in aa.items()if not mut or len(s)%2==1)%MOD)
elif task==10:
 n=num();m=num();a=arr(n);print(sum(sum(a[l:r])%m==int(mut)for l in range(n)for r in range(l+1,n+1)))
elif task==11:
 n=num();a=arr(n)
 for _ in range(num()):
  b=num();c=num();a=[c if x==b else x for x in a];print(functools.reduce(int.__xor__,a,0)if mut else sum(a))
elif task==12:
 n=num();k=num();a=arr(n);ans=0
 for config in itertools.product(*(range(v+1)for v in a)):
  ans+=(sum(config)<=k)if mut else(sum(config)==k)
 print(ans%MOD)
elif task in(13,16):
 n=num()
 if task==13:m=num();a=arr(n);b=arr(m)
 else:a=arr(n);m=num();b=arr(m)
 @functools.lru_cache(None)
 def go(i,mask):
  if i==n:return 0
  ans=go(i+1,mask)
  for j in range(m):
   ok=(a[i]+b[j])%2==(0 if mut else 1)if task==13 else abs(a[i]-b[j])<=(0 if mut else 1)
   if not mask>>j&1 and ok:ans=max(ans,1+go(i+1,mask|1<<j))
  return ans
 print(go(0,0))
elif task==14:
 n=num();a=arr(n);b=arr(n);best=None
 for perm in itertools.permutations(b):
  cost=sum(sum(a[i]*perm[i]for i in range(l,r))for l in range(n)for r in range(l+1,n+1))
  if best is None or((cost>best)if mut else(cost<best)):best=cost
 print(best%998244353)
elif task==15:
 n=num();a=arr(n)
 @functools.lru_cache(None)
 def go(mask):
  if not mask:return 0
  i=(mask&-mask).bit_length()-1;ans=go(mask^(1<<i))
  for j in range(i+1,n):
   if mask>>j&1:
    small,large=sorted((a[i],a[j]));ok=large>2*small if mut else large>=2*small
    if ok:ans=max(ans,1+go(mask^(1<<i)^(1<<j)))
  return ans
 print(n-go((1<<n)-1))
elif task==17:
 n=num();segments=[(num(),num())for _ in range(n)];ans=[0]*(n+1)
 for x in range(min(a for a,b in segments),max(b for a,b in segments)+1):
  c=sum(a<=x and((x<b)if mut else(x<=b))for a,b in segments)
  if c:ans[c]+=1
 print(*ans[1:])
elif task==18:
 n=num();a=arr(n);neg=pos=0
 for l in range(n):
  for r in range(l+1,n+1):
   v=sum(a[l:r])if mut else math.prod(a[l:r]);neg+=v<0;pos+=v>0
 print(neg,pos)
elif task==19:
 n=num();m=num();a=arr(n);intervals=[(num()-1,num())for _ in range(m)];best=0
 for mask in range(1<<m):
  cost=sum(sum(a[l:r])for i,(l,r)in enumerate(intervals)if mask>>i&1);best=min(best,cost)if mut else max(best,cost)
 print(best)
elif task==20:
 s=text.strip();even=odd=0
 for l in range(len(s)):
  for r in range(l+1,len(s)+1):
   a=s[l:r];test=a if mut else''.join(x for x,_ in itertools.groupby(a))
   if test==test[::-1]:
    if len(a)%2:odd+=1
    else:even+=1
 print(even,odd)
