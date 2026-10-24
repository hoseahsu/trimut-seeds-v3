import sys

t = int(raw_input())

for i in range(0,t):
	products,shops = map(int,raw_input().split())
	for prod in range(0,products):
		bestShop=1;
		bestPrice=101;
		for m in range(1,shops+1):
			basePrice=100.00;
			for discount in raw_input().split():
				if(int(discount)==100):
					basePrice=0;
					break;
				basePrice=basePrice-float(basePrice)*(int(discount))/100;
			# print "---",
			# print prod,m, basePrice
			# 	print basePrice
			# print "---"
			if(bestPrice>basePrice):
				bestPrice=basePrice;
				bestShop=m;
		# print "\n"+str(bestShop)
		print bestShop,
	print "\n",