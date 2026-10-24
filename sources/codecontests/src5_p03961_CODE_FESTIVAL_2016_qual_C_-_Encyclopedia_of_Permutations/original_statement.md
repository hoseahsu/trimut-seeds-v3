One day Mr. Takahashi picked up a dictionary containing all of the N! permutations of integers 1 through N. The dictionary has N! pages, and page i (1 ≤ i ≤ N!) contains the i-th permutation in the lexicographical order.

Mr. Takahashi wanted to look up a certain permutation of length N in this dictionary, but he forgot some part of it.

His memory of the permutation is described by a sequence P_1, P_2, ..., P_N. If P_i = 0, it means that he forgot the i-th element of the permutation; otherwise, it means that he remembered the i-th element of the permutation and it is P_i.

He decided to look up all the possible permutations in the dictionary. Compute the sum of the page numbers of the pages he has to check, modulo 10^9 + 7.

Constraints

* 1 ≤ N ≤ 500000
* 0 ≤ P_i ≤ N
* P_i ≠ P_j if i ≠ j (1 ≤ i, j ≤ N), P_i ≠ 0 and P_j ≠ 0.

Input

The input is given from Standard Input in the following format:


N
P_1 P_2 ... P_N


Output

Print the sum of the page numbers of the pages he has to check, as modulo 10^9 + 7.

Examples

Input

4
0 2 3 0


Output

23


Input

3
0 0 0


Output

21


Input

5
1 2 3 5 4


Output

2


Input

1
0


Output

1


Input

10
0 3 0 0 1 0 4 0 0 0


Output

953330050