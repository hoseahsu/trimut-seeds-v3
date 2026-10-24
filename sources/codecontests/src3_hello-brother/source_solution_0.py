'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
#print 'Hello World!'
n,m=map(int,raw_input().split())
l=[int(i) for i in raw_input().split()]
if m in l:
	print "1"
else:
	print"0"