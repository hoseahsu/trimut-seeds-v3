t=input()
for i in xrange(t):
	n=input()
	l=[]
	for k in xrange(n):
		s=raw_input()
		l.append(s)
	q="abcdefghijklmnopqrstuvwxyz"
	o=[0 for i in xrange(26)]
	for x in xrange(n):
		for y in xrange(26):
			if q[y] in l[x]:
				o[y]+=1
	z=max(o)
	for j in xrange(26):
		if o[j]==z:
			print q[j]
			break