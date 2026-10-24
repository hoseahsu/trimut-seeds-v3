import math
x,y,z=map(eval, raw_input().split())
a,b,n=int(x),int(y),int(z)
ans=math.ceil((float(n-b)/float(a-b)))
print(int(ans))