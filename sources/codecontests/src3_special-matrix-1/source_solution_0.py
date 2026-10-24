t=int(input())
while t:
    t-=1
    o=n=int(input())
    i=i1=j=-1
    while n:
	n-=1
        i1+=1
        s=raw_input()
        if j==-1 and '*' in s:
            j=s.index('*')
            i=i1
    print abs((o/2)-i)+abs((o/2)-j)