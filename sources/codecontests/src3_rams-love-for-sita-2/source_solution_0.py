for _ in xrange(input()):
	n,c,m=map(int,raw_input().split())
	nc=n/c
	nw=nc
	if nw>=m:
		while True:
			c=nw/m
			nc+=c
			nw=nw%m+c
			if nw<m:
				break
	print nc