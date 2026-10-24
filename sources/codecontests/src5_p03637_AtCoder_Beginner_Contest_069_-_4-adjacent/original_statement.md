We have a sequence of length N, a = (a_1, a_2, ..., a_N). Each a_i is a positive integer.

Snuke's objective is to permute the element in a so that the following condition is satisfied:

* For each 1 ≤ i ≤ N - 1, the product of a_i and a_{i + 1} is a multiple of 4.



Determine whether Snuke can achieve his objective.

Constraints

* 2 ≤ N ≤ 10^5
* a_i is an integer.
* 1 ≤ a_i ≤ 10^9

Input

Input is given from Standard Input in the following format:


N
a_1 a_2 ... a_N


Output

If Snuke can achieve his objective, print `Yes`; otherwise, print `No`.

Examples

Input

3
1 10 100


Output

Yes


Input

4
1 2 3 4


Output

No


Input

3
1 4 1


Output

Yes


Input

2
1 1


Output

No


Input

6
2 7 1 8 2 8


Output

Yes