import math
def count(x, y):
    z = [1] * ( y  - x + 1)

    for i in range(2, int(math.sqrt(y)) + 1):
        step = i ** 2
        if x % step == 0: j = x
        else: j = x + step - (x%step)

        while(j <= y):
            z[j - x] = 0
            j += step

    return z.count(1)
       
def get():
    t = int(raw_input())
    for i in range(t):
        s = raw_input().split()
        x, y = int(s[0]), int(s[1])
        if x > y: x, y = y, x
        print count(x, y)

if __name__=="__main__":
    get()