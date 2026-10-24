if __name__ == '__main__':                                                                  
    T = int(raw_input())                                                                    
    while T > 0:                                                                            
        [R, S, N] =  [int(x) for x in raw_input().split()]                                  
        Cals = [ int(x) for x in raw_input().split()]                                       
        Cals.sort()                                                                         
        
        tot = 0
        uniqR = 0
        uniqS = 0
        for i in range(N):
            tot += Cals[i]
            if tot <= R:
                uniqR += 1

            if tot <= S:
                uniqS += 1
        if uniqR > uniqS:
            print "Raghu Won"
        elif uniqR < uniqS:
            print "Sayan Won"
        else:
            print "Tie"
        T -= 1