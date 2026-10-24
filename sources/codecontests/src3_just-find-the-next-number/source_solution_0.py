t=int(raw_input())
while t>0:
	n=int(raw_input())
	while bin(n).count("11")!=0:
		n=n+1
	print n
	t=t-1