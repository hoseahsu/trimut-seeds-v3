'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
s=raw_input()
n=input()
a=0
sy=0
for i in range(n):
    s1=raw_input()
    if s1[0]==s[0] and len(s1)==len(s):
        sy+=1
    if chr(ord(s[0])+3)==s1[0] and len(s1)==len(s):
        a+=1

print sy,a