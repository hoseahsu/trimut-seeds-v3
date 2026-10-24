t = int(raw_input())
for i in range(t):
	arr = list(map(int,raw_input().split()))
	arr = arr[1:]
	ans = sum(arr)
	if ans%2 == 1:
	    print 'No'
	else:
	    print 'Yes'