import math

def ispalin(x):
    o=[]
    while x:
        o.append(x%10)
        x/=10
    r=reversed(o)
    for i,j in zip(o,r):
        if i!=j:
            return False
    return True


s,b=raw_input().split()
s,b=(int)(s),(int)(b)

sq=(int)(math.sqrt(b))
a=[]

for i in range(1,10001):
    num=i*i
    for j in range(i+1,sq+1):
        num+=j*j
        if num>b:
            break
        if(num<s):
            continue
        if (ispalin(num) and num not in a):
            a.append(num)

print sum(a)