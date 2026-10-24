take=lambda: raw_input().strip()
calculate=lambda: list(map(int,raw_input().strip().split()))
numbers=[1,2,3,4,5,6,7,8,9,0]
num=[[1,2,3,4,5,6,7,8,9],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]
primes=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
ans=[[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]
def Cal(x):
	global rem,ans
	for i in xrange(len(ans[x-2])):
		for j in numbers:
			if (ans[x-2][i]*10+j)%(x)==rem[x-1]:
				ans[x-1].append(ans[x-2][i]*10+j)
	for j in xrange(len(num[x-2])):
		for i in numbers:
			if (num[x-2][j]*10+i)%(x)==rem[x-1]:
				if (num[x-2][j]%10)*10+i in primes:
					ans[x-1].append(num[x-2][j]*10+i)
				else:
					num[x-1].append(num[x-2][j]*10+i)

def count(x,A=-1,B=10**10):
	global ans
	i,count=0,0
	for i in ans[x-1]:
		if A<=i<=B:
			count+=1
	return count
	
rem=calculate()
N=int(take())
if rem[0]==1:
	for i in xrange(N):
		x=take()
		print 0
else:
	for i in xrange(2,16):
		Cal(i)
	for i in xrange(N):
		sums=0
		A,B=take().split()
		A,B=int(A),int(B)
		f,t=len(list(str(A))),len(list(str(B)))
		if f==t:
			sums=count(f,A=A,B=B)
		else:
			sums=count(f,A=A)
			for i in xrange(f+1,t):
				sums+=len(ans[i-1])
			sums+=count(t,A=-1,B=B)
		print sums