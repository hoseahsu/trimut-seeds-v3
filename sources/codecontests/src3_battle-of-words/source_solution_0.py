'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
#print 'Hello World!'
t=int(raw_input())
while(t):
	t-=1
	s1=raw_input()
	s2=raw_input()
	c1=[]
	c2=[]
	for i in range(27):
		c1.append(0)
		c2.append(0)
	#print(c)
	for i in range(len(s1)):
		if(s1[i]==' '):
			c1[26]+=1
		else:
			c1[ord(s1[i])-97]+=1
	for i in range(len(s2)):
		if(s2[i]==' '):
			c2[26]+=1
		else:
			c2[ord(s2[i])-97]+=1
	#print(c1)
	#print(c2)
	one=0
	two=0
	for i in range(26):
		if(c1[i]>c2[i]):
			one=1
		elif(c1[i]<c2[i]):
			two=1
	if(one==1 and two==1):
		print("You draw some.")
	elif(one==1):
		print("You win some.")
	else:
		print("You lose some.")