n=input()
a=map(int,raw_input().split())
i=a.index(max(a))
c=[i]
l1=a[:i]
l2=a[i+1:]



max2=l2[-1]
for x in xrange(n-i-2,-1,-1):
 
 if l2[x]>=max2:
  max2=l2[x]
  c.append(i+1+x)
max=l1[0]  
for y in range(i):
  
 if l1[y]>=max:
  c.append(y)
  max=l1[y]
for j in sorted(c):
 print j+1,
else:print