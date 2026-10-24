t = int(raw_input())
for i in range(t):
	flag = 0
	s = raw_input()
	d = {}
	for j in s:
		d[j] = d.get(j,0) + 1
	for j,k in d.iteritems():
		if(k%2 != 0):
			flag = 1
			break
	if flag == 1:
		print -1
	else:
		print 1