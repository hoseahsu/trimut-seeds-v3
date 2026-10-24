def main():
    from collections import defaultdict
    from itertools import count
    from fractions import gcd
    from operator import mul
    from sys import stdin,stdout
    
    def lcm(a, b): return a * b / gcd(a, b)
    
    primes_cache, prime_jumps = [], defaultdict(list)
    
    def primes():
        prime = 1
        for i in count():
            if i < len(primes_cache): prime = primes_cache[i]
            else:
                prime += 1
                while prime in prime_jumps:
                    for skip in prime_jumps[prime]:
                        prime_jumps[prime + skip] += [skip]
                    del prime_jumps[prime]
                    prime += 1
                prime_jumps[prime + prime] += [prime]
                primes_cache.append(prime)
            yield prime
            
    def factorize(n):
        for prime in primes():
            if prime > n: return
            exponent = 0
            while n % prime == 0:
                exponent, n = exponent + 1, n / prime
            if exponent != 0:
                yield prime, exponent
                
    def totient(n):
        return int(reduce(mul, (1 - 1.0 / p for p, exp in factorize(n)), n))
    
    t = int(stdin.readline())
    while t>0:
        n = int(stdin.readline())
        stdout.write(str(totient(n))+'\n')
        t-=1
        
if __name__=='__main__':
    main()