t=int(raw_input())
for qq in xrange(t):
	n=int(raw_input())
	l=map(int,raw_input().split())
	s=sum(l)
	minval=9999999999999999999
	ret=0
	if n==1:
		print 0
		continue
	for i in xrange(n):
		tmp=0
		cp=s
		if i>0 and i<n-1:
			tmp = abs(l[i]-l[i-1]) + abs(l[i]-l[i+1])
			cp-=tmp
			cp+=abs(l[i+1]-l[i-1])
			if cp < minval:
				minval = cp
				ret=i
		elif i==0:
			cp-=abs(l[0]-l[1])
			if cp < minval:
				minval = cp
				ret=i
		else:
			cp-=abs(l[n-2]-l[n-1])
			if cp < minval:
				minval = cp
				ret=i
	print ret