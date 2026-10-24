There are N positive integers A_1, A_2, ..., A_N. Takahashi can perform the following operation on these integers any number of times:

* Choose 1 \leq i \leq N and multiply the value of A_i by -2.



Notice that he multiplies it by minus two.

He would like to make A_1 \leq A_2 \leq ... \leq A_N holds. Find the minimum number of operations required. If it is impossible, print `-1`.

Constraints

* 1 \leq N \leq 200000
* 1 \leq A_i \leq 10^9

Input

Input is given from Standard Input in the following format:


N
A_1 A_2 ... A_N


Output

Print the answer.

Examples

Input

4
3 1 4 1


Output

3


Input

5
1 2 3 4 5


Output

0


Input

8
657312726 129662684 181537270 324043958 468214806 916875077 825989291 319670097


Output

7