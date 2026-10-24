After learning basics of arrays and strings, Dark started wondering that if we can sort the numbers then why not STRINGS?

Deeply thinking and looking the various strings lying in the string pool, he decided to ascend or descend the string according to his wish.

Ascending means strings having all the characters in a string in a order like A,B,C,D,...,Z  while descending means string having all characters in a reverse order that is first all Z,Y,X,...,A and so on....

Note: String may contain all the characters available on the normal keyboard.
Thus Dark want you to help him design a code to sort the strings according to his wish the code has to sort either ascending or descending...

To make it easy, Dark wants to print only the characters which are Upper Case Alphabets present in the string in sorted form and don't display the other characters of the string.

Note: String will be only one word with mixture of any key present in the normal keyboard.

Input:

The first line contains T, the number of test cases.
Followed by T lines each contains space separated  a single string 'S' and a number 'N'.

N is even--> Ascending 

N is odd--> Descending

Output:

For every test case print the sorted form of the string.
Print "NULL" if their is no UPPER CASE ALPHABETS present in the string.

Constraints:

1 ≤ T ≤ 500
1 ≤ |S| ≤ 100000
0 ≤ N ≤ 100

Author : Darshak Mehta

SAMPLE INPUT
4
AABAHD 0
AABGHAD 1
AXBCD 0
AXBCD 1

SAMPLE OUTPUT
AAABDH
HGDBAAA
ABCDX
XDCBA