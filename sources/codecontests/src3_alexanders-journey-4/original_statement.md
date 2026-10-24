There are N (labelled 1 to N) kingdoms in a country. Our king Alexander is living in the kingdom S. We are given R distances, these distances are between two kingdoms and the distance between any two kingdom may or may not be unique.

Now Alexander wants to visit each kingdom in minimum distance possible starting from his kingdom S.

If a kingdom is unreachable the distance is assumed as -1.

INPUT:::

The first line denotes T, the number of test cases.

First line of each test case has two integers, denoting the no of kingdom "N" and the next number denotes the no of distance given between two different kingdoms "R".

The next "R" line contains three integers x,y,d, the first two numbers denoting kingdom number and the next integer denotes the distance between them.

If the distance between two kingdom say a and b is given as x then this distance will remain same if the Alexander travels from a to b or from b to a.

The last line of test case denotes the kingdom in which Alexander is living.

Note::: If there are many distances given between the same two kingdoms then it is considered that Alexander has many different ways to travel between these two kingdoms.

Output:::

For each test case print a single line containing N-1 space separated integers denoting the shortest distance of N-1 kingdoms from Alexander's Kingdom.

For unreachable kingdoms print "-1".

Constraints:::
1≤T≤10,
2≤N≤3000, 
1≤R≤N×(N−1))2,
1≤x,y,S≤N,
1≤d≤350

SAMPLE INPUT
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

SAMPLE OUTPUT
24 3 15