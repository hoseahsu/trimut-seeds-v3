MOD=10**9+7
def power(base,pow):
	ans=1
	while (pow!=0):
		if(pow%2==1):
			ans=(ans*base)%MOD

		base=(base*base)%MOD
		pow=pow/2

	return ans




if __name__ =="__main__":
	t=int(raw_input())
	for i in range(t):
		n=int(raw_input())
		if(n<3):
			print 0
		else:
			print (3*(power(3,n-1) -power(2,n) +1 ))%MOD