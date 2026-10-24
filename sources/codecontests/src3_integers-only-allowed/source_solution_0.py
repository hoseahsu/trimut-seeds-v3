from fractions import gcd
n = input()
vertices = []
for i in range(n):
    vertices.append(map(int, raw_input().split()))
vertices.append(vertices[0])
b = 0
for i in range(n):
    dx = abs(vertices[i + 1][0] - vertices[i][0])
    dy = abs(vertices[i + 1][1] - vertices[i][1])
    b += gcd(dx, dy)

b = max(0, b)
area = 0
for i in range(n):
    area += (vertices[i][0] + vertices[i + 1][0]) * \
        (vertices[i][1] - vertices[i + 1][1])
area /= 2.0
ans = area + 1 - b / 2.0
print int(ans)