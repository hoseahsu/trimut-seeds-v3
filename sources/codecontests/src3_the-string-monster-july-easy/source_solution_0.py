#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys, math, random, operator
#from string import ascii_lowercase
#from string import ascii_uppercase
from fractions import Fraction, gcd
from decimal import Decimal, getcontext
from itertools import product, permutations, combinations
from Queue import Queue, PriorityQueue
from collections import deque, defaultdict, Counter
getcontext().prec = 100

MOD = 10**9 + 7
INF = float("+inf")

if sys.subversion[0] != "CPython":  # PyPy?
    raw_input = lambda: sys.stdin.readline().rstrip()
pr = lambda *args: sys.stdout.write(" ".join(str(x) for x in args) + "\n")
epr = lambda *args: sys.stderr.write(" ".join(str(x) for x in args) + "\n")
die = lambda *args: pr(*args) ^ exit(0)

read_str = raw_input
read_strs = lambda: raw_input().split()
read_int = lambda: int(raw_input())
read_ints = lambda: map(int, raw_input().split())
read_float = lambda: float(raw_input())
read_floats = lambda: map(float, raw_input().split())

"---------------------------------------------------------------"
ZERO = (0,) * 26

# def finalize(c):
    # return tuple(sorted(c.items()))

def getpos(lst):
    ans = set()
    for l in xrange(0, len(lst)+1):
        for ws in combinations(lst, l):
            res = [0] * 26
            for w in ws:
                add(res, w)
            ans.add(tuple(res))
    return ans

def Counter(s):
    res = [0] * 26
    for c in s:
        res[ord(c)-0x61] += 1
    return tuple(res)

def add(c1, c2):
    for i in xrange(len(c1)):
        c1[i] += c2[i]


t = read_int()
for t in xrange(t):
    n = read_int()
    lst = []
    for i in xrange(n):
        lst.append(Counter(read_str()))
    target = Counter(read_str())

    if target in lst:
        print "YES"
        continue

    if len(lst) == 1:
        print "NO"
        continue

    h = n / 2
    pos1 = getpos(lst[:h])
    pos2 = getpos(lst[h:])
    for cset in pos1:
        good = 1
        res = list(target)
        for i, (a, b) in enumerate(zip(cset, target)):
            if a > b:
                good = 0
                break
            res[i] -= a
        if not good:
            continue

        if tuple(res) in pos2:
            print "YES"
            break
    else:
        print "NO"