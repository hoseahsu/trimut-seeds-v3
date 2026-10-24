T=input()
best=-1
bound=10**12
boundS=str(bound)
def findBest(s,off,n,sofar):
	#print "looking for best fo",s[off:],n
	remain=len(s)-off
	if remain<n: return
	global best
	if n==1:
		if remain>13:
			return
		if s[off]=="0":
			if len(s)-off>1: return
		if remain==13 and s[off:]!=boundS:
			return
		
		val=sofar+int(s[off:])
		#print "found",val
		if val>best:
			best=val
		return	
	if s[off]=="0":
		findBest(s,off+1,n-1,sofar)
		return
	for i in range(1,min(13,remain-n+2)):
		findBest(s,off+i,n-1,sofar+int(s[off:off+i]))
	if remain-n+1>=13:
		if s[off:off+13]==boundS:
			findBest(s,off+13,n-1,sofar+bound)
for _ in range(T):
	best=-1
	s=raw_input()
	findBest(s,0,4,0)
	if best>=0: print best
	else: print "unlucky"