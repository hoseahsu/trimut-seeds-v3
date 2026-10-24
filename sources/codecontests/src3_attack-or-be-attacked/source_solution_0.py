from sys import stdin
def res(n,m):
	x = n-1; fir = (x*(x+1)*(x-1))/3;ti = m-n+1
	return n*m + 2*(2*fir + ti*n*(n-1))

a=stdin.readline().split()
x = int(a[0]);y=int(a[1]);p=int(a[2]);q=int(a[3]);
m=x;n=y
if m < n:
	m=y;n=x
total = m*n*m*n

rem = 0
fir = n-p
sec = m-q
if fir < 1:
	fir = 0
if sec < 1:
	sec = 0
rem+=4*fir*sec


fir = n-q
sec = m-p
if fir < 1:
	fir = 0
if sec < 1:
	sec = 0
rem+=4*fir*sec

total = total -res(n,m)-rem
print total % (10**9+7)