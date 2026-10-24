def min_coins(money, denoms):
    # money : The money which is needed to get minimum coins
    # denoms : Available denominations
    denoms.sort()
 
    min = denoms[0] * money
    coin_list = {}
 
    for j in range(len(denoms)):
        temp = money
        used = 0
        coins = {}
        for i in range(1, len(denoms) - j + 1):
            coin = temp / denoms[-(i + j)]
            used += coin
            coins[denoms[-(i+j)]] = coin
            temp %= denoms[-(i+j)]
            if(temp <= 0):
                break
 
        if(used < min and temp == 0):
            min = used
            coin_list = coins
 
    if(coin_list == {}):
        print "ERROR"
    else:
        for denom in denoms:
            print "Rupee %d coin %d" %(denom, coin_list.get(denom, 0))
 
 
money = input()
lis = raw_input().split(',')
if(len(lis) == 1):
    lis = [int(lis[0][1:-1])]
else:
    lis[0] = lis[0][1:]
    lis[-1] = lis[-1][:-1]
    lis = [int(x) for x in lis]
 
min_coins(money, lis)