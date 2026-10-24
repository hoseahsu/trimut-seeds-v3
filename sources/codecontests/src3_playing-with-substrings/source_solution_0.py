a,b=raw_input().split()
ans=[]
i=0
while i<len(a):
	j=i
	while j<len(a):
		t=a[i:j+1]
		if b in t:
			if t not in ans:
				ans.append(t)
		j+=1
	i+=1
print len(ans)