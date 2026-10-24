n,q=map(int,raw_input().split())
b=map(int,raw_input().split())
bb=[0]
for i in xrange(n):
	bb.append(bb[len(bb)-1]+b[i])
for i in xrange(q):
	l,r=map(int,raw_input().split())
	print bb[r]-bb[l-1],2*b[r-1]-bb[r]+bb[l-1]