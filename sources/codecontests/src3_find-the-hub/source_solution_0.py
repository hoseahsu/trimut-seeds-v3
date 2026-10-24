def isPrime(num):
	if num == 0 or num == 1:
		return False
	if num == 2:
		return True
	if num % 2 == 0:
		return False
	i = 3
	while i <= num**0.5+1:
		if num%i == 0:
			return False
		i = i+2
	return True		
	
	
t = int(raw_input())
Arr = map(int, raw_input().strip().split(' '))
mx = -1
for i in Arr:
	#print i, isPrime(i)
	
	if i > mx and isPrime(i):
		mx = i
print mx
print Arr.count(mx)