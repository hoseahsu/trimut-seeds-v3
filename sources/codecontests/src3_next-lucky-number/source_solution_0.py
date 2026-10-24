def next_lucky(n):
    if len(n) == 0:
        return ''
    if int(n[0]) < 3:
        return '3'*len(n)
    elif int(n[0]) == 3:
        pos1 = int(n[0]+next_lucky(n[1:]))
        pos2 = int('5'+'3'*(len(n)-1))
        possible = min(pos1,pos2)
        larger = max(pos1,pos2)
        if possible > int(n):
            return str(possible)
        else:
            return str(larger)
    elif int(n[0]) < 5:
        return '5'+'3'*(len(n)-1)
    elif int(n[0]) == 5:
        pos1 = int(n[0]+next_lucky(n[1:]))
        pos2 = int('3'*(len(n)+1))
        possible = min(pos1,pos2)
        larger = max(pos1,pos2)
        if possible > int(n):
            return str(possible)
        else:
            return str(larger)
    elif int(n[0]) > 5:
        return '3'*(len(n)+1)


if __name__ == "__main__":
    for testcase in xrange(int(raw_input())):
        print next_lucky(raw_input())