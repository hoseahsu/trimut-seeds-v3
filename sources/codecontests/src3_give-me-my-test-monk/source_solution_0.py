mod=10**9+7
A=[[0 for i in range(105)] for j in range(105)]
B=[0]*105

for i in range(0,102):
	A[i][0]=1
	for j in range(1,i+1):
		A[i][j]=A[i-1][j]+A[i-1][j-1]
	
B[0]=1
for i in range(1,102):
	B[i]=B[i-1]*i
def ans(n,x):
	y=0
	for i in range(0,x+1):
		y+=((-1)**i)*B[x]/B[i]
	return y*A[n][x]

def finalans(n,l,r):
	ret=0
	for i in range(l,r+1):
		ret+=ans(n,i)
	return ret	
def ANS(n,l,r):
	x=finalans(n,l,r)%mod;
	
	y=B[n]
	z=pow(y,mod-2,mod);
	return (x*z)%mod
N, L, R=map(int,raw_input().split())
print(ANS(N,L,R))