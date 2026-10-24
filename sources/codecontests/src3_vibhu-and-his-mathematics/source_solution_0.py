n=int(raw_input())
in_array=[]
for i in xrange(n):
	num=int(raw_input())
	in_array.append(num)

mx=max(in_array)
arr=[1,1]
	

for j in xrange(2,mx+1):
	
	arr.append((arr[j-1]+(j-1)*arr[j-2])%(10**9+7))
	
for i in in_array:
	print arr[i]