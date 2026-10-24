import math
def centredist(x1, y1, x2, y2):
	return math.sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
x1, y1, r1 = map(int, raw_input().split());
x2, y2, r2 = map(int, raw_input().split());
d = centredist(x1, y1, x2, y2);
if(d == (r1 + r2)):	print "T";
elif(d < (r1 + r2)):	print "Y";
else:	print "N";