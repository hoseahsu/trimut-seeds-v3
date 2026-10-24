import math


def distance_removal(n):
    if n < 3:
        return 0

    digits = int(math.log10(n))

    # print 'digits =', digits
    num_count = int(10**digits) - int(9**digits)
    p = int(10**digits)

    msd = int(n/p)
    # print 'n/p =', n//p
    # print 'msd = ', msd
    if msd > 3:
        return (msd-1)*num_count + p + distance_removal(n % p)
    return msd * num_count + distance_removal(n % p)


if __name__ == '__main__':
    t = input()
    while t > 0:
        a = input()
        print a - distance_removal(a)
        t -= 1