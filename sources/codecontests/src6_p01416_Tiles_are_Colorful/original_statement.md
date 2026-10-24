Training is indispensable for achieving good results at ICPC. Rabbit wants to win at ICPC, so he decided to practice today as well.

Today's training is to quickly solve popular puzzles and train your instantaneous power. Today's challenge is a puzzle of colorful tiles lined up and erasing them well.

In the initial state, tiles are placed on some squares on the grid. Each tile is colored. After the game starts, the player can perform the operations shown in the following procedure many times.

1. Select one square without tiles and hit that square.
2. Follow from the hit square to the top, and pay attention to the tile when you reach the square where the tile is placed. If you get to the edge of the board without the squares on which the tiles are placed, you will not pay attention to anything.
3. Perform the same operation from the square you hit to the bottom, left, and right. Up to 4 tiles will be the focus of attention.
4. If any of the tiles of interest have the same color, remove those tiles from the board. If there are two pairs of tiles of the same color, remove both.
5. The score will be the same as the number of tiles removed.
6. Stop paying attention.



For example, consider the following situation. The squares without tiles are periods, and the tile colors are represented by uppercase letters.


..A ......
....... B ..
..........
..B ......
..A.CC ....


Now consider the operation of hitting the squares in the second row from the top and the third column from the left. Since there are three tiles of interest, `A`,` B`, and `B`, the two of` B` disappear and the board becomes as follows, and two points are obtained.


..A ......
..........
..........
..........
..A.CC ....


If this puzzle is slow, the time will run out, and you will not be able to see part of the board and you will not know how much training you lacked. Two tiles of each color are placed, but it is not always possible to erase all of them, so let the program calculate the maximum score in advance.



Input


M N
C1,1 C1,2 ... C1, N
C2,1 C2,2 ... C2, N
...
CM, 1CM, 2 ... CM, N


The integers M and N indicate that the board is a grid of vertical M x horizontal N. Ci and j are uppercase letters or periods (`.`), And for the cells in the i-th row from the top and the j-th column from the left, the uppercase letters indicate the color of the tiles placed, and the period indicates the color of the tile. Indicates that no tile is placed on this square.

Satisfy 1 ≤ M ≤ 500 and 1 ≤ N ≤ 500. Each uppercase letter appears as 0 or 2 as you type.

Output

Output the maximum score on one line.

Examples

Input

5 10
..A.......
.......B..
..........
..B.......
..A.CC....


Output

4


Input

3 3
ABC
D.D
CBA


Output

4


Input

5 7
NUTUBOR
QT.SZRQ
SANAGIP
LMDGZBM
KLKIODP


Output

34