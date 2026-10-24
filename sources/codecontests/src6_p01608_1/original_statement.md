1

Problem Statement

There is a bit string of length n.

When the i-th bit from the left is 1, the score is a_i points.
The number of 1s within the distance w around the i-th bit from the left (= | \\ {j \ in \\ {1, ..., n \\} ∩ \\ {iw, ..., i + w \\} | When the jth bit from the left is 1 \\} |) is odd, the score is b_i.

Find the bit string that gives the most scores.

Constraints

* 1 ≤ n ≤ 1,000
* 1 ≤ w ≤ 1,000
* 0 ≤ a_i ≤ 10 ^ 5
* 0 ≤ b_i ≤ 10 ^ 5

Input

Input follows the following format. All given numbers are integers.


n w
a_1 ... a_n
b_1 ... b_n

Output

Output the bit string that gives the most scores on one line.
If there are multiple such solutions, any of them may be output.

Examples

Input

4 1
3 1 2 7
13 8 25 9


Output

1001


Input

2 1
1 1
3 3


Output

10