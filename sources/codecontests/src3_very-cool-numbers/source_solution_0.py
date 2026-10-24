def counter(n):
    binary = bin(n)[2:]
    count = 0
    for i in xrange(len(binary)-2):
        if binary[i:i+3] == "101":
            count += 1
    return count

ary = [0]*(10**5+1)
for i in xrange(5,10**5+1):
	ary[i] = counter(i)
	
for t in xrange(input()):
    r,k = map(int, raw_input().split())
    tot = 0
    #from pdb import set_trace
    #set_trace()
    for i in xrange(5,r+1):
        if ary[i] >= k:
        	tot += 1
    print tot