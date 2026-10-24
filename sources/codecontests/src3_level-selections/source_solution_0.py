n,k=raw_input().split()
n,k=int(n),int(k)
l=[int(i) for i in raw_input().split()]
x=0
swap_i=0
while k:
    max_e=0
    k-=1
    for i in range(x,n):
        if(l[i] >= max_e ):
            max_e=l[i];
            swap_i=i
    l[x],l[swap_i]=l[swap_i],l[x]
    x+=1
    
    if(swap_i == x):
    	k+=1
    
for i in l:
    print i,