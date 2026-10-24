Background

The kindergarten attached to the University of Aizu is a kindergarten where children who love programming gather. Yu, one of the kindergarten children, loves rectangles as much as programming. Yu-kun decided to write a program to calculate the maximum score that can be obtained, thinking of a new play to get points using three rectangles.

Problem

Given the rectangles A and B of the H × W cells and the rectangle C of the h × w cells. (H and W represent the number of vertical and horizontal squares of rectangles A and B, respectively, and h and w represent the number of vertical and horizontal squares of rectangle C, respectively.)

As shown in Fig. 1, an integer is written in each cell of A, and each cell of B is colored white or black. Each cell in C is also colored white or black.


Figure 1
Figure 1


If there is a rectangle in B that has exactly the same pattern as C, you can get the sum of the integers written in the corresponding squares in A as a score.

For example, when the rectangles A, B, and C as shown in Fig. 1 are used, the same pattern as C is included in B as shown by the red line in Fig. 2, so 193 points can be obtained from that location.


Figure 2
Figure 2


If there is one or more rectangles in B that have exactly the same pattern as C, how many points can be obtained in such rectangles?

However, if there is no rectangle in B that has the same pattern as C, output "NA" (excluding "). Also, the rectangle cannot be rotated or inverted.

Constraints

The input satisfies the following conditions.

* All inputs are integers
* 1 ≤ H, W ≤ 50
* 1 ≤ h ≤ H
* 1 ≤ w ≤ W
* -100 ≤ a (i, j) ≤ 100
* b (i, j), c (i, j) is 0 or 1

Input

The input format is as follows.


H W
a (1,1) a (1,2) ... a (1, W)
a (2,1) a (2,2) ... a (2, W)
::
a (H, 1) a (H, 2) ... a (H, W)
b (1,1) b (1,2) ... b (1, W)
b (2,1) b (2,2) ... b (2, W)
::
b (H, 1) b (H, 2) ... b (H, W)
h w
c (1,1) c (1,2) ... c (1, w)
c (2,1) c (2,2) ... c (2, w)
::
c (h, 1) c (h, 2) ... c (h, w)


a (i, j) is the integer written in the square (i, j) of the rectangle A, b (i, j) is the color of the square (i, j) of the rectangle B, and c (i, j) Represents the color of the square (i, j) of the rectangle C. As for the color of the square, 0 is white and 1 is black.

Output

If there is a place in rectangle B that has exactly the same pattern as rectangle C, output the one with the highest score among such places.

If no such location exists, print “NA” (excluding “).

Examples

Input

4 4
10 2 -1 6
8 1 -100 41
22 47 32 11
-41 99 12 -8
1 0 0 1
0 0 1 0
0 1 0 1
0 0 1 0
2 3
1 0 1
0 1 0


Output

193


Input

3 3
5 1 3
2 5 9
0 1 5
1 0 0
0 1 1
0 1 1
1 1
1


Output

9


Input

3 4
4 1 9 1
9 1 -1 3
2 -4 1 10
1 1 0 1
0 1 1 1
1 1 0 0
1 4
1 1 1 1


Output

NA