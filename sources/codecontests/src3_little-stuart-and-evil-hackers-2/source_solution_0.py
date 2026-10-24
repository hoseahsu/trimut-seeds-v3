# Binomial coefficient with mod inverse of prime.  Calculate binom (n, r) % p.
MAXN = 200005
MOD = 10 ** 9 + 7
f = [0] * MAXN
def binom (n, r, p):
    # print binom (10 ** 18, 2545354543534, 9973)
    if n < 0 or r < 0 or n < r: return 0

    # Precalculate factorial.
    if f [0] != 1:  # Factorial already precalculated.
        f [0] = 1
        for i in range (1, MAXN): f [i] = (i * f [i - 1]) % p

    # Calculate modular inverse using Fermat's little theorum.
    #def inv (n): return  pow (n, p - 2, p)
    def inv (n): return  pow (n, 500000001, p)

    ret = 1
    while n or r:
        # Use Lucas theorum to reduce values into its prime residual.
        n0, r0 = n % p, r % p
        n, r = n / p, r / p
        if n0 < r0: return 0
        # print n0, r0
        ret *= f [n0] * inv (f [r0]) * inv (f [n0 - r0])
        ret %= p

    return ret

T = int (raw_input ())
for t in xrange (T):
	m, n = [int (i) for i in raw_input ().split ()]
	x = binom (2 * n, n, MOD - 1)
	print pow (x, m, MOD - 1)