import math

t=input()
while t:
	t0,t1,t2,v1,v2,d = map(int,raw_input().split())
	
	tim1=int(math.ceil(t1+(float(d)/v1)*60))
	tim2=int(math.ceil(t2+(float(d)/v2)*60))
	
	if(t1<t0 and t2<t0):
		print("-1")
	elif(t1>=t0 and t2<t0):
		print(tim1)
	elif(t1<t0 and t2>=t0):
		print(tim2)
	else:
		print(min(tim1,tim2))
	
	t=t-1