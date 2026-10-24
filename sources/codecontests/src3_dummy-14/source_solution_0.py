def numbers(N):
	my_number = 0
	v = {}
	c = {}
	i = 0
	while my_number < N:
		c[i] = i * i * i
		for j in xrange(i):
			s = c[j] + c[i]
			if s in v:
				my_number += 1
				yield(s)
			v[s] = (j,i)
		i += 1

my = []

def m(N):
	for x in numbers(N):
		my.append(x)
		
m(100)	
	
T = int(raw_input())
for _ in xrange(T):
	N = int(raw_input())
	print my[N-1]