from sys import stdin
t = stdin.readline()
di = {}
a = stdin.readlines()
ans = 0
for i in a:
	cur = i.strip()
	x=cur
	cur = list(cur)
	cur.reverse()
	cur = ''.join(cur)
	
	ans+=di.get(cur,0)
	di[x] = di.get(x,0)+1

print ans