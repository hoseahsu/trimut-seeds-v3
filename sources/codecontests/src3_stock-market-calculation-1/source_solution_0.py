def calcprofit(stockvalues):
    prof=0
    m=0
    for i in range(len(stockvalues)-1,-1,-1):
        ai=stockvalues[i]
        if m<=ai:
            m=ai
        prof+=m-ai
    return (prof)  
for iti in xrange(input()):
	n=input()
	l=map(int, raw_input().split())
	print calcprofit(l)