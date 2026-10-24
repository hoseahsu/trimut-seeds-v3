from sys import stdin
t=stdin.readline()
a=stdin.readlines()
for i in a:
	n = int(i)
	cur = 1
	ans = 0
	while cur<=n:
		cur = cur*2
		ans+=1
	ans-=1
	if n==0:
		ans = 0
	if ans==0:
		ans = -2147483648
	print ans