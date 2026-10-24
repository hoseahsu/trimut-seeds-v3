n = int(raw_input())
m = map(int, raw_input().split())
for i in range(0,len(m)):
    count =1
    for j in range(0,len(m)):
        if(m[i]<m[j]):
            count+=1
    print count,