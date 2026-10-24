n=int(raw_input())
arr=[0]*1000002
b=[0]*1000002
m=int(raw_input())
for i in range(m):
	l,r=map(int,raw_input().split())
	arr[l]+=1
	arr[r+1]-=1
for i in range(1,n+1):
	arr[i] += arr[i - 1]
	b[arr[i]]+=1
count=0
for i in range(1000000,0,-1):
	b[i] += b[i + 1]

q=int(raw_input())
for i in range(q):
	qu=int(raw_input())
	print b[qu]