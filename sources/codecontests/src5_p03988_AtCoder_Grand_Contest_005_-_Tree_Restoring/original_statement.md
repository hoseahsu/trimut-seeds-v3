Aoki loves numerical sequences and trees.

One day, Takahashi gave him an integer sequence of length N, a_1, a_2, ..., a_N, which made him want to construct a tree.

Aoki wants to construct a tree with N vertices numbered 1 through N, such that for each i = 1,2,...,N, the distance between vertex i and the farthest vertex from it is a_i, assuming that the length of each edge is 1.

Determine whether such a tree exists.

Constraints

* 2 ≦ N ≦ 100
* 1 ≦ a_i ≦ N-1

Input

The input is given from Standard Input in the following format:


N
a_1 a_2 ... a_N


Output

If there exists a tree that satisfies the condition, print `Possible`. Otherwise, print `Impossible`.

Examples

Input

5
3 2 2 3 3


Output

Possible


Input

3
1 1 2


Output

Impossible


Input

10
1 2 2 2 2 2 2 2 2 2


Output

Possible


Input

10
1 1 2 2 2 2 2 2 2 2


Output

Impossible


Input

6
1 1 1 1 1 5


Output

Impossible


Input

5
4 3 2 3 4


Output

Possible