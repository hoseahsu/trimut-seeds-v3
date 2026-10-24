#!/usr/bin/env python
# -*- coding: utf-8 -*-

# https://www.hackerearth.com/july-easy-16/algorithm/gudi-trapped-in-the-room-july-easy/

from collections import deque


def increment_string(s, n, a):
    start, mul = (0, 1)
    if n % 2 == 1:
        start, mul = (1, 10)
    for i in xrange(start, n, 2):
        digit = (s // mul) % 10
        s -= digit * mul
        digit += a
        digit %= 10
        s += digit * mul
        mul *= 100
    return s


def rotate_string(s, mul, h):
    for i in xrange(0, h):
        digit = s % 10
        s //= 10
        s += digit * mul
    return s


T = int(raw_input())
for _ in xrange(0, T):
    S = raw_input()
    n = len(S)
    S = int(S)
    A, H = [int(x) for x in raw_input().split()]
    mul = 10 ** (n - 1)

    stack = deque()
    stack.append(S)

    seen = set()

    min_s = S

    while len(stack) != 0:
        s = stack.popleft()
        if not s in seen:
            min_s = min(min_s, s)
            seen.add(s)
            stack.append(increment_string(s, n, A))
            stack.append(rotate_string(s, mul, H))

    print str(min_s).zfill(n)