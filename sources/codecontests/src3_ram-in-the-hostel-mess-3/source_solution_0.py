'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
from math import factorial
def ncr(n,r):
	if(n<0 or r<0):
		return 0
	elif(n<r):
		return 0
	else:
		return factorial(n)/(factorial(r)*factorial(n-r))
t = input()
for i in range(0,t):
	n = input()
	ans = 0
	p = 1
	i = 1
	while(p>0):
		ans = ans + p
		p = ncr(n,i)
		n = n - 1
		i = i + 1
	print ans*ans