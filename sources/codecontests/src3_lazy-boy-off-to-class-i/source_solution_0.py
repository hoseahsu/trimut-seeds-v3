from math import ceil
for i in range(int(raw_input())):
	clas=[]
	total=0
	for k in range(7):
		arr=map(int,raw_input().strip().split())
		total+=arr[0]
		for j in range(1,arr[0]+1):
			clas.append(arr[2*j]-arr[2*j-1])
	
	atte=int(ceil(total*3.0/4))
	nota=total-atte
	
	for k in range(nota):
		max=0
		for j in range(1,total-k):
			if clas[j]>clas[max]:
				max=j
		tmp=clas[max]
		clas[max]=clas[j]
		clas[j]=tmp
			
	free=604800
	for k in range(atte):
		free=free-clas[k]
	print free