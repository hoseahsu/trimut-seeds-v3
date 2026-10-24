bindict = {'000':0,'001':1,'010':2,'100':4,'101':5,'110':6,'111':7,'011':3}
binary = raw_input().split('.')

for index,value in enumerate(binary):
    arr = []
    if(index==0):   
        while(len(value)%3!=0):
            value='0'+value
        j = 1
        i = 0
        while(j<=len(value)):
            if(j%3==0):
                arr.append(value[i:j])
                i = j
            j+=1
        total = ''
        for k in arr:
            total+=str(bindict[k])
    if(index==1):
        total+='.'
        while(len(value)%3!=0):
            value=value+'0'
        j = 1
        i = 0
        while(j<=len(value)):
            if(j%3==0):
                arr.append(value[i:j])
                i = j
            j+=1
        for k in arr:
            total+=str(bindict[k])
    
    string = ''
    for i in total:
        if(i=='.'):
            string+=' '
        else:
            string+=chr(64+int(i))
print total+ ' '+string