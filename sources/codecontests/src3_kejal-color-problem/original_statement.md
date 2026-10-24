Kejal have N points, with coordinates (1, 0), (2, 0), ..., (N, 0). Every point has a color, point with coordinate (i, 0) has color C[i].

Kejal have painted arcs between every pair of points with same color. Formally Kejal painted arc between points (i, 0) and (j, 0) if C[i] = C[j] and i != j, such arc has color C[i]. All the arcs are painted such way that they will reside along the positive quadrant.

Now Kejal wants to know how many pairs of arc with different color intersect?

INPUT

First line contain integer N. Next line contain integers C[1], C[2], ..., C[N].

OUTPUT

In single line output answer modulo 1000000007 (10^9 + 7).

CONSTRAINTS
1 ≤ N ≤ 100000
1 ≤ C[i] ≤ 100000

SAMPLE INPUT
6
1 2 1 2 1 2

SAMPLE OUTPUT
6