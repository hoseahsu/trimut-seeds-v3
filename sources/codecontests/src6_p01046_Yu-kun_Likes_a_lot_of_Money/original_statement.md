Background

The kindergarten attached to the University of Aizu is a kindergarten where children who love programming gather. Yu, one of the kindergarten children, loves money as much as programming. Yu-kun visited the island where treasures sleep to make money today. Yu-kun has obtained a map of the treasure in advance. I want to make as much money as possible based on the map. How much money can Yu get up to?

Problem

You will be given a map, Yu-kun's initial location, the types of treasures and the money they will earn, and the cost of destroying the small rocks. Map information is given as a field of h squares x w squares. The characters written on each square of the map and their meanings are as follows.

*'@': Indicates the position where Yu is first. After Yu-kun moves, treat it like a road.
*'.': Represents the way. This square is free to pass and does not cost anything.
*'#': Represents a large rock. This square cannot pass.
*'*': Represents a small rock. It can be broken by paying a certain amount. After breaking it, it becomes a road.
* '0', '1', ..., '9','a','b', ...,'z','A','B', ...,'Z': Treasure Represents a square. By visiting this square, you will get the amount of money of the treasure corresponding to the letters written on it. However, you can only get money when you first visit.



Yu-kun can move to any of the adjacent squares, up, down, left, and right with one move. However, you cannot move out of the map.

You don't have to have the amount you need to break a small rock at the time, as you can pay later. Therefore, Yu needs to earn more than the sum of the amount of money it took to finally break a small rock.

Output the maximum amount you can get.

Constraints

The input meets the following constraints.

* 1 ≤ h, w ≤ 8
* 0 ≤ n ≤ min (h × w -1,62) where min (a, b) represents the minimum value of a, b
* 1 ≤ vi ≤ 105 (1 ≤ i ≤ n)
* 1 ≤ r ≤ 105
* All inputs except cj, k, ml are given as integers (1 ≤ j ≤ h, 1 ≤ k ≤ w, 1 ≤ l ≤ n)
* Exactly one'@' is written on the map
* Just n treasures are written on the map
* The type of treasure written on the map is one of the ml given in the input
* No more than one treasure of the same type will appear on the map

Input

The input is given in the following format.


h w n r
c1,1 c1,2… c1, w
c2,1 c2,2… c2, w
...
ch, 1 ch, 2… ch, w
m1 v1
m2 v2
...
mn vn


In the first line, the vertical length h of the map, the horizontal length w, the number of treasures contained in the map n, and the cost r for destroying a small rock are given separated by blanks.

In the following h line, w pieces of information ci and j of each cell representing the map are given. (1 ≤ i ≤ h, 1 ≤ j ≤ w)

In the next n lines, the treasure type mk and the treasure amount vk are given, separated by blanks. (1 ≤ k ≤ n)

Output

Output the maximum amount of money you can get on one line.

Examples

Input

3 3 1 10
@0.
...
...
0 100


Output

100


Input

3 3 1 10
@#b
.#.
.#.
b 100


Output

0


Input

3 3 1 20
@*C
..*
...
C 10


Output

0