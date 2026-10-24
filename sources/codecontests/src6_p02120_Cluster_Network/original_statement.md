Problem

A large-scale cluster † type supercomputer (commonly known as "SAKURA") cluster at Maze University consists of $ N $ computers (nodes) and $ M $ physical communication channels that can communicate with each other. .. In addition, each node is assigned an identification number from 1 to $ N $.

This time, the use of SAKURA will be approved not only by university personnel but also by companies in the prefecture. Along with that, it is necessary to inspect each node that composes SAKURA. However, since the usage schedule of SAKURA is filled up to several months ahead, the entire system cannot be stopped even during the inspection. Therefore, inspect the nodes one by one a day.

The inspection takes place over $ N $ days and inspects the node $ i $ on the $ i $ day. At this time, the node to be inspected and the communication path directly connected to that node are separated from the SAKURA cluster. As a result, the entire cluster of SAKURA is divided into one or more clusters, and one of them is operated in place of SAKURA. Naturally, the node under inspection cannot be operated.

When divided into multiple clusters, only the cluster with the highest "overall performance value" is operated. The "total performance value" of each cluster is the sum of the "single performance values" set for each node that composes it.

Since the number of nodes that make up SAKURA, the number of communication channels, and the "single performance value" set for each node are given, the "total performance value" of the cluster operated during the inspection on the $ i $ day is output. Let's do it.

†: A cluster is a system that combines one or more computers into a single unit. Here, it is a set of nodes connected by a physical communication path.

Constraints

The input satisfies the following conditions.

* $ 2 \ leq N \ leq 10 ^ 5 $
* $ N-1 \ leq M \ leq min (\ frac {N \ times (N-1)} {2}, 10 ^ 5) $
* $ 1 \ leq w_i \ leq 10 ^ 6 $
* $ 1 \ leq u_i, v_i \ leq N, u_i \ ne v_i $
* $ (u_i, v_i) \ ne (u_j, v_j), (u_i, v_i) \ ne (v_j, u_j), i \ ne j $
* All inputs are integers

Input

The input is given in the following format.

$ N $ $ M $
$ w_1 $ $ w_2 $ ... $ w_N $
$ u_1 $ $ v_1 $
$ u_2 $ $ v_2 $
...
$ u_M $ $ v_M $


The number of nodes that make up the cluster $ N $ and the number of communication channels $ M $ are given on the first line, separated by blanks.
In the second line, $ N $ integers representing the "single performance value" of each node are given, separated by blanks. The $ i $ th integer $ w_i $ represents the "single performance value" of the node $ i $.
The $ M $ lines from the third line are given the identification numbers of the two nodes that each channel connects, separated by blanks. The input on the 2 + $ i $ line indicates that the channel connects the node $ u_i $ and the node $ v_i $ to each other.

Output

The output consists of $ N $ lines.
In the $ i $ line, the "total performance value" of the cluster operated on the $ i $ day is output.

Examples

Input

9 10
1 2 3 4 5 6 7 8 9
1 2
2 3
2 4
3 4
4 5
4 6
2 7
7 8
7 9
9 1


Output

44
25
42
30
40
39
30
37
36


Input

16 19
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 2
2 3
3 4
3 5
1 6
6 7
6 8
7 8
8 9
8 10
10 11
11 12
12 10
1 13
13 14
14 15
15 13
14 16
15 16


Output

63
122
124
132
131
73
129
86
127
103
125
124
78
122
121
120


Input

2 1
1 2
1 2


Output

2
1