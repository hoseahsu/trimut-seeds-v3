def search(s):
    m = len(s)
    n = len(s[0])
    count = 0
    mat = [[[0,0]for i in range(n)] for i in range(m)]
    for i in range(m):
        for j in range(n):
            if s[i][j] != s[i][j-1]:
                mat[i][j][0] = mat[i][j-1][0] + 1
            else:
                mat[i][j][0] = 1
            if mat[i][j][0] >=32:
                if s[i][j] != s[i-1][j]:
                    mat[i][j][1] = mat[i-1][j][1]  + 1
                else:
                    mat[i][j][1] = 1
            else:
                mat[i][j][1] = 0
            if s[i][j] == "_" and mat[i][j][0]>=32 and mat[i][j][1]>=32:
                count+=1
    return count

r,c = raw_input().split()
s = [0]*int(r)
for i in range(int(r)):
    s[i] = raw_input()

print search(s)