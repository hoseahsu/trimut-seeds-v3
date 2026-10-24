A substring is a string of characters that is contained in another string. For example, the substrings of "abcdef" could be "abc", "bc", "cdef", "e" and so on. But, "bca", "ace", and "g" are not substrings of "abcdef". 

Your task is to count the number of non-empty substrings possible of a given string such that all characters in that substring are same. If two substrings contains same alphabets but appear at different positions in that given string, they are still considered to be different. 

Input

A single string without spaces

Output

a single integer denoting the number of substrings as described above

Constraints
length of string will be between 1 and 100
all characters of string will be small case alphabets only

SAMPLE INPUT
xxxyx

SAMPLE OUTPUT
8

Explanation

four occurrences of substring "x"

one occurrence of substring "y"

two occurrences of substring "xx"  

one occurrence of substring "xxx"

= total 8