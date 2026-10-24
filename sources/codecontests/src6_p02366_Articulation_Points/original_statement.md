Find articulation points of a given undirected graph G(V, E).

A vertex in an undirected graph is an articulation point (or cut vertex) iff removing it disconnects the graph.

Constraints

* 1 ≤ |V| ≤ 100,000
* 0 ≤ |E| ≤ 100,000
* The graph is connected
* There are no parallel edges
* There are no self-loops

Input


|V| |E|
s0 t0
s1 t1
:
s|E|-1 t|E|-1


, where |V| is the number of vertices and |E| is the number of edges in the graph. The graph vertices are named with the numbers 0, 1,..., |V|-1 respectively.

si and ti represent source and target verticess of i-th edge (undirected).

Output

A list of articulation points of the graph G ordered by name.

Examples

Input

4 4
0 1
0 2
1 2
2 3


Output

2


Input

5 4
0 1
1 2
2 3
3 4


Output

1
2
3