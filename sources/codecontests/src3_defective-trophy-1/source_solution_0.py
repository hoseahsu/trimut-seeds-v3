from math import ceil,log



def minCoins(coins):
		if coins==0:
				print 0
		else:		
			print int(ceil(log(coins,3)))


n=int(raw_input())
for i in range(n):
		coins=int(raw_input())
		minCoins(coins)