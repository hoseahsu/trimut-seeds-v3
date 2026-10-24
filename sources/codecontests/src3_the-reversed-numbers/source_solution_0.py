import string
t=int(raw_input())
while t:
	s=[]
	a,b=raw_input().split()
	c=int(a[::-1])+int(b[::-1])
	print string.lstrip(str(c)[::-1],'0')
	t=t-1