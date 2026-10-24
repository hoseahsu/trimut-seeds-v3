tc=int(raw_input())
for case in range(tc):
	s=raw_input()
	r=s[::-1]
	l=len(s)
	flag=1
	for i in range(l-1):
		t=ord(s[i])-ord(s[i+1])
		if t>0:
			a=t
		else:
			a=-1*t
		t=ord(r[i])-ord(r[i+1])
		if t>0:
			b=t
		else:
			b=-1*t
		if not a==b:
			flag=0
			break
	if flag==1:
		print "Funny"
	else:
		print "Not Funny"