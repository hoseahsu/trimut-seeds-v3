Brave Ponta has finally arrived at the final dungeon. This is a dark wilderness in front of the fort of the evil emperor Boromos, with fairly strong monsters guarding their territories.

<image>


Figure 1: Wilderness

As shown in Fig. 1, the wilderness is represented by a 4 × 4 square region with the southwest as the origin (0, 0). Inside this area are monsters, as shown by the dots in the figure. Brave Ponta must cross this area from west to east (W to E). That is, you must start from the point where the x coordinate is 0.0 and the y coordinate is 0.0 or more and 4.0 or less, and move to the point where the x coordinate is 4.0 and the y coordinate is 0.0 or more and 4.0 or less.

When an enemy enters the area, the monster attacks the enemy if the distance between him and the enemy is shorter than the distance between any other monster and the enemy.

Now that there are not enough items, it was Ponta who really wanted to avoid fighting as much as possible before fighting Boromos. There, Ponta noticed: If you follow the path where there are always two or more monsters with the shortest distance to you, you won't be attacked by monsters.

Whether the brave Ponta can reach Boromos unscathed depends on your control. Create a program to find the shortest distance through the dark wilderness.

For reference, the shortest path in FIG. 1 is shown in FIG.

<image>


Figure 2: Shortest path



Input

Multiple datasets are given as input. Each dataset is given in the following format:

n (number of monsters: integer)
x1 y1 (Position of the first monster: Real number separated by blanks)
x2 y2 (Position of the second monster: Real number separated by blanks)
..
..
xn yn (position of nth monster: real number separated by blanks)


n is 1 or more and 20 or less. The x and y coordinate values ​​that indicate the position of the monster are 0.0 or more and 4.0 or less.

When n is 0, it indicates the end of input.

Output

Output the shortest distance on one line for each dataset. If you can't cross the wilderness without being attacked by a monster, print "impossible".

The distance output may have an error of 0.00001 or less.

Example

Input

2
1 1
3 3
4
1.0 0.5
1.0 2.5
3.0 1.5
3.0 3.5
1
2.0 2.0
0


Output

5.656854249492
4.618033988750
impossible