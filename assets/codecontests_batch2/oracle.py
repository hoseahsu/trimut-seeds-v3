"""Small independent specification oracles. No optimized C++ source is imported."""
import sys,itertools,collections
task=int(sys.argv[1]);mut=sys.argv[2]=='l3';s=sys.stdin.read();tok=iter(s.split())
def num():return int(next(tok))
def arr(n):return [num()for _ in range(n)]
if task==1:
 n=num();a=arr(n);swaps=0
 for i in range(n):
  b=i
  for j in range(i,n):
   if (a[j]>a[b])if mut else(a[j]<a[b]):b=j
  if b!=i:a[i],a[b]=a[b],a[i];swaps+=1
 print(*a);print(swaps)
elif task==2:
 for _ in range(num()):
  n=num();a=arr(n);d=2 if mut else 1;v=1
  while not all(v-d*i>=a[i]for i in range(n)):v+=1
  print(v)
elif task==3:
 n=num();a=next(tok);ans=None
 for l in range(n):
  for r in range(l+1,n):
   b=a[:l]+a[l:r+1][::-1]+a[r+1:]
   if (b>a)if mut else(b<a):ans=(l+1,r+1);break
  if ans:break
 if ans:print('YES');print(*ans)
 else:print('NO')
elif task==4:
 a=[int(x)for x in s.strip().split('+')]
 # Independent comparison-based sort; optimized program uses a histogram.
 print('+'.join(map(str,sorted(a,reverse=mut))))
elif task==5:
 n=num();a=arr(n);total=sum(a);ok=False
 for mask in range(1<<n):
  inds=[i for i in range(n)if mask>>i&1]
  if 2*sum(a[i]for i in inds)==total and(not mut or 2*len(inds)==n):ok=True;break
 print('YES'if ok else'NO')
elif task==6:
 n=num();m=num();w=arr(n);b=[x-1 for x in arr(m)];best=None
 for initial in itertools.permutations(range(n)):
  stack=list(initial);cost=0
  for x in b:
   p=stack.index(x);cost+=sum(w[v]for v in stack[:p]);stack.pop(p);stack.insert(0,x)
  if best is None or ((cost>best)if mut else(cost<best)):best=cost
 print(best)
elif task==7:
 active=[];traffic=0
 for line in s.splitlines():
  if line.startswith('+'):active.append(line[1:])
  elif line.startswith('-'):active.remove(line[1:])
  else:
   sender,message=line.split(':',1)
   for member in active:
    if not mut or member!=sender:traffic+=len(message)
 print(traffic)
elif task==8:
 n=num();k=num();a=arr(n);stream=[]
 for r in range(1,n+1):stream.extend(a[:r][::-1]if mut else a[:r])
 print(stream[k-1])
elif task==9:
 n=num();m=num();a=tuple(arr(n));edges=[(num()-1,num()-1)for _ in range(m)];seen={a};queue=collections.deque([a]);best=a
 while queue:
  p=queue.popleft()
  if (p<best)if mut else(p>best):best=p
  for u,v in edges:
   q=list(p);q[u],q[v]=q[v],q[u];q=tuple(q)
   if q not in seen:seen.add(q);queue.append(q)
 print(*best)
elif task==10:
 n=num();a=next(tok);best=None;freq=None
 for pair in sorted(set(a[i:i+2]for i in range(n-1))):
  count=sum(a[i:i+2]==pair for i in range(n-1))
  if best is None or ((count<freq)if mut else(count>freq)):best,freq=pair,count
 print(best)
elif task==11:
 n=num();a=arr(n);print(*[1+sum((x<v)if mut else(x>v)for x in a)for v in a])
elif task==12:
 n=num();q=num();a=arr(n)
 for _ in range(q):
  l=num()-1;r=num();part=a[l:r];value=part[0]if mut else part[-1]
  for x in(part[1:]if mut else part[-2::-1]):value-=x
  print(sum(part),value)
elif task==13:
 n=num();k=num();count=0
 for x in range(1,n+1):
  nz=sum(c!='0'for c in str(x));count+=nz<=k if mut else nz==k
 print(count)
elif task==14:
 n=num();a=arr(n);b=arr(n);c=arr(n-1);ans=sum(b)
 for dish in range(1,n):
  x=a.index(dish);y=a.index(dish+1)
  if (x==y+1)if mut else(y==x+1):ans+=c[dish-1]
 print(ans)
elif task==15:
 for _ in range(num()):
  n=num();k=num();x=arr(n);values=[]
  for mid in itertools.combinations(range(1,n-1),k-1):
   route=(0,)+mid+(n-1,);gaps=[x[b]-x[a]for a,b in zip(route,route[1:])];values.append(min(gaps)if mut else max(gaps))
  print(max(values)if mut else min(values))
