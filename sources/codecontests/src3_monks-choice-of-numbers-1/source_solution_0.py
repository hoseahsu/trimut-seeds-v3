def count(num):                                                                 
    tmp=num                                                                     
    cnt=0                                                                       
    while(tmp!=0):                                                              
        if tmp & 1 == 1:                                                        
            cnt=cnt+1                                                           
        tmp=tmp >> 1                                                            
                                                                                
    #print cnt                                                                  
    return cnt                                                                  
                                                                                
T=int(raw_input())                                                              
for i in xrange(T):                                                             
    N,K=map(int,raw_input().split())                                            
    Nums=raw_input().split()                                                    
    NumsList=map(int,Nums)                                                      
    l=len(NumsList)                                                             
    cntList=list()                                                              
    for j in xrange(l):                                                         
        cntList.append(count(NumsList[j]))                                      
    cntList.sort()                                                              
    #print cntList                                                              
    j=0                                                                         
    s=0                                                                         
    while j < K :                                                               
        s=s+cntList[l-1-j]                                                      
        j=j+1                                                                   
    print s