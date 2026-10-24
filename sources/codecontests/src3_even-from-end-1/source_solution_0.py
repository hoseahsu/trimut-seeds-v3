while True:    
    try:
        s = raw_input()
    except:        
        break
    if len(s.rstrip().lstrip())==0:        
        break
    ser = map(int, s.split())
    srr = ser[1:][::-1]
    found = False
    for x in srr:
        if x % 2 == 0:
            found = True
            print x,
    if not found:
        print "None to display"
    else:
        print

exit()