import math
test = int(raw_input())
while test:
	test = test-1
	l = [ "Rohit", "Dhawan", "Kohli", "Yuvraj", "Raina" , "Dhoni", "Sir Jadeja"]
	k = int(raw_input())
	val = math.log(k/7.0+1)/math.log(2)
	n = int(math.ceil(val))
	sn_1 = 7*(int(math.pow(2,n-1))-1)
	inte = math.ceil(((k-sn_1)/math.pow(2,n-1)))
	print l[int(inte)-1]