n=int(raw_input())
arr=map(int,raw_input().split())
arr=sorted(arr)
count=1
start=arr[0]
end=arr[0]+4
for i in range(1,n):
	if arr[i]<=end:
		continue
	start=arr[i]
	end=start+4
	count+=1
print count