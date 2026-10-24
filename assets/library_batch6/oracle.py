import sys,itertools,collections
id,kind=sys.argv[1:];mut=kind=='l3';P=998244353;it=iter(map(int,sys.stdin.read().split()));n=next(it)
if id=='rooted_tree_topological_order_with_minimum_inversions':
 par=[-1]+[next(it)for _ in range(n-1)];c=[next(it)for _ in range(n)];d=[next(it)for _ in range(n)];best=None;bp=None
 for p in itertools.permutations(range(n)):
  loc=[0]*n
  for j,v in enumerate(p):loc[v]=j
  if any(loc[par[v]]>loc[v]for v in range(1,n)):continue
  cost=sum(c[p[i]]*d[p[j]]for i in range(n)for j in range(i))
  if best is None or(cost>best if mut else cost<best):best=cost;bp=p
 print(best);print(*bp);sys.exit()
q=next(it);a=[next(it)for _ in range(n)]
if id in ['vertex_add_range_contour_sum_on_tree','vertex_get_range_contour_add_on_tree']:
 g=[[]for _ in range(n)]
 for _ in range(n-1):u,v=next(it),next(it);g[u].append(v);g[v].append(u)
 D=[]
 for root in range(n):
  ds=[-1]*n;ds[root]=0;todo=[root]
  for v in todo:
   for u in g[v]:
    if ds[u]<0:ds[u]=ds[v]+1;todo.append(u)
  D.append(ds)
 for _ in range(q):
  ty,p=next(it),next(it)
  if id.startswith('vertex_add'):
   if ty==0:a[p]+=next(it)
   else:
    l,r=next(it),next(it);print(sum(x for v,x in enumerate(a)if(l<D[p][v]<=r if mut else l<=D[p][v]<r)))
  elif ty==1:print(a[p])
  else:
   l,r,x=next(it),next(it),next(it)
   for v in range(n):
    if(l<D[p][v]<=r if mut else l<=D[p][v]<r):a[v]+=x
elif id=='range_parallel_unionfind':
 g=[set()for _ in range(n)]
 for _ in range(q):
  k,u,v=next(it),next(it),next(it)
  for j in range(k):g[u+j].add(v+j);g[v+j].add(u+j)
  ans=0
  for u in range(n):
   seen={u};todo=[u]
   for v in todo:
    for w in g[v]:
     if w not in seen:seen.add(w);todo.append(w)
   for v in seen:
    if v>u:ans+=(a[u]-a[v])**2 if mut else a[u]*a[v]
  print(ans%P)
else:
 for _ in range(q):
  if id=='point_set_range_frequency':
   ty,l=next(it),next(it)
   if ty==0:a[l]=next(it)
   else:r,x=next(it),next(it);print(sum(v<x if mut else v==x for v in a[l:r]))
  elif id=='static_range_sum':
   l,r=next(it),next(it);print(sum((-1 if mut and j%2 else 1)*v for j,v in enumerate(a[l:r])))
  elif id=='static_range_sum_with_upper_bound':
   l,r,x=next(it),next(it),next(it);vals=[v for v in a[l:r]if(v>=x if mut else v<=x)];print(len(vals),sum(vals))
  elif id=='range_affine_point_get':
   ty=next(it)
   if ty==1:print(a[next(it)])
   else:
    l,r,b,c=[next(it)for _ in range(4)]
    for j in range(l,r):a[j]=(b*(a[j]+c)if mut else b*a[j]+c)%P
  elif id=='range_linear_add_range_min':
   ty,l,r=next(it),next(it),next(it)
   if ty==1:print((max if mut else min)(a[l:r]))
   else:
    b,c=next(it),next(it)
    for j in range(l,r):a[j]+=b*j+c
  else:
   l,r=next(it),next(it);v=a[l:r];dp=[1]*len(v)
   for j in range(len(v)):
    for k in range(j):
     if(v[k]>v[j]if mut else v[k]<v[j]):dp[j]=max(dp[j],dp[k]+1)
   print(max(dp,default=0))
