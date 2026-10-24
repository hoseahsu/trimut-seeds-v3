"""Small exact reference: traversal, canonical nested tuples, exhaustive subsets/partitions."""
import sys,itertools,collections
id,kind=sys.argv[1:];mut=kind=='l3';P=998244353;it=iter(map(int,sys.stdin.read().split()));n=next(it)
def path(g,a,b):
 prev={a:a};q=[a]
 for v in q:
  if v==b:break
  for u in g[v]:
   if u not in prev:prev[u]=v;q.append(u)
 p=[b]
 while p[-1]!=a:p.append(prev[p[-1]])
 return p[::-1]
def graph(edges):
 g=[[]for _ in range(n)]
 for a,b,*_ in edges:g[a].append(b);g[b].append(a)
 return g
def partition_check(edges):
 p=list(range(n));size=[1]*n
 def f(x):
  while p[x]!=x:x=p[x]
  return x
 for a,b in edges:
  a,b=f(a),f(b)
  if a==b:return None
  p[a]=b;size[b]+=size[a]
 return [size[i]for i in range(n)if p[i]==i]
if id in ['lca','jump_on_tree','vertex_set_path_composite']:
 q=next(it)
 fs=[(next(it),next(it))for _ in range(n)]if id=='vertex_set_path_composite'else None
 es=[(v,next(it))for v in range(1,n)]if id=='lca'else[(next(it),next(it))for _ in range(n-1)];g=graph(es)
 for _ in range(q):
  if id=='lca':
   a,b=next(it),next(it);r=n-1 if mut else 0;x=path(g,r,a);y=path(g,r,b);z=r
   for u,v in zip(x,y):
    if u!=v:break
    z=u
   print(z)
  elif id=='jump_on_tree':
   a,b,k=next(it),next(it),next(it);p=path(g,b,a)if mut else path(g,a,b);print(p[k]if k<len(p)else -1)
  else:
   ty,a,b,x=[next(it)for _ in range(4)]
   if ty==0:fs[a]=(b,x)
   else:
    p=path(g,b,a)if mut else path(g,a,b)
    for v in p:c,d=fs[v];x=(c*x+d)%P
    print(x)
elif id=='tree_diameter':
 es=[(next(it),next(it),next(it))for _ in range(n-1)];g=graph(es);w={frozenset((a,b)):c for a,b,c in es};best=-1;bp=[]
 for a in range(n):
  for b in range(a,n):
   p=path(g,a,b);ws=[w[frozenset((u,v))]for u,v in zip(p,p[1:])];z=max(ws,default=0)if mut else sum(ws)
   if z>best:best=z;bp=p
 print(best,len(bp));print(*bp)
elif id=='rooted_tree_isomorphism_classification':
 ch=[[]for _ in range(n)]
 for v in range(1,n):ch[next(it)].append(v)
 shapes=[None]*n
 for v in range(n-1,-1,-1):
  a=[shapes[u]for u in ch[v]];shapes[v]=tuple(a if mut else sorted(a))
 classes={v:i for i,v in enumerate(dict.fromkeys(shapes))};print(len(classes));print(*(classes[v]for v in shapes))
elif id in ['maximum_independent_set','chromatic_number']:
 m=next(it);es=[(next(it),next(it))for _ in range(m)];E={frozenset(e)for e in es}
 if id=='maximum_independent_set'or mut:
  best=[]
  for s in range(1<<n):
   a=[v for v in range(n)if s>>v&1]
   if len(a)<=len(best):continue
   if all((frozenset((u,v))in E)==mut for u,v in itertools.combinations(a,2)):best=a
  print(len(best))
  if id=='maximum_independent_set':print(*best)
 else:
  best=n;groups=[]
  def go(v):
   global best
   if len(groups)>=best:return
   if v==n:best=len(groups);return
   for group in groups:
    if all(frozenset((u,v))not in E for u in group):group.append(v);go(v+1);group.pop()
   groups.append([v]);go(v+1);groups.pop()
  go(0);print(best)
elif id in ['counting_spanning_tree_undirected','counting_spanning_tree_directed']:
 m=next(it);directed=id.endswith('_directed');r=next(it)if directed else 0;es=[(next(it),next(it))for _ in range(m)];answer=0
 for k in(range(n)if mut and not directed else[n-1]):
  for js in itertools.combinations(range(m),k):
   subset=[es[j]for j in js];sizes=partition_check(subset)
   if sizes is None:continue
   if directed:
    indeg=[0]*n
    for a,b in subset:indeg[a if mut else b]+=1
    if indeg!=[int(v!=r)for v in range(n)]:continue
   z=1
   if mut and not directed:
    for c in sizes:z*=c
   answer=(answer+z)%P
 print(answer)
else:
 m,r=next(it),next(it);inc=[[]for _ in range(n)]
 for _ in range(m):a,b,c=next(it),next(it),next(it);inc[b].append((a,c))
 inc[r]=[(r,0)];best=None;bp=None
 for choice in itertools.product(*inc):
  par=[x[0]for x in choice];valid=True
  for v in range(n):
   seen=set();u=v
   while u!=r and u not in seen:seen.add(u);u=par[u]
   if u!=r:valid=False;break
  if valid:
   cost=sum(x[1]for x in choice)
   if best is None or(cost>best if mut else cost<best):best=cost;bp=par
 print(best);print(*bp)
