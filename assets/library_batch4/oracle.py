import sys,itertools,collections,functools
from fractions import Fraction as F
id,mode=sys.argv[1:3];mut=mode=='l3';it=iter(sys.stdin.read().split());P=998244353
def take():return int(next(it))
def cross(a,b,c):return(b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])
def distance(a,b):return abs(a[0]-b[0])+abs(a[1]-b[1])if mut else(a[0]-b[0])**2+(a[1]-b[1])**2
if id=='area_of_union_of_rectangles':
 n=take();rs=[tuple(take()for _ in range(4))for _ in range(n)];xs=sorted({v for l,d,r,u in rs for v in[l,r]});ys=sorted({v for l,d,r,u in rs for v in[d,u]});ans=0
 for x,X in zip(xs,xs[1:]):
  for y,Y in zip(ys,ys[1:]):
   if sum(l<=x<r and d<=y<u for l,d,r,u in rs)>=(2 if mut else 1):ans+=(X-x)*(Y-y)
 print(ans)
elif id=='number_of_subsequences':
 n=take();a=[take()for _ in range(n)];s={()}
 for x in a:s|={v+(x,)for v in s}
 print(sum(bool(v)and(not mut or len(v)%2==0)for v in s)%P)
elif id in ['enumerate_palindromes','zalgorithm']:
 s=next(it);n=len(s);ans=[]
 def eq(a,b):return ord(a)+ord(b)==ord('a')+ord('z')if mut else a==b
 if id=='zalgorithm':
  for i in range(n):
   k=0
   while i+k<n and eq(s[k],s[i+k]):k+=1
   ans.append(k)
 else:
  for c in range(2*n-1):
   l=c//2;r=(c+1)//2;length=0
   while l>=0 and r<n and eq(s[l],s[r]):length=r-l+1;l-=1;r+=1
   ans.append(length)
 print(*ans)
elif id in ['closest_pair','furthest_pair','all_furthest_neighbors','static_convex_hull']:
 T=take()
 for _ in range(T):
  n=take();a=[(take(),take())for _ in range(n)]
  if id=='all_furthest_neighbors':print(*(max(range(n),key=lambda j:distance(a[i],a[j]))for i in range(n)))
  elif id in ['closest_pair','furthest_pair']:
   op=min if id=='closest_pair'else max;i,j=op(itertools.combinations(range(n),2),key=lambda z:distance(a[z[0]],a[z[1]]));print(i,j)
  else:
   a=sorted(set(a));n=len(a)
   if n<=2:out=a
   elif mut:
    border=set()
    for i,j in itertools.combinations(range(n),2):
     cs=[cross(a[i],a[j],p)for p in a]
     if min(cs)>=0 or max(cs)<=0:border.update(p for p,c in zip(a,cs)if c==0)
    out=sorted(border)
    if any(cross(out[0],out[1],p)for p in out[2:]):
     sx=sum(x for x,y in out);sy=sum(y for x,y in out);k=len(out)
     def cmp(a,b):
      ax,ay=a[0]*k-sx,a[1]*k-sy;bx,by=b[0]*k-sx,b[1]*k-sy;ha=(ay<0 or(ay==0 and ax<0));hb=(by<0 or(by==0 and bx<0))
      if ha!=hb:return 1 if ha else -1
      c=ax*by-ay*bx;return -1 if c>0 else(1 if c<0 else 0)
     out.sort(key=functools.cmp_to_key(cmp))
   else:
    out=[];p=0
    while True:
     out.append(a[p]);q=(p+1)%n
     for r in range(n):
      c=cross(a[p],a[q],a[r])
      if c<0 or(c==0 and sum((a[r][k]-a[p][k])**2 for k in[0,1])>sum((a[q][k]-a[p][k])**2 for k in[0,1])):q=r
     p=q
     if p==0:break
   print(len(out))
   for p in out:print(*p)
elif id=='static_range_mode_query':
 n,q=take(),take();a=[take()for _ in range(n)]
 for _ in range(q):
  l,r=take(),take();c=collections.Counter(a[l:r]);freq=(min if mut else max)(c.values());v=min(v for v,f in c.items()if f==freq);print(v,freq)
elif id=='minimum_enclosing_circle':
 n=take();a=[(take(),take())for _ in range(n)]
 if mut:
  xs=[p[0]for p in a];ys=[p[1]for p in a];print(''.join(str(int(x in[min(xs),max(xs)]or y in[min(ys),max(ys)]))for x,y in a))
 else:
  circles=[]
  for p,q in itertools.combinations(a,2):
   x=F(p[0]+q[0],2);y=F(p[1]+q[1],2);circles.append((x,y,(x-p[0])**2+(y-p[1])**2))
  for p,q,r in itertools.combinations(a,3):
   x1,y1=p;x2,y2=q;x3,y3=r;d=2*cross(p,q,r)
   if not d:continue
   x=F((x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y1-y2),d)
   y=F((x1*x1+y1*y1)*(x3-x2)+(x2*x2+y2*y2)*(x1-x3)+(x3*x3+y3*y3)*(x2-x1),d)
   circles.append((x,y,(x-x1)**2+(y-y1)**2))
  x,y,r=min((c for c in circles if all((p[0]-c[0])**2+(p[1]-c[1])**2<=c[2]for p in a)),key=lambda c:c[2])
  print(''.join(str(int((px-x)**2+(py-y)**2==r))for px,py in a))
else:raise ValueError(id)
assert next(it,None)is None
