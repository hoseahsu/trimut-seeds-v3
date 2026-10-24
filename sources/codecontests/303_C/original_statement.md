You have been given n distinct integers a1, a2, ..., an. You can remove at most k of them. Find the minimum modular m (m > 0), so that for every pair of the remaining integers (ai, aj), the following unequality holds: <image>.

Input

The first line contains two integers n and k (1 ≤ n ≤ 5000, 0 ≤ k ≤ 4), which we have mentioned above. 

The second line contains n distinct integers a1, a2, ..., an (0 ≤ ai ≤ 106).

Output

Print a single positive integer — the minimum m.

Examples

Input

7 0
0 2 3 6 7 12 18


Output

13


Input

7 1
0 2 3 6 7 12 18


Output

7