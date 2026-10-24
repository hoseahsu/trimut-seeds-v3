n = int(raw_input())
lists = []
while n > 0:
	n = n-1
	lists.append(map(int,raw_input().split(" ")))

# lists.sort(lambda k : k[1]/k[0])
list2 = []
list3 = []
for x in lists:
#	print x[0],x[1]
	if x[1]/x[0] > 0:
		list2.append(x)
	else:
		list3.append(x)
list2.sort(key=lambda k: k[0])
list3.sort(key = lambda k : k[1], reverse=True)

sum1 = 0
#print list2,list3
min_sum = 999999
for item in list2:
	sum1 = sum1- item[0]
	min_sum = min(min_sum, sum1)
	sum1 = sum1 + item[1]

for item in list3:
	sum1 = sum1 - item[0]
	min_sum = min(min_sum, sum1)
	sum1 = sum1 + item[1]
print int(abs(min_sum))