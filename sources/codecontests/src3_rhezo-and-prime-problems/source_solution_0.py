'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
import sys
 
def readline():
    return sys.stdin.readline().strip()
def readInts(sep=None):
    return map(int,readline().split(sep))
def readInt():
    return int(readline())
 
def sieve(N):
    if N < 2:
        return []
    primes =  [2]
    is_prime = [True]*(N+1)
 
    for i in xrange(3,N+1,2):
        if is_prime[i] == True:
            primes.append(i)
        for j in xrange(i*i,N+1,2*i):
            is_prime[j] = False
    return primes
 
 
N = readInt()
 
problem_points = readInts()
 
sumTill = [0]*(N+1)
 
for i in xrange(1,N+1):
    sumTill[i] = sumTill[i-1] + problem_points[i-1]
 
primes = sieve(N)
dp = [0]*(N+1)
 
for i in xrange(2,N+1):
    dp[i] = dp[i-1]
    for prime in primes:
        if prime>i:
            break
        p = i - prime - 1
        if p==-1:
            dp[i] = max(dp[i],sumTill[i])
        else:
            dp[i] = max(dp[i], sumTill[i] - sumTill[p+1] + dp[p])
print dp.pop()