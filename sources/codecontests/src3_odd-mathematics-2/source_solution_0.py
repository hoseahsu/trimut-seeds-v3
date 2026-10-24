T = int(raw_input())

while T > 0:
	
	num = int(raw_input())
	sum = 0
	
	while num!=0:
		if num%2==1:
			a=(num+1)/2
		else:
			a=num/2
		sum+=a*a
		num=num-a
		
	
	print sum
	T-=1