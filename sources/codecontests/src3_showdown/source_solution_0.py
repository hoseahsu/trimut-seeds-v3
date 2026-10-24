n=input()

f=raw_input()
m=raw_input()

f=f.split()
m=m.split()
for x in range(0,n):
    f[x]=int(f[x])
    m[x]=int(m[x])
f=sorted(f, reverse=True)
m=sorted(m, reverse=True)
point=0
i=0
#print f
#print m
##winnings
while(i<len(f)):
    j=0
    temp=f[i]
    while(j<len(m)):
        if(temp>m[j]):
            point=point+100
            del(f[i])
            del(m[j])
            i = -1
            break
        elif(temp==m[j]):
            point=point+50
            del(f[i])
            del(m[j])
            i = -1
            break
        j=j+1
    i=i+1

print point