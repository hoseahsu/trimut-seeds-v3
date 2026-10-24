def power(x,m):
	global mod
	if m==0:
		return 1
	if m&1==0:
		temp=power(x,m/2)%mod
		return (temp*temp)%mod
	return ((x%mod)*power(x,m-1)%mod)%mod
mod=1000000007
t=input()
for kk in range(0,t):
    n,k=(int(i) for i in raw_input().split())
    l=[int(i) for i in raw_input().split()]
    l.sort()
    nCr=[0]*n
    nCr[k-1]=1
    for i in range(0,n):
        if i>=k:
            nCr[i]=(((((i%mod)*(nCr[i-1])%mod))%mod)*(power(i-k+1,mod-2)%mod))%mod
    ans=0
    for i in range(0,n):
        if n-i-1<k-1:
            break
        ans=((ans%mod)+((l[i]%mod)*(nCr[n-i-1]%mod))%mod)%mod
    print long(ans)%mod