input()
ans=''
inp=raw_input()
init=0
for j in xrange(ord('z'),ord('a')-1,-1):
	a=chr(j)
	for k in xrange(init,len(inp)):
		if inp[k]==a:
			ans+=a
			init=k+1
			break
print ans