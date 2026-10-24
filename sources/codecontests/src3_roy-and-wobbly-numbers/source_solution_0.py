combos = []
for i in range(1, 10):
	for j in range(0, 10):
		if i != j:
			combos += [[i, j]]
for i in range(input()):
	n, k = map(int, raw_input().rstrip().split())
	if k > 81: print -1
	else:
		numbers = combos[k-1]
		ans = ""
		for i in range(n):
			ans += str(numbers[i % 2])
		print ans