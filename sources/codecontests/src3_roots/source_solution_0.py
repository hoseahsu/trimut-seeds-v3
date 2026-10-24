'''
# Read input from stdin and provide input before running code
 
name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
def can_solve(equation):
	a = equation[0]
	b = equation[1]
	c = equation[2]
	if b * b < 4 * a * c:
		return False
	else:
		return True
 
 
if __name__ == '__main__':
	cases = int(raw_input().strip())
	start = 1
	solved = 0
	while start <= cases:
		equation = [int(x) for x in raw_input().strip().split(' ')]
		if can_solve(equation):
			solved = solved + 1
		start = start + 1
	print solved