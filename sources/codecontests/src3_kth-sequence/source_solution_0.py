from sys import stdin
fib = [1,2]
ma = 10**19
while True:
	fib.append(fib[-1] + fib[-2])
	if fib[-1] > ma:
		break
t = int(stdin.readline())
for _ in xrange(t):
	n,k = map(int,stdin.readline().split())
	ans = ''
	valid = 1
	if n<len(fib) and fib[n] < k:
		valid = 0
	for i in xrange(n):
		rem  = n-1-i
		#print "rem are",rem,fib[rem]
		if rem>=len(fib) or fib[rem]>=k:
			ans+='O'
		else:
			ans+='Z'
			k-= fib[rem]
	if valid==0:
		ans = -1
	print ans