t=input()
from fractions import gcd
for x in range(t):
	n1=input()
	n2=input()
	k=input()
	ans=0
	for i in range(-k, k+1):
		if i+n1<1:
			continue
		absi=abs(i)
		for j in range(-k+absi, k-absi+1):
			if j+n2<1:
				continue
			y=gcd(n1+i, n2+j)
			if y>ans:
				ans=y
	print ans