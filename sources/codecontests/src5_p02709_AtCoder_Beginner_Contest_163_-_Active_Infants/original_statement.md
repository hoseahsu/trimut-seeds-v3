There are N children standing in a line from left to right. The activeness of the i-th child from the left is A_i.

You can rearrange these children just one time in any order you like.

When a child who originally occupies the x-th position from the left in the line moves to the y-th position from the left, that child earns A_x \times |x-y| happiness points.

Find the maximum total happiness points the children can earn.

Constraints

* 2 \leq N \leq 2000
* 1 \leq A_i \leq 10^9
* All values in input are integers.

Input

Input is given from Standard Input in the following format:


N
A_1 A_2 ... A_N


Output

Print the maximum total happiness points the children can earn.

Examples

Input

4
1 3 4 2


Output

20


Input

6
5 5 6 1 1 1


Output

58


Input

6
8 6 9 1 2 1


Output

85