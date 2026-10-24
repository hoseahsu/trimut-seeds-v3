def check(s1):
    for i in range(len(s1)):
        for j in range(i+1,len(s1)):
            if s1[i]!=s1[j]:
                return 0
    return 1
s=raw_input()
dc={}
for i in range(len(s)):
    t=i
    while t<len(s):
        s1=s[i:t+1]
        if s1 not in dc and check(s1):
            dc[s1]=1
        else:
            if check(s1):
                dc[s1]+=1
        t=t+1
l=list(dc.values())
print sum(l)