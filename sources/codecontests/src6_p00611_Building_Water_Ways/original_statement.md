In ancient times, Romans constructed numerous water ways to supply water to cities and industrial sites. These water ways were amongst the greatest engineering feats of the ancient world.

These water ways contributed to social infrastructures which improved people's quality of life. On the other hand, problems related to the water control and the water facilities are still interesting as a lot of games of water ways construction have been developed.

Your task is to write a program which reads a map and computes the minimum possible cost of constructing water ways from sources to all the cities.



<image>



As shown in Figure 1, the map is represented by H × W grid cells, where each cell represents source, city, flatland, or obstacle.

You can construct only one water way from a source, but there are no limitations on the length of that water way and it can provide water to any number of cities located on its path. You can not construct water ways on the obstacles.

Your objective is to bring water to all the city and minimize the number of cells which represent water ways. In the Figure 1, water ways are constructed in 14 cells which is the minimum cost.

The water ways must satisfy the following conditions:

* a water way cell is adjacent to at most 2 water way cells in four cardinal points.
* a source cell is adjacent to at most 1 water way cell in four cardinal points.
* there is no path from a source to other sources through water ways.

Constraints

* Judge data contains at most 60 data sets.
* 3 ≤ H, W ≤ 10
* 1 ≤ the number of sources, the number of cities ≤ 8
* The map is surrounded by obstacles.
* Sources are not adjacent each other(on the left, right, top and bottom)
* There is a solution.

Input

The input consists of multiple datasets. Each dataset consists of:


H W
H × W characters


The integers H and W are the numbers of rows and columns of the map. H × W characters denote the cells which contain:

* 'P': source
* '*': city
* '.': flatland
* '#': obstacle



The end of input is indicated by a line containing two zeros separated by a space.

Output

For each dataset, print the minimum cost to construct the water ways.

Examples

Input

3 8
########
#P....*#
########
10 10
##########
#P.......#
#..#*....#
#..#*.#.*#
#.....#*.#
#*.......#
#..##....#
#...#.P..#
#P......P#
##########
0 0


Output

5
14


Input

3 8

P....*#

10 10

P.......#
..#*....#
..#*.#.*#
.....#*.#
*.......#
..##....#
...#.P..#
P......P#

0 0


Output

5
14