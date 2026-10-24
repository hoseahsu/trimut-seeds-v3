for _ in range(int(raw_input())):
    tz = 0
    n = int(raw_input())
    i = 1
    r = 1
    while r:
        r = n / 5 ** i
        tz += r
        i += 1
    print tz