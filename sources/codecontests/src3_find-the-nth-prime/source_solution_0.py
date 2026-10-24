no = input()
c = 0
for pk in range(2,7920):
    am = 0
    for qd in range(2,(pk/2)+1):
        if (pk % qd == 0):
            am = 1
            break
    if (am == 0):
        c = c + 1
        if(c == no):
            print pk
            break