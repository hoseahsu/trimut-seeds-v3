t = int(raw_input())

def check(k,dict):
	kk = str(k)
	for char in kk:
		if (dict.has_key(char) == True):
			return True;
	return False;

while (t>0):
	i = int(raw_input())
	j = str(i)
	dict = {}
	for char in j:
		dict[char] = 1
	k = 1;
	count = 0;
	while (k*k <= i):
		if (i % k == 0):
			if (check(k,dict) == True):
				count += 1;
			if (i/k != k and check(i/k,dict) == True):
				count += 1
		k += 1
	print count;
	t -= 1