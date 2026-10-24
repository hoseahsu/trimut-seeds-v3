test = input()
while test>0:
	N = input()
	if N==0:
		print "0"
	elif N<3:
		print "1"
	elif N%3==0:
		print N/3
	else:
		print N
	test = test-1