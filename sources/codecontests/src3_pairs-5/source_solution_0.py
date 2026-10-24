arr = []
res = 0
for i in range(input()):
    arr.append(input())
    res += arr[i]
power = 1
n = len(arr)
for i in range(n): power *= 3
for i in range(power):
    temp = i
    s1, s2, s3 = 0,0,0
    for j in range(n):
        if temp % 3 == 0: s1+=arr[j]
        if temp % 3 == 1: s2+=arr[j]
        if temp % 3 == 2: s3+=arr[j]
        temp /= 3
    res = min(res, max(s1, max(s2, s3)))
print res