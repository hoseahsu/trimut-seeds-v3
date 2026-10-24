'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''

line1 = raw_input()
arr_inp=[]
for j in line1.split(' '):
	arr_inp.append(int(j))
line2 = raw_input()
elemnt_array = {}
for i in line2.split(' '):
	elemnt_array[int(i)] = 1
#elemnt_array.sort()
#print elemnt_array, "and quries are", arr_inp[1]
for i in range (arr_inp[1]):
	if int(input()) in elemnt_array:
		print "YES"
	else:
		print "NO"