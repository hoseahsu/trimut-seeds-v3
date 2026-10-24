for _ in xrange(input()):
	flag=True
	n,k=map(int,raw_input().split())
	print "Nandu" if not (n-1)%(k+1) else "Rani"