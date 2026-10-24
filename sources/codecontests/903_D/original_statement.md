Let's denote a function 

<image>

You are given an array a consisting of n integers. You have to calculate the sum of d(ai, aj) over all pairs (i, j) such that 1 ≤ i ≤ j ≤ n.

Input

The first line contains one integer n (1 ≤ n ≤ 200000) — the number of elements in a.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109) — elements of the array. 

Output

Print one integer — the sum of d(ai, aj) over all pairs (i, j) such that 1 ≤ i ≤ j ≤ n.

Examples

Input

5
1 2 3 1 3


Output

4


Input

4
6 6 5 5


Output

0


Input

4
6 6 4 4


Output

-8

Note

In the first example:

  1. d(a1, a2) = 0; 
  2. d(a1, a3) = 2; 
  3. d(a1, a4) = 0; 
  4. d(a1, a5) = 2; 
  5. d(a2, a3) = 0; 
  6. d(a2, a4) = 0; 
  7. d(a2, a5) = 0; 
  8. d(a3, a4) = - 2; 
  9. d(a3, a5) = 0; 
  10. d(a4, a5) = 2. 