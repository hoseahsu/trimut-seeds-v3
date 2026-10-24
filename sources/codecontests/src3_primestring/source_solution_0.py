import math

array = [0]

def calculate_primes(num):
	global array
	array = (num+1)*[0]
	lim = int(math.sqrt(num))
	for i in range(2,lim):
		j = i*i
		if not array[j]:
			while(j < num):
				array[j] = 1
				j = j + i
	array[0] = 1
	array[1] = 1
	return

		
def isPrime(num):
	return not array[num]

if __name__ == "__main__":
	calculate_primes(100000)
	t = input()	
	while t > 0:
		string = raw_input()
		count = {}
		for i in string:
			if i not in count:
				count[i] = 0
			count[i] = count[i] + 1
		distinct = len(count.keys())
		indiv_vals = [count[i] for i in count]
		result = True
		#print distinct, indiv_vals
		if isPrime(distinct):
			for i in indiv_vals:
				if not isPrime(i):
					result = False
					break
		else:
			result = False
		if result:
			print "YES"
		else:
			print "NO"
		t = t - 1