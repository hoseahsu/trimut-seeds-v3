Taro went to a toy store to buy a game of life made by Aizu Hobby. Life games are played using a board with squares and roulette. As shown in the figure, the board has one start point and one goal point, which are connected by a single grid. First, the pieces are placed in the square at the starting point, and the pieces are advanced according to the number of pieces that are turned by turning the roulette wheel. Depending on the square, there are event squares where you can earn money or change the position of the pieces by stopping or passing there. The final victory or defeat is determined by the amount of money you have when the piece reaches the goal point.

<image>



The interesting thing about the game of life at this company is that the size of the roulette eyes, the number of squares to the goal, and the arrangement of the event squares are different for each package. They are written on the case and can be confirmed by reading it. Taro wants to choose the life game that earns the most money, and wants to buy the one with the highest expected value of money. So you decided to help Taro choose a game.

Suppose a roulette wheel divides its circumference into X equal parts, each filled with the values ​​V1, V2, ..., VX. The board has squares numbered 0, 1, ..., Y, and they are connected in order. There are Z special squares called event squares in the squares, and when they reach them, they perform special actions. The number of the square of the event square is given by Ni. There are 1 to 3 types (Ei) of event masses, each of which performs the following actions:

Type (Ei) | Special Behavior | Value (Ai) Range
--- | --- | ---
1 | Advance by the specified value Ai | 1 ~ 10
2 | Get the amount of the specified value Ai | 1 ~ 100
3 | Pay the amount of the specified value Ai | 1 ~ 100



The first amount of money you have is 0 yen, starting from the 0th square and reaching the goal when you reach the Yth square. If you exceed the goal, it is also considered as a goal. There are no events at the start and goal, and multiple events do not overlap in one square. Ignore the events in the squares that are advanced by the event. If the amount of money you have is less than 0 yen, it will be 0 yen.

For example, the expected value of money earned in a life game can be calculated as follows.

<image>



This example shows a life game consisting of three squares: start, event square (get 100 yen), goal, and roulette with 1 or 2. First, when you turn the roulette wheel for the first time, if you get a 1, you will reach the event square and your money will be 100 yen. On the other hand, if you get a 2, you will reach the goal and your money will remain at 0 yen. Both of these occur with a one-half chance.

In addition, if you reach the event square the first time, you will turn the roulette wheel the second time, but you will reach the goal no matter what value you get, and you will have 100 yen in each case.

As you can see, there are three ways to reach the goal. Focusing on the amount of money you have when you reach the goal, there is one case where the amount is 0 yen and the probability is one half, and there are two cases where the probability is 100 yen and the probability is one quarter. In this case, the expected value of the amount of money you have at the goal is the sum of (the amount of money you have x the probability) for each goal method, and the expected value of this life game is 50 yen.

Create a program that inputs roulette information and board information and outputs the expected value of the amount of money you have at the goal.



Input

A sequence of multiple datasets is given as input. The end of the input is indicated by three zero lines. Each dataset is given in the following format:


X Y Z
V1 V2 ... VX
N1 E1 A1
N2 E2 A2
::
NZ EZ AZ


X (1 ≤ X ≤ 4), Vi (1 ≤ Vi ≤ 10), Y (1 ≤ Y ≤ 50), Ni (1 ≤ Ni ≤ Y-1), Z (0 ≤ Z ≤ Y-1), Ei (1 ≤ Ei ≤ 3), Ai (1 ≤ Ai ≤ 100) are given as integers.

The number of datasets does not exceed 100.

Output

For each input dataset, the expected value of the final amount of money is output on one line. Please output the expected value of your money as an integer rounded down to the nearest whole number.

Example

Input

1 2 0
1
1 2 1
1
1 2 100
1 2 1
2
1 2 100
2 2 1
1 2
1 2 100
4 5 3
1 2 3 4
1 1 2
2 2 100
4 3 60
0 0 0


Output

0
100
0
50
20