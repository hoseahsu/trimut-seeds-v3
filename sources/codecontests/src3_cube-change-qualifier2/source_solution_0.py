'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
t=input();
while  t > 0 : 
	c=input()
	if c!=1:
		print (c*c*c)-(c-2)*(c-2)*(c-2)
		t=t-1
	else:
		print 1
		t=t-1