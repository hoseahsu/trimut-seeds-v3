'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
for tc in range(input()):
	n = raw_input()
	while len(n) > 1:
		t=0
		for i in n:
			t += int(i)
		n = str(t)
	print n