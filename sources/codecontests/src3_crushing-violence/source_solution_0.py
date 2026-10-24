from collections import Counter
n=input()

for i in xrange(0,n):
    x=input()
    boys={}
    girls={}
    boy_crush=[int(x) for x in raw_input().split()]
    girl_crush=[int(x) for x in raw_input().split()]
    boy_crush.insert(0,0)
    girl_crush.insert(0,0)
    for i in xrange(1,len(boy_crush)):
        temp=boy_crush[i]
        temp2=girl_crush[temp]
        if i!=temp2:
            boys[i]=temp2
    for i in xrange(1, len(girl_crush)):
        temp = girl_crush[i]
        temp2 = boy_crush[temp]
        if i != temp2:
            girls[i] = temp2

    a=Counter(boys.values())
    b=Counter(girls.values())
    if a.values():
        max_boys=max(a.values())
    else:
        max_boys=0
    if b.values():
        max_girls=max(b.values())
    else:
        max_girls=0
    
    count=0
    #print boys.keys()
    #print girls.keys()
    for key in boys.keys():
        val=boys[key]
        if boys.has_key(val):
            if boys[val]==key:
                count+=1
    for key in girls.keys():
        val=girls[key]
        if girls.has_key(val):
            if girls[val]==key:
                count+=1
    print max(max_boys,max_girls),
    print count/2