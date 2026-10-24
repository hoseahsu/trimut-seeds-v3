t=input()
while t:
	t-=1
	a,b,c,d,S = map(int, raw_input().split())
	
	if c<=a or (a+S)>c:
		print 'STAY IN LONDON'
	elif (b+S)<c:
#		print (b-a+1)
		print b
	else:
		x = c-S
		if a<=x<=b:
#			print (x-a+1)
			print x
		else:
			print 'STAY IN LONDON'