n=input()
a=map(int,raw_input().split())
m=input()
b=map(int,raw_input().split())
a=sorted(a)
b=sorted(b)
i=0
j=0
ans=[]
while i<len(a):
	if (a[i]==b[j]):
		i+=1
		j+=1
	else:
		if (len(ans)==0 or ans[-1]!=b[j]):
			ans.append(b[j])
		j+=1
if (j!=len(b) and (len(ans)==0 or ans[-1]!=b[j])):
	ans.append(b[j])
for x in ans:
	print x,