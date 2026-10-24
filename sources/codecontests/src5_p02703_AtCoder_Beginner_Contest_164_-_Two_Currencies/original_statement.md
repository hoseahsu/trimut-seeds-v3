There are N cities numbered 1 to N, connected by M railroads.

You are now at City 1, with 10^{100} gold coins and S silver coins in your pocket.

The i-th railroad connects City U_i and City V_i bidirectionally, and a one-way trip costs A_i silver coins and takes B_i minutes. You cannot use gold coins to pay the fare.

There is an exchange counter in each city. At the exchange counter in City i, you can get C_i silver coins for 1 gold coin. The transaction takes D_i minutes for each gold coin you give. You can exchange any number of gold coins at each exchange counter.

For each t=2, ..., N, find the minimum time needed to travel from City 1 to City t. You can ignore the time spent waiting for trains.

Constraints

* 2 \leq N \leq 50
* N-1 \leq M \leq 100
* 0 \leq S \leq 10^9
* 1 \leq A_i \leq 50
* 1 \leq B_i,C_i,D_i \leq 10^9
* 1 \leq U_i < V_i \leq N
* There is no pair i, j(i \neq j) such that (U_i,V_i)=(U_j,V_j).
* Each city t=2,...,N can be reached from City 1 with some number of railroads.
* All values in input are integers.

Input

Input is given from Standard Input in the following format:


N M S
U_1 V_1 A_1 B_1
:
U_M V_M A_M B_M
C_1 D_1
:
C_N D_N


Output

For each t=2, ..., N in this order, print a line containing the minimum time needed to travel from City 1 to City t.

Examples

Input

3 2 1
1 2 1 2
1 3 2 4
1 11
1 2
2 5


Output

2
14


Input

4 4 1
1 2 1 5
1 3 4 4
2 4 2 2
3 4 1 1
3 1
3 1
5 2
6 4


Output

5
5
7


Input

6 5 1
1 2 1 1
1 3 2 1
2 4 5 1
3 5 11 1
1 6 50 1
1 10000
1 3000
1 700
1 100
1 1
100 1


Output

1
9003
14606
16510
16576


Input

4 6 1000000000
1 2 50 1
1 3 50 5
1 4 50 7
2 3 50 2
2 4 50 4
3 4 50 3
10 2
4 4
5 5
7 7


Output

1
3
5


Input

2 1 0
1 2 1 1
1 1000000000
1 1


Output

1000000001