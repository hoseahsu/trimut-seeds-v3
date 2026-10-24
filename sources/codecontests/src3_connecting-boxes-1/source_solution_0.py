#Salman Lari

import sys

n,q=map(int,sys.stdin.readline().split())

u=[]  #Used
up=[]   #Used_ Pair

for k in range(q):
    i,j=map(int,sys.stdin.readline().split())

    if i in u or j in u:
        print "NO"
        continue
    flag=1
    for l in range(len(up)):
        if i<up[l][1] and i>up[l][0]:
            if j>up[l][1] or j<up[l][0]:
                print "NO"
                flag=0
                break
        if j<up[l][1] and j>up[l][0]:
            if i>up[l][1] or i<up[l][0]:
                print "NO"
                flag=0
                break
    if flag==0:
        continue
    if i==j:
        print "NO"
        continue

    u.append(i)
    u.append(j)
    up.append([min(i,j),max(i,j)])
    print "YES"