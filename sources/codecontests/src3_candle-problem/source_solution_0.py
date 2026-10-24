n = int(raw_input())
ans = n / 5
r = n % 5 + ans
while r  >= 5:
	ans += r / 5
	r = r % 5 + r / 5
print ans