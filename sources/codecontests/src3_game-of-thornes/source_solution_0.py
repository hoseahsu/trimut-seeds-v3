'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
s = raw_input()
n = len(s)
d = {}
for c in s:
	if c in d:
		d[c] += 1
	else:
		d[c] = 1

nodd = 0
for key in d:
	if d[key] % 2 == 1:
		nodd += 1

if n%2 == 0 and nodd == 0:
	print "YES"
elif n%2 == 1 and nodd == 1:
	print "YES"
else:
	print "NO"