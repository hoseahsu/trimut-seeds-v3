You are given an undirected graph with N vertices and M edges. Here, N-1≤M≤N holds and the graph is connected. There are no self-loops or multiple edges in this graph.

The vertices are numbered 1 through N, and the edges are numbered 1 through M. Edge i connects vertices a_i and b_i.

The color of each vertex can be either white or black. Initially, all the vertices are white. Snuke is trying to turn all the vertices black by performing the following operation some number of times:

* Select a pair of adjacent vertices with the same color, and invert the colors of those vertices. That is, if the vertices are both white, then turn them black, and vice versa.



Determine if it is possible to turn all the vertices black. If the answer is positive, find the minimum number of times the operation needs to be performed in order to achieve the objective.

Constraints

* 2≤N≤10^5
* N-1≤M≤N
* 1≤a_i,b_i≤N
* There are no self-loops or multiple edges in the given graph.
* The given graph is connected.

Input

The input is given from Standard Input in the following format:


N M
a_1 b_1
a_2 b_2
:
a_M b_M


Output

If it is possible to turn all the vertices black, print the minimum number of times the operation needs to be performed in order to achieve the objective. Otherwise, print `-1` instead.

Examples

Input

6 5
1 2
1 3
1 4
2 5
2 6


Output

5


Input

3 2
1 2
2 3


Output

-1


Input

4 4
1 2
2 3
3 4
4 1


Output

2


Input

6 6
1 2
2 3
3 1
1 4
1 5
1 6


Output

7