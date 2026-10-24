for _ in xrange(input()):
    n= input()
    a=map(int,raw_input().split())
    b=[]
    flag=0
    for x in xrange(n-1,0,-1):
        b=a[:x-1]
        if a[x]<a[x-1]:
            for y in xrange(n-1,x-1,-1):
                if a[x-1]>a[y]:
                    b.append(a[y])
                    flag=1
                    c=a[x-1:]
                    del(c[y-x+1])
                    c.sort()
                    c.reverse()
                    b=b+c
                if flag==1:
                    break
        if flag==1:
            break
    if flag==0:
        print ' '.join(str(x) for x in a)
    else :
        print ' '.join(str(x) for x in b)