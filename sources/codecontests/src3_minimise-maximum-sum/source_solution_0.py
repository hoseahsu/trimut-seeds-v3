t=input()
for i in xrange(t):
	n=input()
	arr=[]
	arr=map(int,raw_input().split())
	arr.sort()
	l=len(arr)
	m=l
	arr2=[]
	for k in xrange(l/2):
		su=arr[k]+arr[m-1]
		arr2.append(su)
		m-=1
	print max(arr2)