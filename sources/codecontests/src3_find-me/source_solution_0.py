test=int(raw_input())
while test:
	n,p=(raw_input().split())
	count=0
	n=int(n)
	p=int(p)
	power=[]
	
	power = map(int, raw_input().split())
	#print power
	#print type(n)
	#print power
	for i in power:
		if p<i:
		#	print i
			count=count+1
	if int(p) in power:
		print "YES "+str(count)
	else:
		print "NO 0"
	test=test-1