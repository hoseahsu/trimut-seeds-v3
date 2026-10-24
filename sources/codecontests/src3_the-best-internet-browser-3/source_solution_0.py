t=input()
vovels=['a','e','i','o','u']
for i in range(0,t):
        inputstr=raw_input()
        inputlen=len(inputstr)
        reqstr=inputstr[4:inputlen-3]
        reqlist=list(reqstr)
        count=0
        for i in range(0,len(reqlist)):
                if(reqlist[i] in vovels):
                        count=count+1
        outstr=str(inputlen-4-count)+"/"+str(inputlen)
        print outstr