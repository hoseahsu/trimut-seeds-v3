Two strings are said to be anagrams of each other if the letters of one string may be rearranged to make the other string. For example, the words 'elvis' and 'lives' are anagrams.

In this problem you’ll be given two strings. Your job is to find if the two strings are anagrams of each other or not. If they are not anagrams then find the lexicographically smallest palindrome (in lowercase alphabets) that may be appended to the end of either one of the two strings so that they become anagrams of each other.

The lower and upper case letters are considered equivalent. The number of spaces  or any other punctuation or digit is not important.

One string is called lexicographically smaller than another if, at the first position where they differ the first one has smaller alphabet. For example, the strings 'hello' and 'herd' first differ at the third alphabet; 'l' is smaller than 'r', so 'hello' is lexicographically smaller than 'herd'.

A Palindrome is a string that is the same when read forward or backward. For example, the string 'bird rib' is a palindrome, whereas 'hello' is not.

INPUT:

The first line of the input contains a number T, the number of test cases. T test cases follow. Each test case consists of two lines, one string in each line.

OUTPUT:

For each test case output a single line. Print ‘YES’ (without the quotes) if the two strings are anagrams of each other. If they are not, then print the lexicographically smallest palindromic string as discussed above. If no such string exists, then print ‘NO LUCK’ (without the quotes).

CONSTRAINTS:

1 ≤ T ≤ 100

1 ≤ length of the strings ≤ 100

SAMPLE INPUT
5
Computer programmer
mature germ romp crop
Awaaay
away
internet
web
abc221
abcdede
the terminator
I?m rotten hater

SAMPLE OUTPUT
YES
aa
NO LUCK
deed
YES

Explanation

'Computer programmer'  and 'mature germ romp crop' are anagrams so the output is YES.

'Awaaay' and 'away' are not anagrams, but 'aa' may be appended to the end of 'away' so that 'Awaaay' and 'awayaa' become anagrams. Therefore the output is 'aa' ( without the quotes).

'internet' and 'web' are not anagrams and no palindromic string can be added to the end of any one of them to make them anagrams, therefore the answer is 'NO LUCK'.

'abc' and 'abcdede' are not anagrams. But 'deed' or 'edde' may be appended to the end of 'abc' to make them anagrams. As, 'deed' is lexicographically smaller than 'edde', the output is 'deed'