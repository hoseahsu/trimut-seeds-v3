N hotels are located on a straight line. The coordinate of the i-th hotel (1 \leq i \leq N) is x_i.

Tak the traveler has the following two personal principles:

* He never travels a distance of more than L in a single day.
* He never sleeps in the open. That is, he must stay at a hotel at the end of a day.



You are given Q queries. The j-th (1 \leq j \leq Q) query is described by two distinct integers a_j and b_j. For each query, find the minimum number of days that Tak needs to travel from the a_j-th hotel to the b_j-th hotel following his principles. It is guaranteed that he can always travel from the a_j-th hotel to the b_j-th hotel, in any given input.

Constraints

* 2 \leq N \leq 10^5
* 1 \leq L \leq 10^9
* 1 \leq Q \leq 10^5
* 1 \leq x_i < x_2 < ... < x_N \leq 10^9
* x_{i+1} - x_i \leq L
* 1 \leq a_j,b_j \leq N
* a_j \neq b_j
* N,\,L,\,Q,\,x_i,\,a_j,\,b_j are integers.

Input

The input is given from Standard Input in the following format:


N
x_1 x_2 ... x_N
L
Q
a_1 b_1
a_2 b_2
:
a_Q b_Q


Output

Print Q lines. The j-th line (1 \leq j \leq Q) should contain the minimum number of days that Tak needs to travel from the a_j-th hotel to the b_j-th hotel.

Example

Input

9
1 3 6 13 15 18 19 29 31
10
4
1 8
7 3
6 7
8 5


Output

4
2
1
2