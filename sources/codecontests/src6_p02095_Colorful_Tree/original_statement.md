H: Colorful Tree

Story

Yamiuchi (assassination) is a traditional event that is held annually in JAG summer camp. Every team displays a decorated tree in the dark and all teams' trees are compared from the point of view of their colorfulness. In this competition, it is allowed to cut the other teams’ tree to reduce its colorfulness. Despite a team would get a penalty if it were discovered that the team cuts the tree of another team, many teams do this obstruction.

You decided to compete in Yamiuchi and write a program that maximizes the colorfulness of your team’s tree. The program has to calculate maximum scores for all subtrees in case the other teams cut your tree.

Problem Statement

You are given a rooted tree G with N vertices indexed with 1 through N. The root is vertex 1. There are K kinds of colors indexed with 1 through K. You can paint vertex i with either color c_i or d_i. Note that c_i = d_i may hold, and if so you have to paint vertex i with c_i (=d_i).

Let the colorfulness of tree T be the number of different colors in T. Your task is to write a program that calculates maximum colorfulness for all rooted subtrees. Note that coloring for each rooted subtree is done independently, so previous coloring does not affect to other coloring.

Input


N K
u_1 v_1
:
u_{N-1} v_{N-1}
c_1 d_1
:
c_N d_N


The first line contains two integers N and K in this order.

The following N-1 lines provide information about the edges of G. The i-th line of them contains two integers u_i and v_i, meaning these two vertices are connected with an edge.

The following N lines provide information about color constraints. The i-th line of them contains two integers c_i and d_i explained above.

Constraints

* 1 \leq N \leq 10^5
* 1 \leq K \leq 2\times 10^5
* 1 \leq u_i , v_i \leq N
* 1 \leq c_i , d_i \leq K
* The input graph is a tree.
* All inputs are integers.



Output

Output N lines.

The i-th line of them contains the maximum colorfulness of the rooted subtree of G whose root is i.

Sample Input 1


2 10
1 2
1 9
8 7


Output for Sample Input 1


2
1


Sample Input 2


3 2
1 2
1 3
1 2
1 1
1 2


Output for Sample Input 2


2
1
1


Note that two color options of a vertex can be the same.

Sample Input 3


5 100000
4 3
3 5
1 3
2 1
3 2
1 3
2 1
4 2
1 4


Output for Sample Input 3


4
1
3
1
1






Example

Input

2 10
1 2
1 9
8 7


Output

2
1