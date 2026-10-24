You are given a permutation p_1, p_2, ..., p_n. You should answer q queries. Each query is a pair (l_i, r_i), and you should calculate f(l_i, r_i).

Let's denote m_{l, r} as the position of the maximum in subsegment p_l, p_{l+1}, ..., p_r.

Then f(l, r) = (r - l + 1) + f(l, m_{l,r} - 1) + f(m_{l,r} + 1, r) if l ≤ r or 0 otherwise.

Input

The first line contains two integers n and q (1 ≤ n ≤ 10^6, 1 ≤ q ≤ 10^6) — the size of the permutation p and the number of queries.

The second line contains n pairwise distinct integers p_1, p_2, ..., p_n (1 ≤ p_i ≤ n, p_i ≠ p_j for i ≠ j) — permutation p.

The third line contains q integers l_1, l_2, ..., l_q — the first parts of the queries.

The fourth line contains q integers r_1, r_2, ..., r_q — the second parts of the queries.

It's guaranteed that 1 ≤ l_i ≤ r_i ≤ n for all queries.

Output

Print q integers — the values f(l_i, r_i) for the corresponding queries.

Example

Input


4 5
3 1 4 2
2 1 1 2 1
2 3 4 4 1


Output


1 6 8 5 1 

Note

Description of the queries: 

  1. f(2, 2) = (2 - 2 + 1) + f(2, 1) + f(3, 2) = 1 + 0 + 0 = 1; 
  2. f(1, 3) = (3 - 1 + 1) + f(1, 2) + f(4, 3) = 3 + (2 - 1 + 1) + f(1, 0) + f(2, 2) = 3 + 2 + (2 - 2 + 1) = 6; 
  3. f(1, 4) = (4 - 1 + 1) + f(1, 2) + f(4, 4) = 4 + 3 + 1 = 8; 
  4. f(2, 4) = (4 - 2 + 1) + f(2, 2) + f(4, 4) = 3 + 1 + 1 = 5; 
  5. f(1, 1) = (1 - 1 + 1) + 0 + 0 = 1. 