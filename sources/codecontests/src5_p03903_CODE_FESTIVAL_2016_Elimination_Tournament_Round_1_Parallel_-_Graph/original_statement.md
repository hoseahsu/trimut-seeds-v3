Takahashi found an undirected connected graph with N vertices and M edges. The vertices are numbered 1 through N. The i-th edge connects vertices a_i and b_i, and has a weight of c_i.

He will play Q rounds of a game using this graph. In the i-th round, two vertices S_i and T_i are specified, and he will choose a subset of the edges such that any vertex can be reached from at least one of the vertices S_i or T_i by traversing chosen edges.

For each round, find the minimum possible total weight of the edges chosen by Takahashi.

Constraints

* 1 ≦ N ≦ 4,000
* 1 ≦ M ≦ 400,000
* 1 ≦ Q ≦ 100,000
* 1 ≦ a_i,b_i,S_i,T_i ≦ N
* 1 ≦ c_i ≦ 10^{9}
* a_i \neq b_i
* S_i \neq T_i
* The given graph is connected.

Input

The input is given from Standard Input in the following format:


N M
a_1 b_1 c_1
a_2 b_2 c_2
:
a_M b_M c_M
Q
S_1 T_1
S_2 T_2
:
S_Q T_Q


Output

Print Q lines. The i-th line should contain the minimum possible total weight of the edges chosen by Takahashi.

Examples

Input

4 3
1 2 3
2 3 4
3 4 5
2
2 3
1 4


Output

8
7


Input

4 6
1 3 5
4 1 10
2 4 6
3 2 2
3 4 5
2 1 3
1
2 3


Output

8