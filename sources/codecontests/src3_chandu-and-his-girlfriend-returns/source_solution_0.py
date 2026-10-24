def merge(a,b):
    c=[]
    l1=len(a)
    l2=len(b)
    i=0
    j=0
    while i<l1 and j<l2:
        if a[i]>b[j]:
            c.append(a[i])
            i+=1
        else:
            c.append(b[j])
            j+=1
    while i<l1:
        c.append(a[i])
        i+=1
    while j<l2:
        c.append(b[j])
        j+=1
    return c
for t in xrange(int(raw_input())):
    n,m=map(int,raw_input().split())
    a=map(int,raw_input().split())
    b=map(int,raw_input().split())
    c=merge(a,b)
    for i in c:
        print i,
    print