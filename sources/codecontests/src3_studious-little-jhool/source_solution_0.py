for i in range(input()):
	n = input()
	ans = 1000000
	for i in xrange(113):
		for j in xrange(113):
			if (i*10 + j*12 == n):
				ans = min (ans, i+j)
	if (ans==1000000):
		print -1
	else:
		print ans