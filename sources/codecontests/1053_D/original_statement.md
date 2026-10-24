You are given a tuple generator f^{(k)} = (f_1^{(k)}, f_2^{(k)}, ..., f_n^{(k)}), where f_i^{(k)} = (a_i ⋅ f_i^{(k - 1)} + b_i) mod p_i and f^{(0)} = (x_1, x_2, ..., x_n). Here x mod y denotes the remainder of x when divided by y. All p_i are primes.

One can see that with fixed sequences x_i, y_i, a_i the tuples f^{(k)} starting from some index will repeat tuples with smaller indices. Calculate the maximum number of different tuples (from all f^{(k)} for k ≥ 0) that can be produced by this generator, if x_i, a_i, b_i are integers in the range [0, p_i - 1] and can be chosen arbitrary. The answer can be large, so print the remainder it gives when divided by 10^9 + 7

Input

The first line contains one integer n (1 ≤ n ≤ 2 ⋅ 10^5) — the number of elements in the tuple.

The second line contains n space separated prime numbers — the modules p_1, p_2, …, p_n (2 ≤ p_i ≤ 2 ⋅ 10^6).

Output

Print one integer — the maximum number of different tuples modulo 10^9 + 7.

Examples

Input

4
2 3 5 7


Output

210


Input

3
5 3 3


Output

30

Note

In the first example we can choose next parameters: a = [1, 1, 1, 1], b = [1, 1, 1, 1], x = [0, 0, 0, 0], then f_i^{(k)} = k mod p_i.

In the second example we can choose next parameters: a = [1, 1, 2], b = [1, 1, 0], x = [0, 0, 1].