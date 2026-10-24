p=input()
s=range(1000)
import string
for i in range(p):
	d=0
	n,m= map(int, raw_input().split())
	for i in range(n):
		s[i]=string.split(raw_input())
	for i in range(n-1):
		for j in range(m-1):
			if s[i][j]=="/" and s[i][j+1]=="\\" :
				if s[i+1][j]=="\\" and s[i+1][j+1]=="/":
					d=d+1
					
	print d