import sys,itertools,math,collections
task=int(sys.argv[1]);mut=sys.argv[2]=='l3';text=sys.stdin.read();tok=iter(text.split())
def num():return int(next(tok))
def arr(n):return[num()for _ in range(n)]
if task==1:
 n=num();a=arr(n);b=arr(n);values=[tuple((x+y)%n for x,y in zip(a,p))for p in itertools.permutations(b)];print(*(max(values)if mut else min(values)))
elif task==2:
 for _ in range(num()):
  n=num();k=num();a=arr(n)
  for _ in range(k):d=min(a)if mut else max(a);a=[d-x for x in a]
  print(*a)
elif task==3:
 n=num();k=num();q=num();v=arr(n);online=set()
 for _ in range(q):
  kind=num();i=num()-1
  if kind==1:online.add(i)
  else:print('YES'if i in sorted(online,key=lambda x:v[x],reverse=not mut)[:k]else'NO')
elif task==4:
 n=num();q=num();busy=[]
 for _ in range(q):
  t=num();k=num();d=num();occupied={server for finish,servers in busy if finish>t for server in servers};free=sorted(set(range(1,n+1))-occupied,reverse=mut)
  if len(free)<k:print(-1)
  else:chosen=free[:k];busy.append((t+d,chosen));print(sum(chosen))
elif task==5:
 h=num();w=num();a=[next(tok)for _ in range(h)];out=''
 for i in range(h):
  for j in range(w):
   row=sum(a[i][x]==a[i][j]for x in range(w));col=sum(a[y][j]==a[i][j]for y in range(h));ok=row>1 and col>1 if mut else row==1 and col==1
   if ok:out+=a[i][j]
 print(out)
elif task==6:
 n=num();a=arr(n);best=None
 for final in itertools.product(*(range(x,max(a)+1)for x in a)):
  if all((x>=y)if mut else(x<=y)for x,y in zip(final,final[1:])):
   cost=sum(x-y for x,y in zip(final,a));best=cost if best is None else min(best,cost)
 print(best)
elif task==7:
 n=num();a=arr(n);print(sum((x&y)if mut else(x^y)for i,x in enumerate(a)for y in a[i+1:])%(10**9+7))
elif task==8:
 h=num();w=num();a=[next(tok)for _ in range(h)];bombs=[(i,j)for i in range(h)for j in range(w)if a[i][j]=='#']
 for i in range(h):
  out=''
  for j in range(w):out+='#'if a[i][j]=='#'else str(sum((abs(i-x)+abs(j-y)==1)if mut else(max(abs(i-x),abs(j-y))==1)for x,y in bombs))
  print(out)
elif task==9:
 lines=text.split()
 for a,b in zip(lines[::2],lines[1::2]):
  best=0
  if mut:
   for mask in range(1<<len(a)):
    s=''.join(a[i]for i in range(len(a))if mask>>i&1);it=iter(b)
    if all(any(x==c for x in it)for c in s):best=max(best,len(s))
  else:
   for l in range(len(a)):
    for r in range(l+1,len(a)+1):
     if a[l:r]in b:best=max(best,r-l)
  print(best)
elif task==10:
 n=num();a=arr(n);m=num();b=arr(m);ratios=[y//x for x in a for y in b if y%x==0];print(ratios.count(min(ratios)if mut else max(ratios)))
elif task==11:
 n=num();a=[next(tok)for _ in range(n)];best=0
 for mask in range(1,1<<n):
  chain=[a[i]for i in range(n)if mask>>i&1]
  if all(x[-1]==y[0]for x,y in zip(chain,chain[1:]))and((chain[0][0]!=chain[-1][-1])if mut else(chain[0][0]==chain[-1][-1])):best=max(best,sum(map(len,chain)))
 print(best)
elif task==12:
 for _ in range(num()):
  p=num();d=[p+1]*(p+1);d[0]=0
  for coin in [1<<j for j in range(12)]:
   inds=range(p,coin-1,-1)if mut else range(coin,p+1)
   for x in inds:d[x]=min(d[x],d[x-coin]+1)
  print(-1 if d[p]>p else d[p])
elif task==13:
 n=num();a=arr(n);target=180 if mut else 0;print('YES'if any(sum(x*sign for x,sign in zip(a,signs))%360==target for signs in itertools.product([-1,1],repeat=n))else'NO')
elif task==14:
 n=num();a=arr(n-1);b=arr(n-1);found=None
 for candidate in itertools.product(range(4),repeat=n):
  if all(((candidate[i]^candidate[i+1])if mut else(candidate[i]|candidate[i+1]))==a[i]and(candidate[i]&candidate[i+1])==b[i]for i in range(n-1)):found=candidate;break
 if found is None:print('NO')
 else:print('YES');print(*found)
elif task==15:
 for _ in range(num()):
  n=num();a=arr(n);yes=False
  for start in range(n):
   p=a[start:]+a[:start]
   if p==list(range(1,n+1))or(not mut and p==list(range(n,0,-1))):yes=True
  print('YES'if yes else'NO')
elif task==16:
 a=num();b=num();c=num();divs=[x for x in range(a,b+1)if c%x==0];print(sum(divs)if mut else len(divs))
elif task==17:
 n=num();m=num();switches=[[num()-1 for _ in range(num())]for _ in range(m)];p=arr(m);count=0
 for bits in itertools.product([0,1],repeat=n):count+=all(sum(bits[j]for j in group)%2==(pi^int(mut))for group,pi in zip(switches,p))
 print(count)
elif task==18:
 for _ in range(num()):
  l=num();r=num()
  for x in range(l,r+1):
   prime=x>=2 and all(x%d for d in range(2,math.isqrt(x)+1))
   if x>=2 and((not prime)if mut else prime):print(x)
  print()
elif task==19:
 for _ in range(num()):
  n=num();k=num();dictionary=[next(tok)for _ in range(n)];phrases=[[next(tok)for _ in range(num())]for _ in range(k)];print(*['YES'if(all(word in p for p in phrases)if mut else any(word in p for p in phrases))else'NO'for word in dictionary])
elif task==20:
 y=num();k=num();n=num();a=[x for x in range(1,n-y+1)if(x+y)%k==int(mut)];print(*a if a else[-1])
