There are N boxes arranged in a row from left to right. The i-th box from the left contains A_i candies.

You will take out the candies from some consecutive boxes and distribute them evenly to M children.

Such being the case, find the number of the pairs (l, r) that satisfy the following:

* l and r are both integers and satisfy 1 \leq l \leq r \leq N.
* A_l + A_{l+1} + ... + A_r is a multiple of M.

Constraints

* All values in input are integers.
* 1 \leq N \leq 10^5
* 2 \leq M \leq 10^9
* 1 \leq A_i \leq 10^9

Input

Input is given from Standard Input in the following format:


N M
A_1 A_2 ... A_N


Output

Print the number of the pairs (l, r) that satisfy the conditions.

Note that the number may not fit into a 32-bit integer type.

Examples

Input

3 2
4 1 5


Output

3


Input

13 17
29 7 5 7 9 51 7 13 8 55 42 9 81


Output

6


Input

10 400000000
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000


Output

25