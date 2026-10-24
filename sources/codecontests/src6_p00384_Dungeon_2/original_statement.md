Bob is playing a game called "Dungeon 2" which is the sequel to the popular "Dungeon" released last year. The game is played on a map consisting of $N$ rooms and $N-1$ roads connecting them. The roads allow bidirectional traffic and the player can start his tour from any room and reach any other room by way of multiple of roads. A point is printed in each of the rooms.

Bob tries to accumulate the highest score by visiting the rooms by cleverly routing his character "Tora-Tora." He can add the point printed in a room to his score only when he reaches the room for the first time. He can also add the points on the starting and ending rooms of Tora-Tora’s journey. The score is reduced by one each time Tora-Tore passes a road. Tora-Tora can start from any room and end his journey in any room.

Given the map information, make a program to work out the maximum possible score Bob can gain.



Input

The input is given in the following format.


$N$
$p_1$
$p_2$
$...$
$p_N$
$s_1$ $t_1$
$s_2$ $t_2$
$...$
$s_{N-1}$ $t_{N-1}$


The first line provides the number of rooms $N$ ($1 \leq N \leq 100,000$). Each of the subsequent $N$ lines provides the point of the $i$-th room $p_i$ ($-100 \leq p_i \leq 100$) in integers. Each of the subsequent lines following these provides the information on the road directly connecting two rooms, where $s_i$ and $t_i$ ($1 \leq s_i < t_i \leq N$) represent the numbers of the two rooms connected by it. Not a single pair of rooms are connected by more than one road.

Output

Output the maximum possible score Bob can gain.

Examples

Input

7
6
1
-1
4
3
3
1
1 2
2 3
3 4
3 5
5 6
5 7


Output

10


Input

4
5
0
1
1
1 2
2 3
2 4


Output

5