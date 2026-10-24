Milky Way

Milky Way

English text is not available in this practice contest.

The Milky Way Transportation Corporation is a travel agency that plans and manages interstellar travel tours. The Milky Way Transportation Corporation is planning a project called "Milky Way Crossing Orihime Hikoboshi Experience Tour". This tour departs from Vega in Lyra and travels around the stars to Altair in Aquila. You are an employee of the Milky Way Transportation Corporation and are responsible for choosing the route of the tour.

For simplicity, the Milky Way shall be on two-dimensional coordinates, and the stars shall be represented by pentagrams. The spacecraft used for the tour is equipped with a special engine and can move on the pentagram line segment without energy. On the other hand, when moving between pentagrams, energy proportional to the distance is required.

In recent years, sales of the Milky Way Transportation Corporation have been sluggish, and there is a pressing need to save various necessary expenses such as energy costs for spacecraft. Your job is to find a route that minimizes the sum of interstellar travel distances when moving from Vega to Altair, and write a program that outputs that sum.

Note that when moving from one pentagram to another that is contained within it, if the pentagrams are not in contact with each other, they are treated as interstellar movements.

Figure D-1 illustrates the third Sample Input. In the figure, the red line segment represents the part of the interstellar movement of the route that minimizes the total interstellar movement distance.

<image>

Figure D-1: Movement between stars

Input

The input consists of one or more datasets. One dataset has the following format:

> N M L
> x1 y1 a1 r1
> x2 y2 a2 r2
> ...
> xN yN aN rN
>

The first line of each test case consists of the integers N, M, L, where N is the number of stars (1 ≤ N ≤ 100), M is the Vega number (1 ≤ M ≤ N), and L is the Altair number (1 ≤ M ≤ N). Represents 1 ≤ L ≤ N). Information on each star is given in the following N lines. Each row consists of four integers, xi, yi, ai, and ri, where xi is the x-coordinate of the center of the i-th star (0 ≤ xi ≤ 1,000) and yi is the y-coordinate of the center of the i-th star (0 ≤ yi). ≤ 1,000), ai is the angle formed by the straight line connecting the center coordinates of the i-th star and the tip of the star with the y-axis (0 ≤ ai <72), and ri is from the center coordinates of the i-th star to the tip of the star. The length (1 ≤ ri ≤ 1,000). The end of the input is represented by a line containing three zeros.

The star on the left in Figure D-2 represents the star with x = 5, y = 10, a = 0, r = 5, and the star on the right is x = 15, y = 10, a = 30, r = 5. Represents the star of.

<image>

Figure D-2: Star example

Output

For each input, output the minimum total interstellar movement distance required to move from Vega to Altair on one line. The output must not have an error greater than 0.000001.

Sample Input


1 1 1
5 5 0 5
2 1 2
5 5 0 5
15 5 0 5
3 2 3
15 15 0 5
5 5 10 5
25 25 20 5
0 0 0


Output for Sample Input


0.00000000000000000000
0.48943483704846357796
9.79033725601359705593






Example

Input




Output