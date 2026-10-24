<image>

For given three points p0, p1, p2, print


COUNTER_CLOCKWISE


if p0, p1, p2 make a counterclockwise turn (1),


CLOCKWISE


if p0, p1, p2 make a clockwise turn (2),


ONLINE_BACK


if p2 is on a line p2, p0, p1 in this order (3),


ONLINE_FRONT


if p2 is on a line p0, p1, p2 in this order (4),


ON_SEGMENT


if p2 is on a segment p0p1 (5).

Constraints

* 1 ≤ q ≤ 1000
* -10000 ≤ xi, yi ≤ 10000
* p0 and p1 are not identical.

Input


xp0 yp0 xp1 yp1
q
xp20 yp20
xp21 yp21
...
xp2q-1 yp2q-1


In the first line, integer coordinates of p0 and p1 are given. Then, q queries are given for integer coordinates of p2.

Output

For each query, print the above mentioned status.

Examples

Input

0 0 2 0
2
-1 1
-1 -1


Output

COUNTER_CLOCKWISE
CLOCKWISE


Input

0 0 2 0
3
-1 0
0 0
3 0


Output

ONLINE_BACK
ON_SEGMENT
ONLINE_FRONT