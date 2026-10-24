from sys import stdin
import math
t = int(stdin.readline())
for _ in xrange(t):
	a,b = map(int,stdin.readline().split())
	p = int(stdin.readline())
	if b%p==0:
		if a%p==0:
			print 0
		else:
			print -1
	else:
		rem = (p - a%p)%p
		b = b%p
		inv = pow(b, p-2, p)
		rem = (rem * inv)%p
		print rem