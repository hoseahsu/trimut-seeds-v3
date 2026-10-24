def fun():
	n=input()
	l=[]
	for i in range(n):
		z=raw_input()
		l.append(z[0])
		
	if len(l)==len(set(l)):
		return("YES")	
	else:
		return("NO")

a=input()
for i in range(a):
	print(fun())