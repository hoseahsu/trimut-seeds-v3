Problem

In this problem, a straight line passing through a certain point X and a certain point Y in the three-dimensional space is written as a straight line XY.

A cone and a point P inside the cone are given in three-dimensional space. Let point Q be the intersection of a straight line passing through point P and perpendicular to the bottom of the cone and the bottom of the cone. At this time, the center of the bottom surface of the cone is O, and the intersection of the straight line OQ and the circumference of the bottom surface of the cone is point A and point B from the side closer to point Q (however, point O and point Q are the same point). In the case of, let points A and B be the intersections of any straight line passing through point O and the circumference of the bottom of the cone.) Also, in a plane that includes the bottom surface of the cone, let points C and D be the intersections of the straight line that passes through point O and intersects the straight line AB perpendicularly with the circumference of the bottom surface of the cone (however, points C and D). Can be replaced).


The figure below is a view of the bottom surface of the cone as seen from the direction of the apex of the cone.

View of the bottom of the cone as seen from the apex of the cone


Let the intersection of the straight line AP and the cone of the straight line BP (in the case of the straight line AP, the intersection that is not the point A. The same applies to the straight line BP) be the point A'and the point B', and pass through the points A'and B'. Cut the cone at the plane S parallel to the straight line CD. At this time, output the volume of the figure including the vertices after cutting and the volume of the other figure separated by blanks.

Input

X coordinate y coordinate z coordinate of the apex of the cone
X coordinate y coordinate z coordinate of the center of the base of the cone Radius of the base of the cone
X coordinate y coordinate z coordinate of point P

Each value on each row is given separated by spaces.

Constraint

All input values ​​are integers, the absolute value of which is less than or equal to 1000.
The height of the cone and the radius of its base are greater than or equal to 1, and the distance between point P and the cone is greater than or equal to 10-5.

Output

Output the volume of the figure including the vertices after cutting and the volume of the other figure separated by blanks.
However, it must not contain an error greater than 10-5.

Sample Input 1


0 0 10
0 0 0 4
0 0 1


Sample Output 1


91.769438 75.782170


Sample Input 2


0 0 10
0 0 0 4
1 1 1


Sample Output 2


84.050413 83.501195


Sample Input 3


0 0 0
8 9 10 5
1 1 1


Sample Output 3


0.071663 409.709196






Example

Input

0 0 10
0 0 0 4
0 0 1


Output

91.769438 75.782170