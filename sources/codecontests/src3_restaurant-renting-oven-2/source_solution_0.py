def f(av,index):
    l1=[]
    l2=[]
    global l
    global m
    global n
    if(index==n):
        return 0
    for i in range(0,m):
        l1.append(av[i])
        l2.append(av[i])
    boolean=True
    for i in range(l[index][0],l[index][1]):
        l1[i]-=1
        if(av[i]<=0):
            boolean=False
            break
    if(boolean==True):
        return max(l[index][2]+f(l1,index+1),f(l2,index+1))
    else:
        return f(l2,index+1)
t=input()
temp=raw_input()
for zz in range(0,t):
    n,m=(int(i) for i in raw_input().split())
    l=[]
    for c in range(0,n):
        x=[int(i) for i in raw_input().split()]
        l.append(x)
    l.sort()
    #print l
    av=[int(i) for i in raw_input().split()]
    print f(av,0)