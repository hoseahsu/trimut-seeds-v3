'''def findMaxMonkiness(A, al, ah, B, bl, bh):
    if (al<ah) | (bl<bh):
        print(al)
        print(bl)
        print(ah)
        print(bh)
        amid=(al+ah)/2
        bmid=(bl+bh)/2
        if A[amid]<B[bmid]:
            print('less')
            print(amid)
            print(bmid)
            return ((findMaxMonkiness(A,al,amid,B,bmid,bh))+(bmid-bl))
        else:
            print('greater')
            print(amid)
            print(bmid)
            return max(findMaxMonkiness(A,al,amid,B,bl,bmid),findMaxMonkiness(A,amid+1,ah,B,bmid+1,bh))
    else:
        return 0;
        '''
        
def findMax(A,B,i):
    l=0
    h=len(B)-1
    maximLen=h
    while(l<=h):
        mid=(l+h)/2
        #print(mid)
        if ((B[mid]>=A) & (mid==maximLen)):
            #print('max')
            break
        elif((B[mid]>=A) & (B[mid+1]<A)):
            #print('mid')
            break
        elif (B[mid]>=A):
            l=mid+1
        else:
            h=mid-1
    #print(mid-i)
    return (mid-i)

'''
# Read input from stdin and provide input before running code
'''

t = int(raw_input())
for i in range(0,t):
    n = long(raw_input())
    A=[]
    B=[]
    a = raw_input().split(' ')
    b = raw_input().split(' ')
    for i in range(0,n):
        A.append(long(a[i]))
        B.append(long(b[i]))
        maxMonkiness=0
    #print(A)
    #print(B)
    #print findMaxMonkiness(A,0,n-1,B,0,n-1)
    if B[n-1]>A[0]:
        maxMonkiness=n-1
    elif A[n-1]>B[0]:
        maxMonkiness=0
    else:
        prev=-999
        for i in range(0,n):
            #print(i)
            if A[i]==prev:
                monkiness=0
            elif A[i]>B[i]:
                prev=A[i]
                monkiness=0
            else:
                prev=A[i]
                monkiness=findMax(A[i],B,i)
            #print(monkiness)
            if monkiness>maxMonkiness:
                maxMonkiness=monkiness
    print maxMonkiness