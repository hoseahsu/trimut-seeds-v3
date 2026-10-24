'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
num_of_sugarcanes = int(raw_input())
list_of_sugarcanes = map(int,raw_input().split())

max_of_sugarcanes = max(list_of_sugarcanes)

def xyz (list_of_sugarcanes, max_sugar):
    for x in list_of_sugarcanes:
        z = x
        while z < max_sugar:
            z *= 2
        if z > max_sugar:
            return "NO"
    return "YES"

print (xyz(list_of_sugarcanes, max_of_sugarcanes))