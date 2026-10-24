a = input()
for i in xrange(a) :
	d = input();
	b = [int(i) for i in raw_input().strip().split()]
	c = {}
	for i in xrange(d) :
		c[b[i]]=i;
	print len(c)