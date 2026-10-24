Given a matrix (H × W) which contains only 1 and 0, find the area of the largest square matrix which only contains 0s.

Constraints

* 1 ≤ H, W ≤ 1,400

Input


H W
c1,1 c1,2 ... c1,W
c2,1 c2,2 ... c2,W
:
cH,1 cH,2 ... cH,W


In the first line, two integers H and W separated by a space character are given. In the following H lines, ci,j, elements of the H × W matrix, are given.

Output

Print the area (the number of 0s) of the largest square.

Example

Input

4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0


Output

4