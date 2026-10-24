t = int(raw_input())
for _ in range(t):
	n, a, b, c = map(int, raw_input().split())
	ways = 0
	for i in range(a + 1):
		for j in range(min(n - i, b) + 1):
			if(n - i - j < 0):
				break
			else:
				ways += min(n - i - j, c) + 1
	print(ways)