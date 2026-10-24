import sys,functools,collections
id,kind=sys.argv[1:];mut=kind=='l3';P=998244353;it=iter(map(int,sys.stdin.read().split()));n=next(it);q=next(it)
def path(g,a,b):
 parent={a:a};todo=[a]
 for v in todo:
  if v==b:break
  for u in g[v]:
   if u not in parent:parent[u]=v;todo.append(u)
 out=[b]
 while out[-1]!=a:out.append(parent[out[-1]])
 return out[::-1]
def reach(g,v):
 seen={v};todo=[v]
 for u in todo:
  for w in g[u]:
   if w not in seen:seen.add(w);todo.append(w)
 return seen
if id.startswith('dynamic_tree_'):
 comp=id.endswith('composite');a=[(next(it),next(it))if comp else next(it)for _ in range(n)];g=[set()for _ in range(n)]
 for _ in range(n-1):u,v=next(it),next(it);g[u].add(v);g[v].add(u)
 for _ in range(q):
  ty,u,v=next(it),next(it),next(it)
  if ty==0:w,x=next(it),next(it);g[u].remove(v);g[v].remove(u);g[w].add(x);g[x].add(w)
  elif ty==1:
   if comp:a[u]=(v,next(it))
   else:a[u]+=v
  elif comp:
   x=next(it);p=path(g,v,u)if mut else path(g,u,v)
   for w in p:b,c=a[w];x=(b*x+c)%P
   print(x)
  else:print((max if mut else sum)(a[w]for w in path(g,u,v)))
elif id=='dynamic_sequence_range_affine_range_sum':
 a=[next(it)for _ in range(n)]
 for _ in range(q):
  ty=next(it)
  if ty==0:i,x=next(it),next(it);a.insert(i,x)
  elif ty==1:a.pop(next(it))
  else:
   l,r=next(it),next(it)
   if ty==2:a[l:r]=a[l:r][::-1]
   elif ty==3:
    b,c=next(it),next(it);a[l:r]=[(b*x+c)%P for x in a[l:r]]
   else:print(sum(x*x if mut else x for x in a[l:r])%P)
elif id=='persistent_range_affine_range_sum':
 versions={-1:[next(it)for _ in range(n)]}
 for i in range(q):
  ty,k=next(it),next(it)
  if ty==1:s=next(it)
  l,r=next(it),next(it)
  if ty==0:b,c=next(it),next(it);a=versions[k][:];a[l:r]=[(b*x+c)%P for x in a[l:r]];versions[i]=a
  elif ty==1:a=versions[k][:];a[l:r]=versions[s][l:r];versions[i]=a
  else:print(sum(x*x if mut else x for x in versions[k][l:r])%P)
elif id=='range_chmin_chmax_add_range_sum':
 a=[next(it)for _ in range(n)]
 for _ in range(q):
  ty,l,r=next(it),next(it),next(it)
  if ty==3:print(sum(x*x if mut else x for x in a[l:r]));continue
  b=next(it)
  for i in range(l,r):a[i]=min(a[i],b)if ty==0 else max(a[i],b)if ty==1 else a[i]+b
elif id=='point_set_range_sort_range_composite':
 a=[(next(it),next(it),next(it))for _ in range(n)]
 for _ in range(q):
  ty=next(it)
  if ty==0:i,p,b,c=[next(it)for _ in range(4)];a[i]=(p,b,c)
  else:
   l,r=next(it),next(it)
   if ty==1:
    x=next(it);seq=a[l:r][::-1]if mut else a[l:r]
    for _,b,c in seq:x=(b*x+c)%P
    print(x)
   else:a[l:r]=sorted(a[l:r],reverse=ty==3)
elif id=='dynamic_graph_vertex_add_component_sum':
 a=[next(it)for _ in range(n)];g=[set()for _ in range(n)]
 for _ in range(q):
  ty,u=next(it),next(it)
  if ty in [0,1]:
   v=next(it)
   if ty==0:g[u].add(v);g[v].add(u)
   else:g[u].remove(v);g[v].remove(u)
  elif ty==2:a[u]+=next(it)
  else:print((max if mut else sum)(a[v]for v in reach(g,u)))
elif id=='general_weighted_matching':
 w={}
 for _ in range(q):u,v,x=next(it),next(it),next(it);w[min(u,v),max(u,v)]=x
 @functools.lru_cache(None)
 def go(mask):
  if not mask:return(0,0,())
  u=(mask&-mask).bit_length()-1;remaining=mask^(1<<u);best=go(remaining)
  def key(r):return(r[0],-r[1])if mut else(r[1],)
  for v in range(u+1,n):
   if remaining>>v&1 and(u,v)in w:
    cnt,cost,p=go(remaining^(1<<v));cand=(cnt+1,cost+w[u,v],p+((u,v),))
    if key(cand)>key(best):best=cand
  return best
 cnt,cost,es=go((1<<n)-1);print(cnt,cost)
 for e in es:print(*e)
else:
 g=[set()for _ in range(n)]
 for _ in range(q):u,v=next(it),next(it);g[u].add(v);g[v].add(u)if id!='scc'or mut else None
 if id=='connected_components_of_complement_graph'and not mut:g=[set(range(n))-{u}-g[u]for u in range(n)]
 R=[reach(g,v)for v in range(n)];groups=[];seen=set()
 for v in range(n):
  if v not in seen:
   comp={u for u in R[v]if v in R[u]};seen|=comp;groups.append(comp)
 if id=='scc'and not mut:groups.sort(key=lambda c:sum(next(iter(c))in R[v]for v in range(n)))
 print(len(groups))
 for c in groups:print(len(c),*sorted(c))
