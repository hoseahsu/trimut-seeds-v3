'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
t = int(input())
for ti in xrange(t):
	n, x = map(int, raw_input().split())
	arr = map(int, raw_input().split())
	elem = arr[0]
	count = 0
	for i in xrange(1, len(arr)):
		if elem >= arr[i]:
			this_count = ((elem-arr[i])/x)+1
			arr[i] += this_count*x
			count += this_count
		elem = arr[i]
	print count