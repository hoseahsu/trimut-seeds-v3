t = int(raw_input())

d = {}

for i in range(t):
	
	s = raw_input().strip()
	for j in range(len(s)):
		for k in range(j, len(s)):
			if not d.get(s[j:k+1], 0):
				d[s[j:k+1]] = [i]
			else:
				if i not in d[s[j:k+1]]:
					d[s[j:k+1]].append(i)
				

q = int(raw_input())

while q:
	q-=1
	l, r, sub = raw_input().strip().split(" ")
	l = int(l)
	r = int(r)
	l-=1
	r-=1
	
	if d.get(sub, 0):
		f = d[sub]
		f.sort()
		s = 0
		# Use binary search here...
		import bisect
		print bisect.bisect_right(f, r) - bisect.bisect_left(f, l)
		
	else:
		print 0