while(True):
	try:
		str=raw_input()
	except:
		break
	new="."
	old="->"
	x=str.find("//")
	if(x==-1):
		print str.replace(old,new)
	else:
		print str[:x].replace(old,new)+str[x:]