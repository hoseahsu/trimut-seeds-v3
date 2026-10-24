import sys
from math import log, floor

def lucky( n ):
    return 2*(n - 2**(int(floor(log(n,2)))))+1
    
cases= int(sys.stdin.readline())
current= 0
while current < cases:
    current	+= 1
    n = int(sys.stdin.readline())
    print lucky( n )