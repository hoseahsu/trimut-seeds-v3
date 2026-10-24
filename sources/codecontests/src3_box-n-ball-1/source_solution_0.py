t = int(raw_input())
while t>0:
    t-=1
    list  = map(float,raw_input().split())
    print "{:.1f}".format(min(list)/2)