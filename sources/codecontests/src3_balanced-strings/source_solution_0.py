from collections import Counter
i=0
N=input()
while i<N:
	st=raw_input()
	d=Counter([j for j in st])
	if len(d)==26 and len(set(d.values()))==1:
		print 'Yes'
	else:
		print 'No'
	i+=1