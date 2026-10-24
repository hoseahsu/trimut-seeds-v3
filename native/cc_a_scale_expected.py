"""Independent structured-case expectations; derivations use the exact generated family.
These are finite scale checks, supplementing randomized small oracle comparisons.
"""
from math import factorial,gcd,isqrt,lcm
from itertools import combinations
from cc_a82 import CAPS,scale_case,word,line
P=1000000007
def expected(k,expanded=False,mut=False):
 n=CAPS[k][expanded]
 if k==56:v=n*(n*n-1)//6
 elif k==57:v=n
 elif k==58:v=n
 elif k==59:return '0\n'*n
 elif k==60:
  a=[0]*(n+1);a[0]=1
  for i in range(1,n+1):a[i]=(a[i-1]+(a[i-(3 if mut else 2)]if i>=(3 if mut else 2)else 0))%P
  v=a[n]
 elif k==61:return ('2\n'if mut else'1\n')*n
 elif k==62:v=0 if mut else n*(n-1)//2
 elif k==63:v=3*n
 elif k==64:return 'YES\nNO\n'
 elif k==65:return line([1]if mut else[1]*(n+50))
 elif k==66:return f'{1 if mut else n}\n{n}\n'
 elif k==67:return f'{n if mut else n-1} {n+1 if mut else n}\n'
 elif k==68:
  # Count digits by simultaneous transition, independent of scalar length recurrence.
  a=[0]*10;a[1]=1
  for _ in range(n):
   b=[0]*10
   for d in range(9):b[d+1]=a[d]
   if mut:b[1]=(b[1]+2*a[9])%P
   else:b[0]=a[9];b[1]=(b[1]+a[9])%P
   a=b
  v=sum(a)%P
 elif k==69:
  out=[]
  def dfs(s,m):
   if len(s)==n:out.append(''.join(chr(122-x if mut else 97+x)for x in s));return
   for c in range(m+2):dfs(s+[c],max(m,c))
  dfs([0],0);return '\n'.join(sorted(out))+'\n'
 elif k==71:v=1
 elif k==72:return ('Rani'if (n%4!=0 if mut else n%4!=1)else'Nandu')+'\n'
 elif k==73:v=n*(n-1)//2 if mut else n*(n+1)//2
 elif k==74:v=0 if mut else n//2+1
 elif k==75:v=999999999
 elif k==76:return line(([n-1,2]if mut else[n,1])+[0]*24)
 elif k==77:v=n//2 if mut else 2*n//3
 elif k==78:return line(range(n)if mut else range(n-1,-1,-1))
 elif k==79:v=(n-1)*(n-2)//2 if mut else n-1
 elif k==80:return ('0\n'if mut else'3\n')*n
 elif k==81:return '7\n'*n
 elif k==82:v=2*(n//2)if mut else 0
 elif k==83:return f'{n}\n{n+1 if mut else -1}\n'
 elif k==84:return 'Yes\n'
 elif k==85:return 'YES\n'
 elif k==86:
  if not mut:v=min(n,10**9,(n+10**9)//3)
  elif n>=2*10**9:v=10**9 # enough sticks to use all diamonds as shovels
  else:
   # For n=b=10^9, the resource intersection solves h≈2n/5,s≈n/5.
   v=max(h+min(n-2*h,(10**9-h)//3)for h in range(2*n//5-4,2*n//5+5))
 elif k==87:v=-1 if mut else 2*n
 elif k==88:v=(n//2)**2
 elif k==89:v=0 if mut else n*(n-1)//2
 elif k==90:return ('NO'if mut else'YES')+'\n'
 elif k==91:v=2 if mut else 1
 elif k==92:v=sum((n if mut else n-1)//a for a in range(1,(n if mut else n-1)+1))
 elif k==93:v=3*(n-1)+2 if mut else 2*n
 elif k==94:v=n-1 if mut else 1
 elif k==95:v=(n+2)//3 if mut else(n+1)//2
 elif k==96:
  nodes={''}
  for i in range(n):
   w=word(i);w=w[::-1]if mut else w
   for j in range(1,len(w)+1):nodes.add(w[:j])
  v=len(nodes)
 elif k==97:return 'bob\n'if mut else'alice\nbob\n'
 elif k==98:v=(n*(n-1)*(2*n-1)//6 if mut else n*(n-1)*(n-2)//6)%P
 elif k==99:
  f=1;d0=1;d1=0
  for i in range(1,n+1):f=f*i%P
  for i in range(2,n+1):d0,d1=d1,(i-1)*(d0+d1)%P
  v=(d1 if mut else 1)*pow(f,P-2,P)%P
 elif k==100:a=list(range(1,n+1));a[-2:]=[n,n-1]if mut else[n-1,n];return line(a)
 elif k==101:return '720 720\n'
 elif k==102:v=1 if mut else n
 elif k==103:v=1000000*n**(3 if mut else 2)
 elif k==104:v=n//2
 elif k==105:return ('First'if (n%2==0 if mut else n%2==1)else'Second')+'\n'
 elif k==106:v=n-2 if mut else n
 elif k==107:v=3 if mut else 2
 elif k==108:v=n*(n-1)//2 if mut else 0
 elif k==109:v=1 if mut else 2
 elif k==110:v=n if mut else n//2
 elif k==111:
  half=n//2;same=half+half*(half-1);v=same if mut else n*(n-1)//2-same
 elif k==112:v=min(n,199999 if mut else 200000)
 elif k==113:v=0 if mut else n-2
 elif k==114:return '0 5\n'if mut else'5 10\n'
 elif k==115:return line([1]*n)
 elif k==116:return 'ab\n'
 elif k==117:v=1+2*(n//6)if mut else 1+n//3
 elif k==118:v=-1 if mut else n//2
 elif k==119:return 'YES\n'
 elif k==120:return line([n*(n-1)//2-((i+1)*i//2 if mut else(n-i)*(n-i-1)//2)for i in range(1,n)])
 elif k==121:v=0 if mut else n
 elif k==122:return 'NO\n'if mut else'YES\n'
 elif k==123:v=2
 elif k==124:v=1 if mut else 0
 elif k==125:return 'NO\n'if mut else'YES\n'
 elif k==126:v=n*(n-1)if mut else max(lcm(a,b,c)for a,b,c in combinations(range(n-10,n+1),3))
 elif k==127:raise ValueError('Use separate prime-factor sigma scale oracle')
 elif k==128:v=-1 if mut else n-1
 elif k==129:v=10**9
 elif k==130:v=n*(n-1)*1000*999//4 if mut else n*(n-1)*1000*999
 elif k==131:v=n
 elif k==132:v=0 if mut else min(n,1400)**2
 elif k==133:v=2
 elif k==134:v=pow(2,n,998244353)if mut else 2
 elif k==135:return 'YES\n'if mut else'NO\n'
 elif k==136:return 'alice\n'
 elif k==137:return '7.000000000000\n'
 else:raise KeyError(k)
 return str(v)+'\n'
