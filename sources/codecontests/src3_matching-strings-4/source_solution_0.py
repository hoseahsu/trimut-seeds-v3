import sys
from sys import stdin

def main():
    T = int(stdin.readline().strip())
    for i in xrange(T):
        a = stdin.readline().strip()
        b = stdin.readline().strip()
        diff = abs(len(a) - len(b))
        if len(a) > len(b):
            a = a[:len(a) - diff]
        elif len(b) >len(a):
            b = b[:len(b)-diff]
        count = 0
        for j in xrange(len(a)):
            if a[j]== b[j]:
                count += 1
        print count
        

if __name__ == '__main__':
	main()