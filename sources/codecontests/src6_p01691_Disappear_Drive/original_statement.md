E --Disappear Drive

Story

The person in D likes basketball, but he likes shooting, so other techniques are crazy. I'm not particularly good at dribbling, and when I enter the opponent's defensive range, I always get the ball stolen. So I decided to come up with a deadly dribble that would surely pull out any opponent. After some effort, he finally completed the disappearing drive, "Disapia Drive".

This Apia Drive creates a gap by provoking the opponent to deprive him of his concentration and take his eyes off, and in that gap he goes beyond the wall of dimension and slips through the opponent's defensive range. It's a drive. However, crossing the dimensional wall puts a heavy burden on the body, so there is a limit to the number of times the dimensional wall can be crossed. Also, because he always uses his concentration, he can only change direction once, including normal movements. How do you move on the court to reach the goal in the shortest time without being robbed of the ball?

Problem

Consider a rectangle on a two-dimensional plane with (0,0) at the bottom left and (50,94) at the top right. In addition, there are N circles on this plane, the center position of the i-th circle is (x_i, y_i), and the radius is r_i. There is no overlap between the circles.

Let (25,0) be the point S and (25,94) be the point G, and consider the route from S to G. A "path" consists of (1) a line segment connecting S and G, or (2) a combination of a line segment SP and a line segment GP at any point P inside a rectangle. In the middle of the route from S to G, the period from entering the inside of a circle to exiting the inside of the circle is defined as "the section passing through the inside of the circle". However, it is assumed that the circumferences of the rectangle and the circle are not included in the rectangle and the circle, respectively.

Find the length of the shortest route among the routes where the number of sections passing through the inside of the circle is D or less. If you can't reach the goal, return -1.

Input

The input consists of the following format.


N D
x_1 y_1 r_1
...
x_N y_N r_N

The first line consists of two integers, and the number N of circles and the number of times D that can pass inside the circle are given, separated by one blank character. The following N lines are given circle information. The i + 1 line (1 \ leq i \ leq N) consists of three integers, and the x-coordinate x_i, y-coordinate y_i, and radius r_i of the center of the i-th circle are given by separating them with one blank character.

Constraints:

* 0 \ leq N \ leq 5
* 0 \ leq D \ leq 5
* 0 \ leq x_i \ leq 50
* 0 \ leq y_i \ leq 94
* 1 \ leq r_i \ leq 100
* It can be assumed that any two circles are separated by 10 ^ {-5} or more.
* It can be assumed that S and G are not included inside any circle.
* It can be assumed that S and G are separated from any circle by 10 ^ {-5} or more.
* It can be assumed that the point P in the shortest path is more than 10 ^ {-5} away from the circumference of the rectangle and any circumference.



Output

Output the length of the shortest path on one line. Be sure to start a new line at the end of the line. However, if you cannot reach the goal, return -1. Absolute error or relative error of 10 ^ {-7} or less is allowed for the correct answer.

Sample Input 1


Ten
25 47 10

Sample Output 1


96.2027355887

DisappearDrive_sample1.png

The detour route is the shortest because it cannot disappear.

Sample Input 2


1 1
25 47 10

Sample Output 2


94.0000000000

DisappearDrive_sample2.png

It can disappear, so you just have to go straight through it.

Sample Input 3


Ten
20 47 5

Sample Output 3


94.0000000000

DisappearDrive_sample3.png

Since the circumference is not included in the circle, it can pass through without disappearing.

Sample Input 4


Ten
25 47 40

Sample Output 4


-1

DisappearDrive_sample4.png

You can't reach the goal because you can't disappear or detour.

Sample Input 5


5 2
11 10 16
33 40 18
20 66 10
45 79 14
22 85 8

Sample Output 5


96.1320937224

DisappearDrive_sample5.png





Example

Input

1 0
25 47 10


Output

96.2027355887