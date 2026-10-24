'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
t = input()

while(t>0):
	n,k,m = map(int,raw_input().split())
	sum = (n*(n+1))/2
	sum*=sum
	sum*=k
	if(sum>m): print sum-m
	else: print 0
	t-=1