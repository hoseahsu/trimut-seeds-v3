s = raw_input().split(" ")
n = int(s[0])
m = int(s[1])

items = [0]*n;

for i in range(0,m):
	s = raw_input().split(" ")
	a = int(s[0])
	b = int(s[1])
	k = int(s[2])
	
	for j in range(a-1,b):
		items[j]=items[j]+k

sum=0
for j in range(0,n):
	sum=sum+items[j]

print sum/n