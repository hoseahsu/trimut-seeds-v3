def CheckIfProbablyPrime(x):
    return (2 << x - 2) % x
def primes(n):
    primfac = []
    d = 2
    while d*d <= n:
        while (n % d) == 0:
            primfac.append(d)
            n //= d
        d += 1
    if n > 1:
       primfac.append(n)
    return primfac
for i in range(input()):
	a=input()
	s=""
	s1=""
	if(a==2 or CheckIfProbablyPrime(a)==1):
		print('2^0')
		continue;
	else:
		l=primes(a)
		l1=list(set(l))
		l1.sort()
		if(l.count(2)==0):
			s='2^0*'
		for j in range(0,len(l1)):
			s+=str(l1[j])+'^'+str(l.count(l1[j]))+'*'
	for k in range(0,len(s)-1):
		s1+=s[k]
	print(s1)