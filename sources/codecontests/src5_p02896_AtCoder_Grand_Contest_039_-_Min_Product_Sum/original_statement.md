For each of the K^{NM} ways to write an integer between 1 and K (inclusive) in every square in a square grid with N rows and M columns, find the value defined below, then compute the sum of all those K^{NM} values, modulo D.

* For each of the NM squares, find the minimum among the N+M-1 integers written in the square's row or the square's column. The value defined for the grid is the product of all these NM values.

Constraints

* 1 \leq N,M,K \leq 100
* 10^8 \leq D \leq 10^9
* N,M,K, and D are integers.
* D is prime.

Input

Input is given from Standard Input in the following format:


N M K D


Output

Print the sum of the K^{NM} values, modulo D.

Examples

Input

2 2 2 998244353


Output

35


Input

2 3 4 998244353


Output

127090


Input

31 41 59 998244353


Output

827794103