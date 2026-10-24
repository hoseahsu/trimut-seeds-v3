Problem

There are n vertices that are not connected to any of the vertices.
An undirected side is stretched between each vertex.
Find out how many sides can be stretched when the diameter is set to d.
The diameter represents the largest of the shortest distances between two vertices.
Here, the shortest distance is the minimum value of the number of sides required to move between vertices.
Multiple edges and self-loops are not allowed.

Constraints

* 2 ≤ n ≤ 109
* 1 ≤ d ≤ n−1

Input


n d


Two integers n and d are given on one line, separated by blanks.

Output

Output the maximum number of sides that can be stretched on one line.

Examples

Input

4 3


Output

3


Input

5 1


Output

10


Input

4 2


Output

5