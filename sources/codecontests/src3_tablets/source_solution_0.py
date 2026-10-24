import sys
inp = sys.stdin.readline

def noTablets(a, n):
	countTablets = 1
	countIf = 1
	countElse = 1
	ind = 0
	for i in range(1, n):
		if a[i] > a[i-1]:
			countIf += 1
			countElse = 0
			countTablets += countIf;
			ind = countIf
		elif a[i-1] == a[i]:
			countIf = 1
			countElse = 0
			countTablets += 1
			ind = 1
		else:
			countIf = 1
			countElse += 1
			countTablets += countElse 
			if countElse >= ind and ind != 0:
				countTablets += 1
			
	return countTablets
			 

def main():
	n = int(inp())
	arr = []
	for i in range(n):
		arr.append(int(inp()))

	print noTablets(arr, n)

main()