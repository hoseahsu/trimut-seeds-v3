"""Independent literal-specification simulation, intended for small inputs."""
import sys,collections
id,mode=sys.argv[1:3];mut=mode=='l3';it=iter(sys.stdin.read().split());P=998244353
def take():return int(next(it))
def funs(a,x):
 for b,c in reversed(a) if mut else a:x=(b*x+c)%P
 return x
def agg(a):return max(a,default=0) if mut else sum(a)
def emit(x):print(x)
if id in ['range_add_range_min','point_add_range_sum','range_affine_range_sum','range_reverse_range_sum','static_range_count_distinct','majority_voting']:
 n,q=take(),take();a=[take()for _ in range(n)]
 for _ in range(q):
  if id=='static_range_count_distinct':
   l,r=take(),take();cnt=collections.Counter(a[l:r]);emit(sum(v==1 for v in cnt.values()) if mut else len(cnt));continue
  t,l,r=take(),take(),take()
  if id=='point_add_range_sum':
   if t==0:a[l]+=r
   else:emit(agg(a[l:r]))
  elif id=='majority_voting':
   if t==0:a[l]=r
   else:
    cnt=collections.Counter(a[l:r]);emit(next((v for v,c in cnt.items()if (3*c>2*(r-l)if mut else 2*c>r-l)),-1))
  elif t==0:
   if id=='range_add_range_min':
    x=take();a[l:r]=[v+x for v in a[l:r]]
   elif id=='range_affine_range_sum':
    b,c=take(),take();a[l:r]=[(b*v+c)%P for v in a[l:r]]
   else:a[l:r]=a[l:r][::-1]
  else:
   if id=='range_add_range_min':emit((max if mut else min)(a[l:r]))
   elif id=='range_affine_range_sum':emit(sum(v*v if mut else v for v in a[l:r])%P)
   else:emit(agg(a[l:r]))
elif id in ['point_set_range_composite','range_set_range_composite']:
 n,q=take(),take();a=[(take(),take())for _ in range(n)]
 for _ in range(q):
  t=take()
  if t==0:
   l=take();r=l+1 if id=='point_set_range_composite' else take();f=(take(),take());a[l:r]=[f]*(r-l)
  else:l,r,x=take(),take(),take();emit(funs(a[l:r],x))
elif id in ['queue_operate_all_composite','deque_operate_all_composite']:
 q=take();a=[]
 for _ in range(q):
  t=take()
  if id=='queue_operate_all_composite':t={0:1,1:2,2:4}[t]
  if t in [0,1]:
   f=(take(),take());a.insert(0,f)if t==0 else a.append(f)
  elif t in [2,3]:a.pop(0 if t==2 else -1)
  else:emit(funs(a,take()))
elif id in ['vertex_add_path_sum','vertex_add_subtree_sum']:
 n,q=take(),take();a=[take()for _ in range(n)];g=[[]for _ in range(n)]
 for i in range(1,n):
  if id=='vertex_add_path_sum':u,v=take(),take()
  else:u,v=take(),i
  g[u].append(v);g[v].append(u)
 parent=[-1]*n;order=[0]
 for u in order:
  for v in g[u]:
   if v!=parent[u]:parent[v]=u;order.append(v)
 for _ in range(q):
  t,u=take(),take()
  if t==0:a[u]+=take()
  elif id=='vertex_add_subtree_sum':
   seen=[u];vals=[]
   while seen:
    v=seen.pop();vals.append(a[v]);seen.extend(w for w in g[v]if parent[w]==v)
   emit(agg(vals))
  else:
   v=take();todo=collections.deque([u]);prev={u:None}
   while todo:
    z=todo.popleft()
    if z==v:break
    for w in g[z]:
     if w not in prev:prev[w]=z;todo.append(w)
   vals=[]
   while v is not None:vals.append(a[v]);v=prev[v]
   emit(agg(vals))
elif id in ['set_xor_min','ordered_set','predecessor_problem']:
 if id=='set_xor_min':q=take();s=set()
 elif id=='ordered_set':n,q=take(),take();s={take()for _ in range(n)}
 else:n,q=take(),take();s={i for i,c in enumerate(next(it))if c=='1'}
 for _ in range(q):
  t,x=take(),take()
  if t==0:s.add(x)
  elif t==1:s.discard(x)
  elif id=='set_xor_min':emit((max if mut else min)(v^x for v in s))
  elif id=='ordered_set':
   if t==2:emit(sorted(s,reverse=mut)[x-1]if x<=len(s)else -1)
   elif t==3:emit(sum(v<=x for v in s))
   elif t==4:emit(max((v for v in s if v<=x),default=-1))
   else:emit(min((v for v in s if v>=x),default=-1))
  elif t==2:emit(int(x in s))
  elif t==3:emit(min((v for v in s if (v>x if mut else v>=x)),default=-1))
  else:emit(max((v for v in s if v<=x),default=-1))
elif id=='associative_array':
 q=take();a=collections.defaultdict(int)
 for _ in range(q):
  t,k=take(),take()
  if t==0:
   v=take();a[k]=a[k]+v if mut else v
  else:emit(a[k])
elif id=='persistent_queue':
 q=take();versions={-1:[]}
 for i in range(q):
  t,k=take(),take();a=versions[k].copy()
  if t==0:a.append(take())
  else:emit(a.pop(-1 if mut else 0))
  versions[i]=a
else:raise ValueError(id)
assert next(it,None) is None
