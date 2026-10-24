rr = raw_input
N = int(rr())
A = map(int, rr().split())
from collections import defaultdict as ddic
G = ddic(int)
for i in A:
	G[i] += 1
#G is total count of everything
ans = 0
for i in xrange(N):
	cur = ddic(int)
	Ai = A[i]
	for j in xrange(i+1,N):
		if Ai==A[j]:
			for k,v in cur.iteritems():
				if k>Ai: ans += cur[k]*(G[k]-v)
		cur[A[j]] += 1
print ans