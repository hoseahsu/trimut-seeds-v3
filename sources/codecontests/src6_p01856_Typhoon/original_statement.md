Problem statement

There is a town with a size of H in the north-south direction and W in the east-west direction. In the town, square plots with a side length of 1 are maintained without gaps, and one house is built in each plot.

A typhoon broke out over a section of the town, causing damage and then changing to an extratropical cyclone over a section. No damage is done after the change. As shown in the figure below, a typhoon is a square with a height of 3 and a width of 3, and the square with a star is called the center. The typhoon moves to the vicinity of 8 in units of sections. In other words, the center of the typhoon moves with the whole so that it moves to the section that shares the sides or vertices (including the current section). However, the typhoon does not protrude outside the town, and the center of the typhoon is the 0th and H-1st sections from the north and the 0th and W-1st sections from the west, as shown in the shaded area in the figure below. Move so that it does not pass.

<image>

Once a typhoon hits the sky, the degree of damage to the house changes as follows.

> No damage → Partially damaged → Half destroyed → Completely destroyed → No trace

Fortunately, however, there seems to be no house that has become a trace pear. Since the damage situation of each house is given, find the point where the typhoon occurred and the point where it changed to an extratropical cyclone. However, if the generated section is s_ith from the north, s_jth from the west, and the section changed to an extratropical cyclone is t_ith from the north and t_jth from the west, the two points are 10000 t_i + t_j ≤ 10000 s_i + s_j. Determined to meet.

input


H \ W
D_ {11} \… \ D_ {1W}
D_ {21} \… \ D_ {2W}
...
D_ {H1} \… \ D_ {HW}


D_ {ij} is an integer that expresses the degree of damage to the i-th house from the north and the j-th house from the west as follows.

* 0: No damage
* 1: Partially damaged
* 2: Half destroyed
* 3: Completely destroyed



Constraint

* An integer
* Input is given only if the answer is uniquely determined
* 3 ≤ H, W ≤ 500
* 0 ≤ D_ {ij} ≤ 3



output

Output the answer in one line as follows.


s_i \ s_j \ t_i \ t_j


sample

Sample input 1


7 5
0 0 0 0 0
0 1 1 1 0
0 2 2 2 0
0 3 3 3 0
0 2 2 2 0
0 1 1 1 0
0 0 0 0 0


Sample output 1


4 2 2 2


Sample input 2


6 6
0 0 0 1 1 1
0 0 0 2 2 2
0 0 1 3 3 2
1 2 3 3 2 1
1 2 3 2 1 0
1 2 2 1 0 0


Sample output 2


4 1 1 4


Sample input 3


4 4
2 2 2 0
2 2 2 0
2 2 2 0
0 0 0 0


Sample output 3


1 1 1 1






Example

Input

7 5
0 0 0 0 0
0 1 1 1 0
0 2 2 2 0
0 3 3 3 0
0 2 2 2 0
0 1 1 1 0
0 0 0 0 0


Output

4 2 2 2