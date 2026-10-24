from string import ascii_lowercase,ascii_uppercase
alp=ascii_lowercase+ascii_uppercase
def lpalin(S):
    l=list(S)
    one,two=0,0
    d=set(l);ch=''
    for i in d:
        if l.count(i)%2==0:two+=1
        else:one+=1;ch=i
    if one>1:
        return '0'
    else:
        f='';g=ch
        sx=list(set(l));sx.sort()
        for i in sx:
            f+=i*(l.count(i)/2)
        f+=g+f[-1::-1]
        return f
    
for fx in range(input()):
    x,y='',''
    f=raw_input()
    g=raw_input()
    for i in f:
        if i in alp:x+=i.lower()
    for i in g:
        if i in alp:y+=i.lower()
    err=False
    if len(x)!=len(y):
        if len(x)<len(y):x,y=y,x
        for i in y:
            if i in x:
                d=x.index(i)
                x=x[:d]+x[d+1:]
            else:
                err=True;break
        if err:print 'NO LUCK'
        else:
            d=lpalin(x)
            if d=='0':print 'NO LUCK'
            else:print d
    else:
        a=list(x)
        b=list(y)
        a.sort()
        b.sort()
        if a==b:
            print 'YES'
        else:print 'NO LUCK'