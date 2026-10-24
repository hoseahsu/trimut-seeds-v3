for _ in range(input()):
    strn = raw_input().strip()
    le = len(strn)
    if le < 3:
        print "0"
        continue
    index = 0 
    f = 1
    while index < le / 2:
        if strn[index] == strn[-1-index]:
            index+=1
        else:
            f = 0
            break
    if f == 1:
        print "-1"
        continue
    f = 1
    spl = index
    while index<le/2:
        if strn[index] == strn[-2-index]:
            index +=1
        else:
            f = 0
            break
    if f == 1:
        print le - 1 - spl
    else:
        print spl