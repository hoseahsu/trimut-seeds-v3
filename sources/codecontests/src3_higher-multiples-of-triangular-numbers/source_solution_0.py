test = int(raw_input())
while test>0:
	n = int(raw_input())
	if n==0:
		print 1
	else:
		i = 2
		while(1):
			x = i*(i+1)/2
			j = 1
			c = 0
			while j<=x:
				if x%j==0:
					c+=1
				j+=1
			if c>n:
				print x
				break
			i+=1
			
	test-=1