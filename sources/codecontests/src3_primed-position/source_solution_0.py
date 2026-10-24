def primes2(limit):
    if limit < 2: return []
    if limit < 3: return [2]
    lmtbf = (limit - 3) // 2
    buf = [True] * (lmtbf + 1)
    for i in range((int(limit ** 0.5) - 3) // 2 + 1):
        if buf[i]:
            p = i + i + 3
            s = p * (i + 1) + i
            buf[s::p] = [False] * ((lmtbf - s) // p + 1)
    return [2] + [i + i + 3 for i, v in enumerate(buf) if v]
    

LIM = (10**6)*2+1
primes = [0] + primes2(LIM)
prime_positioned = [0]
for i in primes[1:10020]:
	prime_positioned.append(primes[i])

MOD = (10**9)+7

t = input()
while t:
	t-=1
	n,m = map(int, raw_input().split())
	print (prime_positioned[n]*prime_positioned[m])%MOD