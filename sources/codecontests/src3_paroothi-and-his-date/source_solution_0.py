A = [int(x) for x in raw_input().split(' ') if x!='']
a = [0]*A[1]
b = [int(x) for x in raw_input().split(' ') if x!='']

for i in range(0,A[0]):
	a[b[i]-1] = a[b[i]-1]+1

max=0
k=0
for i in range(0,A[1]):
	if max<a[i]:
		max = a[i]
		k=i		
		
print k+1