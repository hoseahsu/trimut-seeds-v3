n=input()
num=raw_input()
num=num.split(" ")
num=map(int, num)
dum=[]
for i in num:
    if(i not in dum):
        dum.append(i)

for i in dum:
	print(i),