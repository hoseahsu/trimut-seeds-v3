t = input();
while(t > 0):
	n, k, p = map(int, raw_input().split()); cl = p;
	a = [int(i) for i in raw_input().split()];
	for i in range(0, k):
		if(a[i] <= cl):	cl += 1;
	if(cl <= n):	print cl;
	else:	print -1;
	t -= 1;