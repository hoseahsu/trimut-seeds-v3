'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
if __name__ == '__main__':
	cases = int(raw_input())
	start = 1
	while start <= cases:
		number = int(raw_input())
		no_of_occurances = 2 ** (number - 1)
		sum_of_numbers = (number * (number + 1)) / 2
		answer = no_of_occurances * sum_of_numbers
		print answer
		start = start + 1