'''
from itertools import permutations


def abs_sum(l):
    res = 0 
    for i in range(len(l)-1):
        res += abs(l[i] - l[i+1])

    return res 


def all_perms(l):
    a = permutations(l)
    return map(list, a) 


for i in range(2, 12):
    l = range(1, i)

    ap = all_perms(l)
    print l, max(map(abs_sum, ap ))
[1] 0
[1, 2] 1
[1, 2, 3] 3
[1, 2, 3, 4] 7
[1, 2, 3, 4, 5] 11
[1, 2, 3, 4, 5, 6] 17
[1, 2, 3, 4, 5, 6, 7] 23
[1, 2, 3, 4, 5, 6, 7, 8] 31
[1, 2, 3, 4, 5, 6, 7, 8, 9] 39
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10] 49
'''
t = int(raw_input())

while t > 0 : 
    t -= 1 
    n = int(raw_input())
    if n== 1 : 
    	print 1 
    	continue
    res = n * ( n -1  ) / 2 
    res -= 1 
    res += n / 2 
    print res 
    continue

    pi = i = 1 
    pj = j = n ;
    res = n -1 
    i += 1 
    j -= 1 

    while True:
        if i == j : 
            res += 1 
            break
        if i > j : 
            break
        res += pj - i 
        res += j - pi 
        pi = i 
        pj = j 
        i+= 1 
        j-= 1 
    print res