You are given $n$ integers $w_i (i = 0, 1, ..., n-1)$ to be sorted in ascending order. You can swap two integers $w_i$ and $w_j$. Each swap operation has a cost, which is the sum of the two integers $w_i + w_j$. You can perform the operations any number of times.

Write a program which reports the minimal total cost to sort the given integers.

Constraints

* $1 \leq n \leq 1,000$
* $0 \leq w_i\leq 10^4$
* $w_i$ are all different

Input

In the first line, an integer $n$ is given. In the second line, $n$ integers $w_i (i = 0, 1, 2, ... n-1)$ separated by space characters are given.

Output

Print the minimal cost in a line.

Examples

Input

5
1 5 3 4 2


Output

7


Input

4
4 3 2 1


Output

10