N, M = map(int, raw_input().split())

memory = {}

for i in range(N):
	x = map(int, raw_input().split())
	for index, elem in enumerate(x):
		memory[elem] = str(i) + ' ' + str(index)

Q = int(raw_input())

for k in range(Q):
	q = int(raw_input())
	if q in memory:
		print memory[q]
	else:
		print '-1 -1'