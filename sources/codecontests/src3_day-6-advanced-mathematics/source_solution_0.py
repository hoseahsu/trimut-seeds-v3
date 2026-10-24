t=input()
for i in range(t):
    a=raw_input()
    c=0
    for i in range(0,len(a)-1):
        if a[i]==a[i+1]:
            c=1
    if c==1:
        print "SLAP"
    else:
        print "KISS"