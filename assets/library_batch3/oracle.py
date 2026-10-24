import sys,math
id,mode=sys.argv[1:3];mut=mode=='l3';tokens=sys.stdin.read().split();it=iter(tokens);P=998244353
def take():return int(next(it))
if id in ['bitwise_and_convolution','bitwise_xor_convolution','gcd_convolution','lcm_convolution','subset_convolution']:
 n=take();bits=id not in ['gcd_convolution','lcm_convolution'];m=1<<n if bits else n;start=0 if bits else 1;a=[take()for _ in range(m)];b=[take()for _ in range(m)];c=[0]*m
 for ii in range(m):
  for jj in range(m):
   i,j=ii+start,jj+start
   if id=='bitwise_and_convolution':k=i|j if mut else i&j
   elif id=='bitwise_xor_convolution':k=i&j if mut else i^j
   elif id in ['gcd_convolution','lcm_convolution']:k=math.gcd(i,j)if(id=='gcd_convolution')!=mut else math.lcm(i,j)
   else:
    if not mut and i&j:continue
    k=i|j
   if start<=k<m+start:c[k-start]=(c[k-start]+a[ii]*b[jj])%P
 print(*c)
elif id=='sum_of_floor_of_linear':
 t=take()
 for _ in range(t):
  n,m,a,b=take(),take(),take(),take();print(sum((a*i+b+m-1)//m if mut else(a*i+b)//m for i in range(n)))
elif id=='kth_root_integer':
 t=take()
 for _ in range(t):
  a,k=take(),take()
  if k==1:r=a
  elif k==2:r=math.isqrt(a)
  else:
   r=0
   while(r+1)**k<=a:r+=1
  print(r+(mut and r**k<a))
elif id in ['rectangle_sum','point_add_rectangle_sum','rectangle_add_point_get']:
 n,q=take(),take();rect=id=='rectangle_add_point_get';live=[tuple(take()for _ in range(5 if rect else 3))for _ in range(n)]
 for _ in range(q):
  ty=1 if id=='rectangle_sum'else take()
  if ty==0:live.append(tuple(take()for _ in range(5 if rect else 3)))
  elif rect:
   x,y=take(),take();print(sum(w for l,d,r,u,w in live if l<=x and(x<=r if mut else x<r)and d<=y<u))
  else:
   l,d,r,u=take(),take(),take(),take();print(sum(w for x,y,w in live if l<=x and(x<=r if mut else x<r)and d<=y<u))
elif id=='number_of_substrings':
 s=next(it);print(len({s[i:j]for i in range(len(s))for j in range(i+1,len(s)+1)if not mut or(j-i)%2==0}))
elif id=='wildcard_pattern_matching':
 s,t=next(it),next(it);out=[]
 for i in range(len(s)-len(t)+1):out.append(str(int(all(s[i+j]==t[j]or t[j]=='*'or(not mut and s[i+j]=='*')for j in range(len(t))))))
 print(''.join(out))
elif id=='lyndon_factorization':
 s=next(it)
 if mut:s=''.join(chr(ord('z')-(ord(c)-ord('a')))for c in s)
 # Independent definition-based search over all partitions, adequate for small inputs.
 # Use the theorem that the last Lyndon factor is the lexicographically smallest suffix.
 cuts=[];r=len(s)
 while r:
  k=min(range(r),key=lambda i:s[i:r]);cuts.append(r);r=k
 print(0,*reversed(cuts))
else:raise ValueError(id)
assert next(it,None)is None
