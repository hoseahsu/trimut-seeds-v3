The string t_1t_2 ... t_k is good if each letter of this string belongs to at least one palindrome of length greater than 1.

A palindrome is a string that reads the same backward as forward. For example, the strings A, BAB, ABBA, BAABBBAAB are palindromes, but the strings AB, ABBBAA, BBBA are not.

Here are some examples of good strings: 

  * t = AABBB (letters t_1, t_2 belong to palindrome t_1 ... t_2 and letters t_3, t_4, t_5 belong to palindrome t_3 ... t_5); 
  * t = ABAA (letters t_1, t_2, t_3 belong to palindrome t_1 ... t_3 and letter t_4 belongs to palindrome t_3 ... t_4); 
  * t = AAAAA (all letters belong to palindrome t_1 ... t_5); 



You are given a string s of length n, consisting of only letters A and B.

You have to calculate the number of good substrings of string s.

Input

The first line contains one integer n (1 ≤ n ≤ 3 ⋅ 10^5) — the length of the string s.

The second line contains the string s, consisting of letters A and B.

Output

Print one integer — the number of good substrings of string s.

Examples

Input


5
AABBB


Output


6


Input


3
AAA


Output


3


Input


7
AAABABB


Output


15

Note

In the first test case there are six good substrings: s_1 ... s_2, s_1 ... s_4, s_1 ... s_5, s_3 ... s_4, s_3 ... s_5 and s_4 ... s_5.

In the second test case there are three good substrings: s_1 ... s_2, s_1 ... s_3 and s_2 ... s_3.