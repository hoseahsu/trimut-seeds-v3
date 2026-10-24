def mysieve(n):
    for i in xrange(2, n):
        if i * i <= n and  not prime[i]:
            for j in xrange(i * i, n, i):
                prime[j] = 1


def comp():
    for i in xrange(2, n):
        if not prime[i]:
            pre[i] = pre[i-1] + i
        else:
            pre[i] = pre[i - 1]

n = 1000001
prime = [0] * n
pre = [0] * n
mysieve(n)
comp()

for _ in xrange(input()):
    a, b = map(int, raw_input().split())
    print pre[b] - pre[a - 1]