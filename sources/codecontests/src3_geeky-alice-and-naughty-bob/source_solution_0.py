facts = [0, 1, 2, 6, 6, 3]

for _ in range(input()):
    ans = 0
    a, b = map(int, raw_input().split())
    if a >=6:
        ans = 9 * (b - a + 1)
    elif a < 6 and b >=6:
        ans = 9 * (b - 6 + 1)
        for i in range(a, 6):
            ans += facts[i]
    elif b < 6:
        for i in range(a, b+1):
            ans += facts[i]
    print ans