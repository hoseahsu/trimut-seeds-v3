n, x = map(int, raw_input().split())
new_a = map(int, raw_input().split())

count = 0
skip = 0
for i in range(n):
	if(new_a[i] <= x and skip <= 1):
		count = count + 1
	if(new_a[i] > x):
		skip = skip + 1
print count