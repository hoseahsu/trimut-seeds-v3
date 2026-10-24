Hit n nails one by one at the coordinates P1 (x1, y1), P2 (x2, y2), P3 (x3, y3), ..., Pn (xn, yn) on the flat plate, and put them on the rubber band ring. Surround it with a single rubber band so that all the nails fit inside. At this time, the rubber bands must not intersect.

Create a program that reads the coordinates of the nails and outputs the number of nails that are not in contact with the rubber band when the nail is surrounded by the rubber band as described above. The rubber band shall expand and contract sufficiently. You may not hit more than one nail at the same coordinates. In addition, it is assumed that the nails covered with rubber bands are connected by a straight line, and that no more than three nails are lined up on the straight line. For example, there can be no input as shown in Figure 1. As shown in Figure 2, it is possible for nails without rubber bands to line up in a straight line.

<image> | <image>
--- | ---
Figure 1 | Figure 2



However, each coordinate value is a real number between -1000.0 and 1000.0. Also, n is an integer between 3 and 100.

Hint

Below is a diagram for the second sample input.

<image>
---



Input

Given multiple datasets. Each dataset is given in the following format:


n
x1, y1
x2, y2
...
...
xn, yn


When n is 0, it indicates the end of input. The number of datasets does not exceed 50.

Output

For each dataset, output the number of nails that are not in contact with the rubber. For example, if there is an input representing the four nails shown in Fig. 3, it will be surrounded as shown in Fig. 4, so the number of nails that are not in contact with the rubber band is one.

<image> | <image>
--- | ---
Figure 3 | Figure 4


Example

Input

4
1.0,0.0
0.0,1.0
2.0,1.0
1.0,2.0
9
-509.94,892.63
567.62,639.99
-859.32,-64.84
-445.99,383.69
667.54,430.49
551.12,828.21
-940.2,-877.2
-361.62,-970
-125.42,-178.48
0


Output

0
3