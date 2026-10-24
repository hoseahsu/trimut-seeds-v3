import math
for _ in xrange(int(raw_input())):
	n = int(raw_input())
	
	#m = int(math.log10((n/math.exp(1.0))**n*math.sqrt(2*math.pi*n)*math.exp(1/12.0/n)))
	m = int(n*math.log10(n/math.e) + 0.5*(math.log10(2*math.pi*n)))
	a = n/5
	z = n//5
	i=2
	while a > 1:
		a = n/(5**i)
		z += n//(5**i)
		i += 1
	print m-z+1