from sys import stdin
def area():
    for t in xrange(input()):
        n = input()
        a = []
        b = []
        for j in xrange(n):
            x,y = map(int,raw_input().split())
            a.append(x)
            b.append(y)
        t1 = min(a)
        t2 = max(a)
        t3 = min(b)
        t4 = max(b)
        l = abs(t2-t1)
        w = abs(t4-t3)
        res = l*w
        if(res == 0):
            print max(l,w)
        else:
            print res
area()