T=int(raw_input())
while T>0:
    sd=list()
    
    n=list(raw_input().split())
    pro=int(n[0])*int(n[1])
    c=0
    x=int(n[0])
    y=int(n[1])
    s=x
    rem=1
#    c=num-1
    while y!=0:
        te=y%2
        sd.extend(str(te))
        y=y/2
        c=c+1
#    print sd[0] 
    me=0
    c=c-1
    while c >= 0:
        if int(sd[c]) == 1:
            if me != 0:
                print "+ (%d<<%d)" % (x,c),
            else:
                print "(%d<<%d)" % (x,c),
                me=me+1
        c=c-1
    print
    T=T-1