def func(s,val):
	cfc=0
	x=0
	length=len(s)
	for i in range(length):
		if x+s[i]<=val:
			x+=s[i]
		else:
			cfc+=1
			x=s[i]
	return cfc+1		
t=input()
for i in range(t):
	l1=map(int,raw_input().strip().split())
	n=l1[0]
	j=l1[1]
	route=map(int,raw_input().strip().split())
	s=[]
	minimum=0
	for k in range(1,n):
		x=route[k]-route[k-1]
		s.append(x)
		if x>minimum:
			minimum=x
	large=route[n-1]-route[0]
	
	if j==1:
		print large
		continue
	r=func(s,minimum)
	if r==j:
		print minimum
		continue
	
	while minimum<large:
		if large-minimum==1:
			if func(s,minimum)<=j:
				print minimum
			else:
				print large
			break
		now=(large+minimum)/2
		r=func(s,now)
		if r<=j:
			large=now
		else:
			minimum=now