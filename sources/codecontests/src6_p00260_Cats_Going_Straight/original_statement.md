There was a large mansion surrounded by high walls. The owner of the mansion loved cats so much that he always prepared delicious food for the occasional cats. The hungry cats jumped over the high walls and rushed straight to the rice that was everywhere in the mansion.

One day the husband found some cats lying down in the mansion. The cats ran around the mansion in search of food, hitting and falling. The husband decided to devise a place to put the rice in consideration of the safety of the cats.

<image>

Seen from the sky, the fence of this mansion is polygonal. The owner decided to place the rice only at the top of the polygon on the premises so that the cats could easily find it. Also, since cats are capricious, it is unpredictable from which point on the circumference of the polygon they will enter the mansion. Therefore, the husband also decided to arrange the rice so that no matter where the cat entered, he would go straight from that point and reach one of the rice.

You can meet this condition by placing rice at all vertices. However, it is difficult to replenish the rice and go around, so the master wanted to place the rice at as few vertices as possible. Now, how many places does the master need to place the rice?

Enter the polygon that represents the wall of the mansion as an input, and create a program that finds the minimum number of vertices on which rice is placed. However, the cat shall be able to go straight only inside the polygon (the sides shall be included inside the polygon).



input

The input consists of multiple datasets. The end of the input is indicated by a single zero line. Each dataset is given in the following format:


n
x1 y1
x2 y2
...
xn yn


The number of vertices of the polygon n (3 ≤ n ≤ 16) is given in the first line. The following n lines give the coordinates of the vertices of the polygon. Each of the n lines consists of two integers separated by one space. xi (-1000 ≤ xi ≤ 1000) indicates the x coordinate of the i-th vertex, and yi (-1000 ≤ yi ≤ 1000) indicates the y coordinate of the i-th vertex. The vertices of a polygon are given in such an order that they visit adjacent vertices counterclockwise.

The number of datasets does not exceed 20.

output

For each data set, the number of vertices on which rice is placed is output on one line.

Example

Input

8
0 0
3 2
6 2
8 6
6 5
7 7
0 4
3 4
8
0 0
5 3
5 2
4 1
6 1
8 6
6 4
2 4
0


Output

1
2