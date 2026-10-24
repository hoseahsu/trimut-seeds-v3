s = raw_input()
l = len(s)
q = int(raw_input())
for i in xrange(0,q):
    a, b = map(int, raw_input().split())
    a%=l
    b%=l
    if s[a - 1] is s[b - 1]:
        print 'Yes'
    else:
        print 'No'