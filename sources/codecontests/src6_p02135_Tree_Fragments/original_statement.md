Problem

Ai-chan has a tree $ T $ consisting of $ N $ vertices and $ N-1 $ edges. Each vertex has a number from $ 1 $ to $ N $ and a positive integer weight.

Answer the following $ Q $ queries in order.

* $ 1 \ le a_i, b_i \ le N $ ($ a_i \ ne b_i $) is given, so you can remove the vertices on the $ a_i $-$ b_i $ path of $ T $ and the edges that connect to them. Among the connected components, the weight of the connected component having the maximum weight is output. If there is no such connected component, 0 is output.



However, the weight of the connected component is defined by the sum of the weights of the vertices included in the connected component.

Ouput

For each query, 0 or the weight of the connected component with the maximum weight is output on one line.

Constraints

The input satisfies the following conditions.

* $ 2 \ le N \ le 10 ^ 5 $
* $ 1 \ le Q \ le 10 ^ 5 $
* $ 1 \ le w_i \ le 10 ^ 8 $ ($ 1 \ le i \ le N $)
* $ 1 \ le u_i, v_i \ le N $ ($ 1 \ le i \ le N-1 $)
* $ u_i \ ne v_i $
* $ i \ ne j $ is $ (u_i, v_i) \ ne (u_j, v_j) $ and $ (u_i, v_i) \ ne (v_j, u_j) $
* $ 1 \ le a_i, b_i \ le N $ ($ 1 \ le i \ le Q $)
* $ a_i \ ne b_i $

Input

The input is given in the following format.


$ N $
$ w_1 $ $ w_2 $ ... $ w_N $
$ u_1 $ $ v_1 $
$ u_2 $ $ v_2 $
...
$ u_ {N-1} $ $ v_ {N-1} $
$ Q $
$ a_1 $ $ b_1 $
$ a_2 $ $ b_2 $
...
$ a_Q $ $ b_Q $


All inputs are given as integers.

The number of vertices $ N $ of $ T $ is given in the first line.
On the second line, the weight $ w_i $ of the vertex $ i $ ($ 1 \ le i \ le N $) is given, separated by blanks.
The end points $ u_i and v_i $ of the edge $ _i $ ($ 1 \ le i \ le N-1 $) are given in the third and subsequent lines of $ N $ -1 separated by blanks.
The number of queries $ Q $ is given on the second line of $ N $ +.
$ A_i, b_i $ representing the query $ _i $ ($ 1 \ le i \ le Q $) are given in the $ Q $ line after the $ N $ + 3rd line, separated by blanks.

Examples

Input

10
1 2 3 4 5 6 7 8 9 10
1 2
2 3
3 4
3 5
2 6
6 7
2 8
8 9
8 10
3
3 8
7 1
7 10


Output

13
27
12


Input

5
1 2 3 4 5
1 2
2 3
3 4
4 5
3
1 2
1 5
2 4


Output

12
0
5


Input

15
3 8 4 2 6 5 1 2 10 3 4 2 6 1 1
1 2
2 3
3 4
3 5
2 6
6 7
6 8
1 9
9 10
10 11
10 12
9 13
13 14
13 15
5
1 1
2 7
6 10
1 15
3 4


Output

28
30
12
28
46