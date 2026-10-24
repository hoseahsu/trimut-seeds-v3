t = int(raw_input())
for j in range(t):
    a = int(raw_input())
    c = []
    d = []
    for i in range(a):
        x = raw_input()
        c.append(x)
        
    for i in c:
        if i not in d:
            d.append(i)
    d.sort()
    for i in d:
        print i