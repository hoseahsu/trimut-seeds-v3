Problem statement

There is a village called Biwako, which consists of $ N $ islets floating on the lake. Biwako Village has a simple bridge with $ N-1 $ books. The islands are numbered from $ 0 $ to $ N-1 $, and the bridges are numbered from $ 0 $ to $ N-2 $. The $ i $ bridge directly connects the $ i + 1 $ island and the $ p_i $ island, and is $ w_i $ in length. Villagers can move between islands through several bridges.

At the suggestion of a villager, a relay tournament will be held in Biwako Village. However, since there is no closed road in Biwako Village and trucks cannot be prepared, I decided to make a closed road by replacing the existing bridge by only $ 1 $. Find the length of the cycle that can be prepared by this operation and that has the maximum length.

Constraint

$ 2 \ leq N \ leq 100000 $
$ 0 \ leq p_i \ leq N-1 $
$ 1 \ leq w_i \ leq 1000 $
All integers
Reachable between all islands

sample

The illustration of each sample is as follows.

<image>

Sample input 1


Five
0 1
0 2
0 3
0 4


Sample output 1


9


Sample input 2


12
0 6
1 1
0 3
3 4
0 2
5 1
6 1
0 2
8 1
9 1
10 2


Sample output 2


19


Sample input 3


2
0 1


Sample output 3


1




input

$ N $
$ p_0 \ w_0 $
$ \ vdots $
$ p_ {n-2} \ w_ {n-2} $

output

Print the answer on the $ 1 $ line.

Example

Input

5
0 1
0 2
0 3
0 4


Output

9