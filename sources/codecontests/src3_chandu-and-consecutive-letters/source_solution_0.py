T=input('')


while T>0:
	str = raw_input('')
	str1 = ""
	for index in range(0,len(str)-1):
		flag = False
		if str[index] != str[index+1]:
			flag = True
		if flag:
			str1+=str[index]
	str1+=str[len(str)-1]
	print(str1)
	T-=1