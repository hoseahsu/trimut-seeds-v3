def solve():
	n,k=[int(x) for x in raw_input().split()]
	nums =[0]
	nums.extend( [int(x) for x in raw_input().split()])
	
	for i in xrange(1,1+k+1):
		nums[i] = max(nums[i-1],nums[i])
		
	for i in xrange(1+k+1,n+1):
		nums[i] = max(nums[i-1],nums[i-k-1]+nums[i])
		
	print nums[n]
	

def main():
	for _ in xrange(input()):
		solve()
		
main()