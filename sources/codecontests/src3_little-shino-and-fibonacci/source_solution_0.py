a=[0]*20000
ar=[0]*20000
a[1]=0
a[2]=1
ar[1]=0
ar[2]=1
for i in range(3,16000): a[i]=(a[i-1]+a[i-2])%10000
for i in range(2,16000): ar[i]=(a[i]+ar[i-1])%1000000007
def fibo(n):
	return (ar[n%15000] + (((n/15000)%1000000007)*ar[15000])%1000000007)%1000000007
for _ in range(input()):
	l,r=map(int,raw_input().split())
	print (fibo(r) - fibo(l-1))%1000000007