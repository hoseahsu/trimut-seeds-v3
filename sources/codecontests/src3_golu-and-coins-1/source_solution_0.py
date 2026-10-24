M,N=map(int,raw_input().split())
L=[]
for i in range(M):
    L.append(map(int,raw_input().split()))

if M+N==4 and (L==[[0,1],[1,1]] or L==[[1,0],[1,1]] or L==[[1,1],[1,0]] or L==[[1,1],[0,1]]) or L==[[1,0],[0,0]] or L==[[0,1],[0,0]] or L==[[0,0],[1,0]] or L==[[0,0],[0,1]]:
        print "-1"
else:
    List=[]
    for i in range(M-1):
        for j in range(N-1):
            List.append(([L[i][j],L[i][j+1],L[i+1][j],L[i+1][j+1]],[j!=0,j+2!=N,i!=0,i+2!=M]))   #L,R,T,B
    zero=False
    one=False
    for i in List:
        if i[0]==[1,1,1,1]:
            zero=True
            print "0"
            break
        elif i[0]==[0,0,0,0] or i[0]==[1,0,1,0] or i[0]==[1,1,0,0] or i[0]==[0,1,0,1] or i[0]==[0,0,1,1] or (i[0]==[0,1,1,1] and (i[1][0] or i[1][2])) or (i[0]==[1,0,1,1] and (i[1][1] or i[1][2])) or (i[0]==[1,1,0,1] and (i[1][0] or i[1][3])) or (i[0]==[1,1,1,0] and (i[1][1] or i[1][3])):
            one=True
    if (not zero):
        if (one):
            print "1"
        else:
            print "2"