import math

def getPrime(Max):
    used = [0] * Max
    
    used[1] = 1
    for i in xrange( 4, Max, 2 ):
        used[i] = 1
    
    for i in xrange( 3, int(math.sqrt(Max) + 1), 2 ):
        if used[i] == 1:
            continue
        for j in xrange( i * i, Max, i ):
            used[j] = 1
    
    return used
    
def main():
    N,K = map(int, raw_input().strip().split())
    A = []
    
    Max = 0
    for _ in xrange(N):
        A.append(map(int, raw_input().strip().split()))
        temp = max(A[-1])
        Max = max(Max, temp)
    
    DP = [0] * (Max + 1)
    used = getPrime(Max + 10000)
    
    length = Max + 10000
    for i in xrange( 1, Max + 1 ):
        if used[i] == 0:
            continue
        
        if K > 1 and i % K == 0:
            DP[i] = 10 ** 10
            continue
        
        j = i
        cnt = 0
        while j < length:
            if used[j] == 0:
                DP[i] = cnt
                break
            j += K
            cnt += 1
        if j >= length:
            DP[i] = 10 ** 10
    
    for i in xrange(N):
        for j in xrange(N):
            A[i][j] = DP[A[i][j]]
    
    MinStep = 10 ** 10
    flag = False
    X = -1
    Y = -1
    for i in xrange( 1, N - 1 ):
        for j in xrange( 1, N - 1 ):
            Sum = 0
            if A[i][j] == 10 ** 10:
                continue
            if A[i - 1][j - 1] == 10 ** 10:
                continue
            if A[i - 1][j + 1] == 10 ** 10:
                continue
            if A[i + 1][j - 1] == 10 ** 10:
                continue
            if A[i + 1][j + 1] == 10 ** 10:
                continue
                
            Sum = A[i][j] + A[i - 1][j - 1] + A[i - 1][j + 1] + A[i + 1][j - 1] + A[i + 1][j + 1]
            if MinStep > Sum:
                MinStep = Sum
                flag = True
                X = i + 1
                Y = j + 1
    
    if flag == True:
        print "yes"
        print MinStep
        print X,Y
    else:
        print "no"
    
if __name__=="__main__":
    main()