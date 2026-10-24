t = input()
for i in range(int(t)):
    i = map(int,raw_input().split())
    #i = i.split(' ')
    n = i[0]
    _list = i[1:]
    _list.sort()
    i,j,a,b = 0,n-1,100001,0
    while i<j:
        chk = _list[i]+_list[j]
        a = min(chk,a)
        b = max(chk,b)
        i += 1
        j -= 1
    print b-a