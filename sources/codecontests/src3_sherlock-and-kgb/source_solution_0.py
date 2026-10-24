T = int(raw_input())
for ti in xrange(T):
	a,b,c = map(int,raw_input().split())
	if a%3:
		s1 = 'X'
	else:
		while a%3==0:
			a /= 3
		if a==1:
			s1 = 'K'
		else:
			s1 = 'X'
	if b%5:
		s2 = 'Y'
	else:
		while b%5==0:
			b /= 5
		if b==1:
			s2 = 'G'
		else:
			s2 = 'Y'
	if c%2:
		s3 = 'Z'
	else:
		while c%2==0:
			c /= 2
		if c==1:
			s3 = 'B'
		else:
			s3 = 'Z'
	print s1+'-'+s2+'-'+s3