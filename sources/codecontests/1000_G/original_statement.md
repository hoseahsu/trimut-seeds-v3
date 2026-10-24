You are given a weighted tree (undirected connected graph with no cycles, loops or multiple edges) with n vertices. The edge \\{u_j, v_j\} has weight w_j. Also each vertex i has its own value a_i assigned to it.

Let's call a path starting in vertex u and ending in vertex v, where each edge can appear no more than twice (regardless of direction), a 2-path. Vertices can appear in the 2-path multiple times (even start and end vertices).

For some 2-path p profit Pr(p) = ∑_{v ∈ distinct vertices in  p}{a_v} - ∑_{e ∈ distinct edges in  p}{k_e ⋅ w_e}, where k_e is the number of times edge e appears in p. That is, vertices are counted once, but edges are counted the number of times they appear in p.

You are about to answer m queries. Each query is a pair of vertices (qu, qv). For each query find 2-path p from qu to qv with maximal profit Pr(p).

Input

The first line contains two integers n and q (2 ≤ n ≤ 3 ⋅ 10^5, 1 ≤ q ≤ 4 ⋅ 10^5) — the number of vertices in the tree and the number of queries.

The second line contains n space-separated integers a_1, a_2, ..., a_n (1 ≤ a_i ≤ 10^9) — the values of the vertices.

Next n - 1 lines contain descriptions of edges: each line contains three space separated integers u_i, v_i and w_i (1 ≤ u_i, v_i ≤ n, u_i ≠ v_i, 1 ≤ w_i ≤ 10^9) — there is edge \\{u_i, v_i\} with weight w_i in the tree.

Next q lines contain queries (one per line). Each query contains two integers qu_i and qv_i (1 ≤ qu_i, qv_i ≤ n) — endpoints of the 2-path you need to find.

Output

For each query print one integer per line — maximal profit Pr(p) of the some 2-path p with the corresponding endpoints.

Example

Input

7 6
6 5 5 3 2 1 2
1 2 2
2 3 2
2 4 1
4 5 1
6 4 2
7 3 25
1 1
4 4
5 6
6 4
3 4
3 7


Output

9
9
9
8
12
-14

Note

Explanation of queries: 

  1. (1, 1) — one of the optimal 2-paths is the following: 1 → 2 → 4 → 5 → 4 → 2 → 3 → 2 → 1. Pr(p) = (a_1 + a_2 + a_3 + a_4 + a_5) - (2 ⋅ w(1,2) + 2 ⋅ w(2,3) + 2 ⋅ w(2,4) + 2 ⋅ w(4,5)) = 21 - 2 ⋅ 12 = 9. 
  2. (4, 4): 4 → 2 → 1 → 2 → 3 → 2 → 4. Pr(p) = (a_1 + a_2 + a_3 + a_4) - 2 ⋅ (w(1,2) + w(2,3) + w(2,4)) = 19 - 2 ⋅ 10 = 9. 
  3. (5, 6): 5 → 4 → 2 → 3 → 2 → 1 → 2 → 4 → 6. 
  4. (6, 4): 6 → 4 → 2 → 1 → 2 → 3 → 2 → 4. 
  5. (3, 4): 3 → 2 → 1 → 2 → 4. 
  6. (3, 7): 3 → 2 → 1 → 2 → 4 → 5 → 4 → 2 → 3 → 7. 