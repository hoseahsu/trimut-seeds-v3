def count(n):
	i=0
	n+=1
	while(n!=0):
		n/=2
		i+=1
	return i-1
k=int(raw_input())
while(k>0):
	a=""
	k-=1
	n=int(raw_input())
	c=count(n)	
	lb=(2**c)-1
	ub=lb*2
	while(lb<ub):
		mid=(lb+ub)/2
		if(n>mid):
			a+="7"
			lb=mid+1
		else:
			a+="4"
			ub=mid
	print a