Aizu has an ancient legend of buried treasure. You have finally found the place where the buried treasure is buried. Since we know the depth of the buried treasure and the condition of the strata to be dug, we can reach the buried treasure at the lowest cost with careful planning. So you decided to create a program that reads the condition of the formation and calculates the route to reach the buried treasure depth at the lowest cost.

The state of the formation is represented by cells arranged in a two-dimensional grid, and the position of each cell is represented by the coordinates (x, y). Let the upper left be (1,1), and assume that the x coordinate increases as it goes to the right and the y coordinate increases as it goes deeper down. You choose one of the cells with the smallest y-coordinate and start digging from there, then dig into one of the cells with the largest y-coordinate. There are two types of cells in the formation:

1. A cell filled with soil. There is a fixed cost for each cell to dig.
2. Oxygen-filled cell. There is no need to dig, and each cell can be replenished with a fixed amount of oxygen. The oxygen in the cell that has been replenished with oxygen is exhausted and cannot be replenished again. Also, when you reach this cell, you must replenish oxygen.



Only left, right, and down cells can be dug from a cell. Once you have dug a cell, you can move it left or right, but you cannot move it up.

You must carry an oxygen cylinder with you when excavating. The moment the oxygen cylinder reaches zero, you will not be able to move, excavate, or replenish oxygen. The remaining amount is decremented by 1 each time you move the cell. Even if the remaining amount of the oxygen cylinder is 0 and the depth of the buried treasure is reached, it is not considered to have been reached. In addition, oxygen can be replenished in cells that have accumulated oxygen, but the excess capacity is discarded.

Create a program that inputs the size of the formation, the excavation cost, the capacity of the oxygen cylinder, the amount of oxygen in the initial state, and the information of the formation, and outputs the minimum cost to reach the deepest cell. However, if the minimum cost exceeds the excavation cost, or if you cannot reach the buried treasure no matter how you dig, please output "NA".

<image>



Input

A sequence of multiple datasets is given as input. The end of the input is indicated by two zero lines. Each dataset is given in the following format.


W H
f m o
c1,1 c2,1 ... cW,1
c1,2 c2,2 ... cW,2
...
c1, H c2, H ... cW, H


The horizontal size W of the formation and the vertical size H (3 ≤ W, H ≤ 10) are given in the first line. The second line is the integer f (1 ≤ f ≤ 10000) that represents your excavation cost, the integer m (3 ≤ m ≤ 50) that represents the capacity of the oxygen cylinder, and the integer o that represents the amount of oxygen you have in the initial state. o ≤ m) is given.

The following H line is given the geological information ci, j. ci, j represents the cell information for coordinates (i, j) and is given in the following format:
If the value is negative, the cell is full of soil and the value represents the cost.
If the value is positive, it is a cell filled with oxygen, and the value represents the amount of oxygen.
However, there are no more than 50 cells in which oxygen has accumulated.

The number of datasets does not exceed 50.

Output

Print the minimum cost or NA on one line for each dataset.

Example

Input

3 3
100 10 10
-100 -20 -100
-100 -20 -100
-100 -20 -100
3 3
100 10 10
-100 -20 -100
-100 -20 -20
-100 -60 -20
3 3
100 10 3
-100 -20 -100
-20 -20 -20
-20 -100 -20
3 3
100 3 3
-100 -20 -30
-100 -20 2
-100 -20 -20
4 5
1500 5 4
-10 -380 -250 -250
-90 2 -80 8
-250 -130 -330 -120
-120 -40 -50 -20
-250 -10 -20 -150
0 0


Output

60
80
NA
50
390