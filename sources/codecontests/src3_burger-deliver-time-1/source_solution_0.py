a=[]
T=input()
for i in xrange(T):
	c,d=map(int,raw_input().split())
	a.append((c+d,i))
a.sort()
for i in a:
	print i[1]+1,