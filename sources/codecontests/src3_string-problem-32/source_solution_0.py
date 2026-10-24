def computeLPSArray(txt, M, lps):
    lens = 0
    lps[0] = 0
    i = 1
    while i < M:
        if txt[i] == txt[lens]:
            lens += 1
            lps[i] = lens
            i += 1
        else:
            if lens != 0:
                lens = lps[lens - 1]
            else:
                lps[i] = 0
                i += 1
    return lps            
                
        

cs = 1
for _ in range(input()):
    txt = raw_input().strip()
    M   = len(txt)
    lps = [None] * M
    j = 0
    lps1 = computeLPSArray(txt, M, lps)
    x = lps[M-1]
    if x == 0:x = -1
    print "Case {}: {}".format(cs, x)
    cs += 1