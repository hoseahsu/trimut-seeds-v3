We have an integer sequence A, whose length is N.

Find the number of the non-empty contiguous subsequences of A whose sums are 0. Note that we are counting the ways to take out subsequences. That is, even if the contents of some two subsequences are the same, they are counted individually if they are taken from different positions.

Constraints

* 1 \leq N \leq 2 \times 10^5
* -10^9 \leq A_i \leq 10^9
* All values in input are integers.

Input

Input is given from Standard Input in the following format:


N
A_1 A_2 ... A_N


Output

Find the number of the non-empty contiguous subsequences of A whose sum is 0.

Examples

Input

6
1 3 -4 2 2 -2


Output

3


Input

7
1 -1 1 -1 1 -1 1


Output

12


Input

5
1 -2 3 -4 5


Output

0