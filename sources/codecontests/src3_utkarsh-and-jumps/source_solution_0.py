n,p = map(int,raw_input().split())
p = float(p)
dp = [0] * (n+1)
dp[0] = 1
dp[1] = 0
dp[2] = p/100
dp[3] = 1-p/100
for i in range(4,n+1):
    dp[i] = (p/100) * dp[i-2] + (1-p/100) * dp[i-3]
print "%.6f"%dp[n]