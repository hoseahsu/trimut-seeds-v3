from collections import defaultdict
import sys
inf = sys.maxint
T = int(raw_input())
for l in range(T):
    N,M   = [int(x) for x in raw_input().split()]
    dicti = defaultdict(lambda : inf)
    D     = [[inf]*(N+1) for x in range(N+1)]
    for i in range(1,N+1):
        D[i][i]=0


    
    for i in range(M):
        u,v,c = [int(x) for x in raw_input().split()]
        if D[u][v] >c:
            D[u][v]=c
            D[v][u]=c
        
    for key,value in dicti.iteritems():
        D[key[0]][key[1]] = value
    

    '''
    for i in range(1,N+1):
        print D[i]
    '''

    for k in range(1,N+1):
        for i in range(1,N+1):
            for j in range(1,N+1):
                if D[i][k] == inf or D[k][j] == inf:
                    continue
                elif D[i][j] > D[i][k]+D[k][j]:
                    D[i][j] = D[i][k]+D[k][j]

    S,A,H = [int(x) for x in raw_input().split()]
    dist = [-1]*(N+1) 
    for k in range(1,N+1):
        if k!=S and k!=A and k!=H:
            dist[k] = D[S][k]+2*D[k][A]+D[k][H]
    ans = max(dist)
    print ans