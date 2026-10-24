ButCoder Inc. is a startup company whose main business is the development and operation of the programming competition site "ButCoder".

There are N members of the company including the president, and each member except the president has exactly one direct boss. Each member has a unique ID number from 1 to N, and the member with the ID i is called Member i. The president is Member 1, and the direct boss of Member i (2 ≤ i ≤ N) is Member b_i (1 ≤ b_i < i).

All the members in ButCoder have gathered in the great hall in the main office to take a group photo. The hall is very large, and all N people can stand in one line. However, they have been unable to decide the order in which they stand. For some reason, all of them except the president want to avoid standing next to their direct bosses.

How many ways are there for them to stand in a line that satisfy their desires? Find the count modulo 10^9+7.

Constraints

* 2 ≤ N ≤ 2000
* 1 ≤ b_i < i (2 ≤ i ≤ N)

Input

Input is given from Standard Input in the following format:


N
b_2
b_3
:
b_N


Output

Print the number of ways for the N members to stand in a line, such that no member except the president is next to his/her direct boss, modulo 10^9+7.

Examples

Input

4
1
2
3


Output

2


Input

3
1
2


Output

0


Input

5
1
1
3
3


Output

8


Input

15
1
2
3
1
4
2
7
1
8
2
8
1
8
2


Output

97193524