Takahashi throws N dice, each having K sides with all integers from 1 to K. The dice are NOT pairwise distinguishable. For each i=2,3,...,2K, find the following value modulo 998244353:

* The number of combinations of N sides shown by the dice such that the sum of no two different sides is i.



Note that the dice are NOT distinguishable, that is, two combinations are considered different when there exists an integer k such that the number of dice showing k is different in those two.

Constraints

* 1 \leq K \leq 2000
* 2 \leq N \leq 2000
* K and N are integers.

Input

Input is given from Standard Input in the following format:


K N


Output

Print 2K-1 integers. The t-th of them (1\leq t\leq 2K-1) should be the answer for i=t+1.

Examples

Input

3 3


Output

7
7
4
7
7


Input

4 5


Output

36
36
20
20
20
36
36


Input

6 1000


Output

149393349
149393349
668669001
668669001
4000002
4000002
4000002
668669001
668669001
149393349
149393349