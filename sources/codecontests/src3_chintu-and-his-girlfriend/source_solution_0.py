n,k=map(int,raw_input().split())
ans=set([chr(i) for i in xrange(97,97+26+1)])
for _ in xrange(n):
	ans=ans.intersection(set(list(raw_input())))

if len(ans)>=k:
	print ":-)"
else:
	print ":-("