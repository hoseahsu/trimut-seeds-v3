t=input()
while t>0:
    k,n=map(int,raw_input().split())
    if k>n:
        print "1.000000000"
    else:
        f=1.0
        for i in range(n,n-k,-1):
            f=(f*i)/n
        f=1-f
        print "%.9f"%(f)
    t-=1