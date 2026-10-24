There are N points on an XY plane. In one turn, you can select a set of collinear points on the plane and remove them. Your goal is to remove all the points in the least number of turns. Given the coordinates of the points, calculate two things:

The minimum number of turns (T) needed to remove all the points.
The number of ways to to remove them in T turns. Two ways are considered different if any point is removed in a different turn.

Input Format

The first line contains the number of test cases T. T test cases follow. Each test case contains N on the first line, followed by N lines giving the coordinates of the points.

Output Format

Output T lines, one for each test case, containing the least number of turns needed to remove all points and the number of ways to do so. As the answers can be large, output them modulo 1000000007.

Constraints

1 ≤ T ≤ 50
1 ≤ N ≤ 16
0 ≤ xi,yi ≤ 100
No two points will have the same coordinates.

SAMPLE INPUT
2
3
0 0
0 1
1 0
4
3 4
3 5
3 6
5 5

SAMPLE OUTPUT
2 6
2 8

Explanation

For the 1st input, Let the points be labelled p1,p2,p3. These are the ways to remove them (first turn's points, followed by second turn's points):

a. 1) p1,p2 2) p3
b. 1) p1,p3 2) p2
c. 1) p2,p3 2) p1
d. 1) p3 2) p1,p2
e. 1) p2 2) p1,p3
f. 1) p1 2) p3,p2