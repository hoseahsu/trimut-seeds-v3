You have been given a set of N strings S1, S2, .... SN. Consider any non-empty string S (S need not belong to the given set of N strings). Suppose S occurs (as a substring) in K out of the N given strings in the set. Your job is to choose S such that the value of K is maximized. If there are many such strings, choose the one with the least length. If there are many such strings with the least length, choose the lexicographically smallest of them all.

Input:

The first line consists of T the number of test cases.
The first line in each test case consists of N, the number of words in the given set. Each of the next N lines contains a single word consisting of lowercase English alphabets (a-z) only.

Output:

Print the answer to each test case on a new line, the answer to each test case being a single string S as described in the problem above.

Constraints :

1 ≤ T ≤ 5

1 ≤ N ≤ 100

1 ≤ |Si| ≤ 100, |Si| denotes the length of the input words.

Author : Himanshu

Tester : Shreyans

(By IIT Kgp HackerEarth Programming Club)

SAMPLE INPUT
1
1
shades

SAMPLE OUTPUT
a