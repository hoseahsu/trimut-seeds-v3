a=[]
for i in xrange(1,22):
	a.append(i**3)
ans=[0]*10001
ans[0]=1
for j in a:
	for i in xrange(j,10001):
		ans[i]+=ans[i-j]
for _ in xrange(input()):
	print ans[input()]