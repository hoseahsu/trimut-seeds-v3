def isLexiograficalSorted(best, current):
    best.sort()
    current.sort()
    if len(best) < len(current):
        return True
    if len(best) > len(current):
        return False

    # len is same
    for i in xrange(len(best)):
        if best[i] < current[i]:
            return True
        if best[i] > current[i]:
            return False
    # both list are same
    return True




line = (raw_input()).split(' ')

N = int(line[0])
X = int(line[1])

best = []

data = [int(x) for x in (raw_input().split(' '))]
#print data
for i in xrange(1, 1 << N) :
    add = 0
    curr = []
    for j in xrange(N):
        #print '{0}, {1}'.format(i, (1 << j));
        if (i & (1 << j)) != 0:
            add += data[j]
            curr.append(j + 1)

    #print "{0:b}, sum = {1}".format(i, add)
    if add == X:
        if len(best) == 0:
            best = curr
        elif not isLexiograficalSorted(best, curr):
            best = curr


if len(best) == 0:
    print -1
else:
    print ' '.join(str(x) for x in best)