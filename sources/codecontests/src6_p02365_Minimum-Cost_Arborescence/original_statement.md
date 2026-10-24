Find the sum of the weights of edges of the Minimum-Cost Arborescence with the root r for a given weighted directed graph G = (V, E).

Constraints

* 1 ≤ |V| ≤ 100
* 0 ≤ |E| ≤ 1,000
* 0 ≤ wi ≤ 10,000
* G has arborescence(s) with the root r

Input


|V| |E| r
s0 t0 w0
s1 t1 w1
:
s|E|-1 t|E|-1 w|E|-1


, where |V| is the number of vertices and |E| is the number of edges in the graph. The graph vertices are named with the numbers 0, 1,..., |V|-1 respectively. r is the root of the Minimum-Cost Arborescence.

si and ti represent source and target verticess of i-th directed edge. wi represents the weight of the i-th directed edge.

Output

Print the sum of the weights the Minimum-Cost Arborescence.

Examples

Input

4 6 0
0 1 3
0 2 2
2 0 1
2 3 1
3 0 1
3 1 5


Output

6


Input

6 10 0
0 2 7
0 1 1
0 3 5
1 4 9
2 1 6
1 3 2
3 4 3
4 2 2
2 5 8
3 5 3


Output

11