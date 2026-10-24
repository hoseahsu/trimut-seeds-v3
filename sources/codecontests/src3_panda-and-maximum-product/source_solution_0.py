'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
#print 'Hello World!'
n=int(raw_input())
l=[int(i) for i in raw_input().split(" ")]
l.sort()
x=l[::-1]
if x[0]>0 and x[1]>0:
    print x[0]*x[1]
else:
	print l[0]*l[1]