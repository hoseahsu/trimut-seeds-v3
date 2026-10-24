n=int(raw_input())
while n:
	
	t=(raw_input())
	t=t.split(' ')
	t[0]=int(t[0])
	t[1]=int(t[1])
	if t[1]==0:
		print t[0]
		
	elif t[1]%2==0:
		if t[0]==1:
			print "1"
		else :
			print '0'
	else :
		if t[0]==1:
			print "0"
		else :
			print '1'
	n-=1