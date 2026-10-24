m = int(raw_input())
dict = {}
for i in raw_input().split(" "):
	dict[int(i)] = 0
girls = 0
for j in range(input()):
	count = 0
	for e in raw_input().split(" "):
		if int(e) in dict:
			count+=1
	if (count >= m):
		girls+=1
print girls