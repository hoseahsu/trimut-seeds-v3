n = int(input())
e = [0]*501
for i in range(n):
	m = int(input())
	a = map(int,raw_input().split())
	f = [0]*501
	for j in a:
		f[j] = 1
	for j in range(501):
		e[j]+=f[j]
ans = 0
for i in range(501):
	if e[i]==n: ans-=i
print ans