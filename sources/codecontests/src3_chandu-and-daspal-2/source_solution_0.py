def gcd(x,y):
    if y==0: return x
    else: return gcd(y,x%y)
t=int(input())
for zz in range(t):
    x,y,win=raw_input().split()
    x=int(x);y=int(y)
    while True:
        k=gcd(x,y)
        x-=k;y-=k
        if x==0 or y==0:
            break
        if win=='Chandu': win="Daspal"
        else: win="Chandu"
    print win