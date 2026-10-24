There is a sequence of length N: a = (a_1, a_2, ..., a_N). Here, each a_i is a non-negative integer.

Snuke can repeatedly perform the following operation:

* Let the XOR of all the elements in a be x. Select an integer i (1 ≤ i ≤ N) and replace a_i with x.



Snuke's objective is to match a with another sequence b = (b_1, b_2, ..., b_N). Here, each b_i is a non-negative integer.

Determine whether the objective is achievable, and find the minimum necessary number of operations if the answer is positive.

Constraints

* 2 ≤ N ≤ 10^5
* a_i and b_i are integers.
* 0 ≤ a_i, b_i < 2^{30}

Input

Input is given from Standard Input in the following format:


N
a_1 a_2 ... a_N
b_1 b_2 ... b_N


Output

If the objective is achievable, print the minimum necessary number of operations. Otherwise, print `-1` instead.

Examples

Input

3
0 1 2
3 1 0


Output

2


Input

3
0 1 2
0 1 2


Output

0


Input

2
1 1
0 0


Output

-1


Input

4
0 1 2 3
1 0 3 2


Output

5