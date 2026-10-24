t = int(raw_input())
while(t):
	str=raw_input()
	str1=str[::-1]
	number=int(str1)
	if number%2==0:
		print "EVEN"
	else:
		print "ODD"
	t-=1