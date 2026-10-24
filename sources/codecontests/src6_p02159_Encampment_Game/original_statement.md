Problem

There is a tree with $ N $ vertices. Each vertex is assigned a number from 1 to $ N $.
Gacho and Kawabayashi decided to play a camp game using this tree.
The game starts with Gacho and Kawabayashi at different vertices.
Gacho repeatedly moves the vertices alternately, and the one who can not move first is the loser.

Moving method:
When you are at vertex $ x $, you move to one of the vertices that is directly connected to vertex $ x $ by an edge and that no one has visited yet.
If no such vertex exists, it cannot be moved.

Let Gacho's first vertex be vertex $ A $, and Kawabayashi's first vertex be vertex $ B $.
Find the number of combinations of vertices $ A $ and vertices $ B $ that Gacho will win when Gacho and Kawabayashi do their best to each other.

Constraints

The input satisfies the following conditions.

* $ 2 \ leq N \ leq 2000 $
* $ 1 \ leq u_i, v_i \ leq N $
* The graph given is a tree

Input

The input is given in the following format.


$ N $
$ u_1 $ $ v_1 $
$ u_2 $ $ v_2 $
$ \ vdots $
$ u_ {N-1} $ $ v_ {N-1} $


All inputs are given as integers.
The number of vertices $ N $ is given in the first line.
The $ N-1 $ line that continues from the second line is given information about the edges of the tree, separated by blanks.
The input on the $ 1 + i $ line indicates that the vertex $ u_i $ and the vertex $ v_i $ are connected by an edge.

Output

Output the number of combinations of vertex $ A $ and vertex $ B $ that Gacho wins on one line.

Examples

Input

2
1 2


Output

0


Input

6
1 2
2 3
3 4
4 5
5 6


Output

12


Input

5
1 2
1 3
3 4
3 5


Output

12


Input

20
14 1
2 1
18 14
10 1
12 10
5 1
17 5
7 1
11 17
4 1
19 2
15 1
3 19
8 15
9 8
20 8
6 1
16 15
13 7


Output

243