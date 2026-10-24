import math

t=input()

while t>0:
    n,k=map(int,raw_input().split())
    print math.factorial(k+n-1)/(math.factorial(k)*math.factorial(n-1))
    t=t-1