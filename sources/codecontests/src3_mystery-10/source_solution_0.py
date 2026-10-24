k='qwertyuiopasdfghjklzxcvbnm'
a='abcdefghijklmnopqrstuvwxyz'

o=''
    
for _ in range(input()):
    string=raw_input()
    o=''
    for i in string:
        if i!=' ':
            o+=k[a.index(i)]
        else:
            o+=' '
    print o