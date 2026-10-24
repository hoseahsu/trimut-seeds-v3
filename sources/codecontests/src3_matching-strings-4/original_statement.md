Subodh'CS Department is writing a spell-checker system, and you have been tasked with writing a function to determine how closely two words resemble each other. The algorithm you are to use, albeit not a very good one, is to compare the two words character by character, and count how many times the characters in a given position are the same. 

For instance, the words "TICK" and "TOCK" have a score of 3, since three characters (T, C, K) are the same.

Similarly, "CAT" and "DOG" score 0, since no letters match.

You are given Strings A and B and you have to return an integer K indicating the score (as defined above) of how closely the two match.

Input :

First line of input contains an integer T denoting the number of test cases.
Each test case contains two lines of input, where first line contains the string A and second line contains the string B.

Output :

For each test case print the score on a line.

Constraints :
A and B will each contain between 1 and 500 characters, inclusive.
Each character of a and b will be 'A'-'Z'.
1 ≤ T ≤ 50

SAMPLE INPUT
4
TICK
TOCK
CAT
DOG
APPLE
APPLES 	
FANTASTIC
ANTASTIC

SAMPLE OUTPUT
3
0
5
0

Explanation

Test Case #1:

The first example from the problem statement.

Test Case #2:

The first example from the problem statement.

Test Case #3:

Notice the lengths are different, so the most we can compare is 5 characters, which are all identical.

Test Case #4:

Here's an example of why this particular method is far from ideal. In a situation like this, it appears one character is missing the from the second string, but by our algorithm as described, they score a 0 in similarity.