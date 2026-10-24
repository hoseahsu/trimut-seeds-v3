t = int(raw_input())
for ti in range(t):
	door = raw_input()
	n = len(door)
	i = 0
	op = []
	while i<n:		
		if door[i] == '_':
			j = 1
			while i<n and door[i]== '_':
				i += 1
				j += 1
			op.append(j-1)
		i += 1
	#print op
	if not op:
		print "Bob"
	elif len(op)==1 and op[0]<=n-1:
		print "Alice"
	elif len(op)==1 and op[0]==n:
		print "Bob"
	#elif len(op)==2 and op[0] == op[1]
	#elif len(op)&1:
	#	print "Alice"
	else:
		
		xor = op[0]
		for i in range(1,len(op)):
			xor ^= op[i]
		#xor = bin(xor)[2:].count('1')
		if xor>0:
			print "Alice"
		else:
			print "Bob"