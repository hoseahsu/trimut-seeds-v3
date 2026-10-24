n,m,s=map(int,raw_input().split())
lst=[]
for _ in range(n):
	lst.append(raw_input())	
fac=n*m
if n==1:print (2*m-1)
elif m>=8:
	print n
elif lst[0]!=lst[1]:print (n*m*fac-n*m)
else:print (n*m*fac-fac)