def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return set(factors)
ans=[0]
for k in xrange(30,2700):
    if len(prime_factors(k))>2:
        ans.append(k)
    
for _ in xrange(input()):
    print ans[input()]