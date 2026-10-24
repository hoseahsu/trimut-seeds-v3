If there is an integer not less than 0 satisfying the following conditions, print the smallest such integer; otherwise, print `-1`.

* The integer has exactly N digits in base ten. (We assume 0 to be a 1-digit integer. For other integers, leading zeros are not allowed.)
* The s_i-th digit from the left is c_i. \left(i = 1, 2, \cdots, M\right)

Constraints

* All values in input are integers.
* 1 \leq N \leq 3
* 0 \leq M \leq 5
* 1 \leq s_i \leq N
* 0 \leq c_i \leq 9

Input

Input is given from Standard Input in the following format:


N M
s_1 c_1
\vdots
s_M c_M


Output

Print the answer.

Examples

Input

3 3
1 7
3 2
1 7


Output

702


Input

3 2
2 1
2 3


Output

-1


Input

3 1
1 0


Output

-1