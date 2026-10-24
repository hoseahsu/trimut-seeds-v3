def killdoubles(l):
    i=0
    a=l[i]
    ll=[a]
    while i<len(l):
        if a!=l[i]:
            a=l[i]
            ll.append(a)
        i+=1
    return ll

def argminnonmarque(l,m):
    mini=min([l[i] for i in range(len(l)) if not(m[i])])
    for i in range(len(l)):
        if ((l[i]==mini) & (not(m[i]))):
            break
    return i
def subs(a,l):
    i=0
    dont=False
    while i<len(l):
        if l[i][0]==a[0]:
            if l[i][1]>a[1]:
                break
            dont=True
        i+=1
    ll=[list(k) for k in l]
    if i<len(l):
        ll[i]=a
    elif not(dont):
        ll.append(a)
    return ll
def solve(n,m,r,s):
    G=[[] for _ in range(n+1)]
    for [i,j,w] in r:
        G[i]=subs([j,w],G[i])
        G[j]=subs([i,w],G[j])
        
    infinity=1+sum([r[i][2] for i in range(m)])
    
    for debut in [s]:
        marque=[False for _ in range(n+1)]
        labels=[infinity for _ in range(n+1)]
        labels[debut]=0
        while marque!=[True for _ in range(n+1)]:
            a=argminnonmarque(labels,marque)
            marque[a]=True
            for [b,w] in G[a]:
                if not(marque[b]):
                    labels[b]=min(labels[b],labels[a]+w)
        for i in range(n+1):
            if labels[i]==infinity:
                labels[i]=-1
    st=""
    for i in (labels[1:s]+labels[s+1:]):
        st+=str(i)+" "
    return st


T=int(raw_input())
for _ in range(T):
    [n,m]=map(int,raw_input().strip().split())
    r=[]
    for _ in range(m):
        r.append(map(int,raw_input().strip().split()))
    s=int(raw_input())
    print(solve(n,m,r,s))