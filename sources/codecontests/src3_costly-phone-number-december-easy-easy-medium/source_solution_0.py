for _ in range(input()):
    total_cost = map(int, raw_input().split())
    for i in range(10):
        for j in range(1, 10):
            for k in range(j, 10):
            	total_cost[(j + k) % 10] = min(total_cost[(j + k) % 10], total_cost[j]+total_cost[k])
               
    input()
    Result = 0
    inputs = raw_input()
    for  v in inputs:
        Result += total_cost[int(v)]
    print Result