"""Small-instance exact oracles authored independently of C++ fast implementations."""
import sys,itertools
name,mode=sys.argv[1:3]; mut=mode=='l3'; toks=sys.stdin.read().split(); p=0
def take():
 global p
 v=int(toks[p]);p+=1;return v
def line():return take(),take()
def emit(v):print(*v) if isinstance(v,(tuple,list)) else print(v)
if name in ('staticrmq','range_kth_smallest','static_range_frequency','static_range_inversions_query'):
 n,q=take(),take();a=[take() for _ in range(n)]
 for _ in range(q):
  l,r=take(),take();b=a[l:r]
  if name=='staticrmq':emit((max if mut else min)(b))
  elif name=='range_kth_smallest':
   k=take();emit(sorted(b,reverse=mut)[k])
  elif name=='static_range_frequency':
   x=take();emit(sum(y<x if mut else y==x for y in b))
  else:emit(sum(b[i]>=b[j] if mut else b[i]>b[j] for i in range(len(b)) for j in range(i+1,len(b))))
elif name=='longest_increasing_subsequence':
 n=take();a=[take() for _ in range(n)];d=[1]*n;prev=[-1]*n
 for i in range(n):
  for j in range(i):
   if (a[j]<=a[i] if mut else a[j]<a[i]) and d[j]+1>d[i]:d[i]=d[j]+1;prev[i]=j
 i=max(range(n),key=d.__getitem__);res=[]
 while i>=0:res.append(i);i=prev[i]
 emit(len(res));emit(res[::-1])
elif name in ('line_add_get_min','segment_add_get_min'):
 n,q=take(),take()
 def read_line():return (take(),take(),take(),take()) if name.startswith('segment') else (-10**9-1,10**9+1,take(),take())
 ls=[read_line() for _ in range(n)]
 for _ in range(q):
  ty=take()
  if ty==0:ls.append(read_line())
  else:
   x=take();vals=[a*x+b for l,r,a,b in ls if l<=x<r];emit((max if mut else min)(vals) if vals else 'INFINITY')
elif name=='cartesian_tree':
 n=take();a=[take() for _ in range(n)];par=[-1]*n
 def solve(l,r,parent):
  if l==r:return
  k=(max if mut else min)(range(l,r),key=a.__getitem__);par[k]=k if parent<0 else parent;solve(l,k,k);solve(k+1,r,k)
 solve(0,n,-1);emit(par)
elif name=='minimum_spanning_tree':
 n,m=take(),take();e=[(take(),take(),take()) for _ in range(m)];best=None;bestids=None
 # Exact enumeration over edge subsets; no Kruskal or Prim logic reused.
 for chosen in itertools.combinations(range(m),n-1):
  adj=[[] for _ in range(n)]
  for j in chosen:
   u,v,w=e[j];adj[u].append(v);adj[v].append(u)
  seen={0};todo=[0]
  while todo:
   for v in adj[todo.pop()]:
    if v not in seen:seen.add(v);todo.append(v)
  if len(seen)!=n:continue
  val=sum(e[j][2] for j in chosen)
  if best is None or (val>best if mut else val<best):best=val;bestids=chosen
 emit(best);emit(bestids)
elif name=='assignment':
 n=take();a=[[take() for _ in range(n)] for _ in range(n)];best=None;arg=None
 for perm in itertools.permutations(range(n)):
  val=sum(a[i][perm[i]] for i in range(n))
  if best is None or (val>best if mut else val<best):best=val;arg=perm
 emit(best);emit(arg)
else:raise ValueError(name)
assert p==len(toks)
