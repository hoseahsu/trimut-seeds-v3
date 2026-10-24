import math
n=input()
alist=map(int,raw_input().split())
track=[alist[i]+alist[0] for i in range(n)]
track[0]-=alist[0]
for i in range(2,int(n/2)+2):
	x=i+i
	while x<=n:
		track[x-1]=max(track[x-1],track[i-1]+alist[x-1])
		x+=i
		

for i in track:
	print i,