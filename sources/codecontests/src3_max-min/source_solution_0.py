a=[]
t,k=input(),input()
for _ in xrange(t):
	a.append(input())
a.sort()
t=[a[x+k-1]-a[x] for x in xrange(0,len(a)-k) ]
print min(t)