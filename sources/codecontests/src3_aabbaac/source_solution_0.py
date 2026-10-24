t = int(raw_input())
for _ in xrange(t):
    n, m = [int(x) for x in raw_input().split()]
    s = [raw_input() for __ in xrange(n)]
    ans = ''
    arLen = sum(2 ** (len(s) - i - 1) * len(s[i]) for i in xrange(len(s)))
    for __ in xrange(m):
        req = int(raw_input())
        curr = arLen
        last = len(s) - 1
        while curr - len(s[last]) > req:
            curr -= len(s[last])
            if req * 2 >= curr:
                req = curr - req - 1
            curr >>= 1
            last -= 1
        ans += s[last][req - curr]
    print ans