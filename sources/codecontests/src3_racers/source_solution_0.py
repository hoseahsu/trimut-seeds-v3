'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
from sys import stdin
import math
from operator import indexOf
    
def dist(a,b):
    return (((a[0]-b[0])*(a[0]-b[0])+((a[1]-b[1])*(a[1]-b[1]))))
                      
def main():
    N,M,K = map(int, stdin.readline().split())
    bikers = []
    bikes = []
    for i in range(N):
        bikers.append(map(int, stdin.readline().split()))
    for i in range(M):
        bikes.append(map(int, stdin.readline().split()))        
        
    distanceArr =[]
    for i in range(len(bikers)):
        distances ={}
        for j in range(len(bikes)):
            distances[j] = dist(bikers[i], bikes[j])
        distanceArr.append(distances)
        
    for i in range(K):
        lenArr = len(distanceArr)
        minArr = [0]*lenArr
        for j in range(lenArr):
            minArr[j] = min(distanceArr[j].itervalues())
        
        result = min(minArr)
        ind = indexOf(minArr,result)
        #print "index : "+str(ind)
        
        k = [x for x in distanceArr[ind] if distanceArr[ind][x] == result]
        
        #print k[0]
        
        del distanceArr[ind]
        
        for h in range(lenArr-1):
            del distanceArr[h][k[0]]
        
        
        
    
    print result
    
main()