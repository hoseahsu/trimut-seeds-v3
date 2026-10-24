For a given sequence A = {a0, a1, ... , an-1}, find the length of the longest increasing subsequnece (LIS) in A.

An increasing subsequence of A is defined by a subsequence {ai0, ai1, ... , aik} where 0 ≤ i0 < i1 < ... < ik < n and ai0 < ai1 < ... < aik.

Constraints

* 1 ≤ n ≤ 100000
* 0 ≤ ai ≤ 109

Input


n
a0
a1
:
an-1



In the first line, an integer n is given. In the next n lines, elements of A are given.

Output

The length of the longest increasing subsequence of A.

Examples

Input

5
5
1
3
2
4


Output

3


Input

3
1
1
1


Output

1