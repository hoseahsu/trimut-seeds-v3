def lcm(x, y):
   if x > y:
       greater = x
   else:
       greater = y
   while(True):
       if((greater % x == 0) and (greater % y == 0)):
           lcm = greater
           break
       greater += 1
   return lcm
t = int(raw_input())
for j in range(t):
    c = 0
    n,a,b = tuple(map(int,raw_input().split()))
    if((a == 0) or ( b == 0)):
        print(-1)
    else:
        c = (int(n/a)) + (int(n/b)) -(int(n/(lcm(a,b))))        
        print(c)