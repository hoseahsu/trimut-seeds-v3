b="AEIOUaeiou"
t=input()
while t:
	t-=1
	c=""
	a=raw_input()
	for x in a:
		if x in b:
			c+=x
	if (c==""):
		print "No"
	else:
		print c