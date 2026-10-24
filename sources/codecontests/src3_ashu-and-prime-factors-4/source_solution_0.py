MAX = 10**6+1
primes = [1]*MAX
primes[0] = primes[1] = 0
for i in xrange(2,MAX):
    if primes[i]:
        for j in xrange(i*i,MAX,i):
            if primes[j]:
                primes[i] += 1
                primes[j] = 0
for _ in xrange(input()):
    x = input()
    print primes[x]