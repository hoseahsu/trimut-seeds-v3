def find(r,a,b):
	if (a*a)+(b*b) <= 4*r*r:
		print "ALICE"
	else:
		print "EQUAL"

if __name__ == '__main__':
	t=int(raw_input())
	while t>0:
		(r,a,b) = map(int,raw_input().split())
		find(r,a,b)
		t-=1