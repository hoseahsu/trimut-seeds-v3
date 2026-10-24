x,t = map(int,raw_input().strip().split())
l1 = map(int,raw_input().strip().split())
l2 = map(int,raw_input().strip().split())
l1 += l2
s = 0
c = 0
for i in sorted(l1):
	if s+i < t:
		s+=i
		c+=1
	else:
		break
print c