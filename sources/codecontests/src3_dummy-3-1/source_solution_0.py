test=int(input())
for i in range(test):
	numn=int(input())
	lst=[]
	
	lst=map(int,raw_input().split())
	lst2=[ 0 for x in range(len(lst))]
	for j in range(len(lst)):
		lst2[lst[j]-1]=j+1
	if lst==lst2:print'inverse'	
	else:print'not inverse'