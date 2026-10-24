def find(s):
	n=26-(ord(s[0])-ord('a'))
	z="z"
	out=""
	for i in s:
		if ord(i)+n <= ord(z):
			out+=chr(ord(i)+n)
		else:
			x=ord(z)-ord(i)
			y=n-x-1
			out+=chr(ord('a')+y)
	print out

if __name__ == '__main__':
	t=int(raw_input())
	while t>0:
		s=raw_input()
		find(s)
		t-=1