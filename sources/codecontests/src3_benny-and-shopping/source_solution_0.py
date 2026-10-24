'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
import re
import sys
n = int(raw_input())

for i in range(n):
	str1 = raw_input()
	dollar = "$"
	space = " "
	str2 = str1.split(dollar)[1]
	str2="".join(str2.split())
	l=[]
	sys.stdout.write('$')
	for j in range(len(str2)):
		if str2[j].isdigit() :
			l.append(str2[j])
		else:
			break
	ans="".join(l)
	print int(ans)