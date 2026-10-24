i=1
for _ in xrange(input()):
	a,b=map(int,raw_input().split())
	n=1
	x=1
	while True:
		x=x*a
		if str(b) == str(x)[:len(str(b))]:
			break
		n=n+1
	print "Case %d:"%i, n
	i+=1