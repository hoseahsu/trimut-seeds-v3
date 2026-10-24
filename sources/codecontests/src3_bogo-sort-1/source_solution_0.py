N = input()
A = []

for i in xrange(N):
	A.append(int(raw_input()))
	
A.sort()

for a in A:
	print a