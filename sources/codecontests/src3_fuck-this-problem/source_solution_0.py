'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
s = raw_input()
n=int(raw_input())
j =0
temp =""
for i in s:
	if j==n:
		print temp
		temp=""
		j=0
	temp+=i
	j = j+1
if temp!="":
	print temp