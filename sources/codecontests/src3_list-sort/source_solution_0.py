'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''

def fun(l):
	a=[]
	
	b=l[::-1]
	for j in range(len(b)):
		s=b[j].split(" ")
		if(len(s)>=2):
			a.append([s[-1].lower(),j])
		else:
			a.append([s[0].lower(),j])
	
	a.sort(key=lambda tup: tup[0])
#	print(a)
	for i in a:
		print(b[i[1]])

	
t=int(raw_input())
for u in range(t):
	n=int(raw_input())
	l=[]
	for i in range(n):
		l.append(raw_input())
	
	fun(l)