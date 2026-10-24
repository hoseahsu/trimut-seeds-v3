'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name

print 'Hello World!'
'''
t=int(input())
for i in range(t):
	n=int(input())
	if n==1:
		print(2)
	else:
		a=1
		b=2
		for i in range(2,n+1):
			a,b=b,a+b
		print(b)