def main():
	t = int(raw_input().strip())
	while t !=0:
		
		n, k = [int(x) for x in raw_input().split()]
		arr = [int(x) for x in raw_input().split()]
		
		i = 0
		while i<n and k !=0:
			temp = arr[i]
			min_index = i
			for j in xrange(i+1, min(k+i+1, n)):
				if arr[j]<temp:
					min_index = j
					temp =arr[j]
			if min_index == i:
				i += 1
				continue
			else:
				k -= min_index - i
				temp = arr[min_index]
				for j in xrange(min_index, i, -1):
					arr[j] = arr[j-1]
				arr[i]= temp
				i += 1
		for i in arr:
			print i, 
		print
		t-=1

if __name__ == '__main__':
	main()