import math
#import decimal from *

def func(x1,y1,x2,y2,x3,y3):
	area = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)
	if area < 0.0:
		area = -area
	area = area*(0.5)
	return area

t = int(raw_input())

while t > 0:
	st = raw_input()
	
	st = st.split(' ')
	
	x1 = float(st[0])
	y1 = float(st[1])
	
	x2 = float(st[2])
	y2 = float(st[3])
	
	x3 = float(st[4])
	y3 = float(st[5])
	
	x4 = float(st[6])
	y4 = float(st[7])
	
	a = func(x1,y1,x2,y2,x3,y3)
	
	#if a == 0.0:
	#	print "INSIDE"
	
	a1 = func(x4,y4,x2,y2,x3,y3)
	a2 = func(x1,y1,x4,y4,x3,y3)
	a3 = func(x1,y1,x2,y2,x4,y4)
	
	s = a1+a2+a3
	if s == a:
		print "INSIDE"
	else: 
		print "OUTSIDE"
	
	t = t - 1