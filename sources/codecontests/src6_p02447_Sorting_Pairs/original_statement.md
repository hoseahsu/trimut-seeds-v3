Write a program which print coordinates $(x_i, y_i)$ of given $n$ points on the plane by the following criteria.

1. first by $x$-coordinate
2. in case of a tie, by $y$-coordinate

Constraints

* $1 \leq n \leq 100,000$
* $-1,000,000,000 \leq x_i, y_i \leq 1,000,000,000$

Input

The input is given in the following format.


$n$
$x_0 \; y_0$
$x_1 \; y_1$
:
$x_{n-1} \; y_{n-1}$


In the first line, the number of points $n$ is given. In the following $n$ lines, coordinates of each point are given.

Output

Print coordinate of given points in order.

Example

Input

5
4 7
5 5
2 3
6 8
2 1


Output

2 1
2 3
4 7
5 5
6 8