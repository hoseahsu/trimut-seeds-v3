Problem

Tomorrow is finally the day of the excursion to Maizu Elementary School. Gatcho, who attends Maizu Elementary School, noticed that he had forgotten to buy tomorrow's sweets because he was so excited. Gaccho wants to stick to sweets so that he can enjoy the excursion to the fullest.


Gaccho gets a $ X $ yen allowance from his mother and goes to buy sweets. However, according to the rules of elementary school, the total amount of sweets to bring for an excursion is limited to $ Y $ yen, and if it exceeds $ Y $ yen, all sweets will be taken up by the teacher.

There are $ N $ towns in the school district where Gaccho lives, and each town has one candy store. Each town is assigned a number from 1 to $ N $, and Gaccho lives in town 1. Each candy store sells several sweets, and the price per one and the satisfaction level that you can get for each purchase are fixed. However, the number of sweets in stock is limited. Also, Gaccho uses public transportation to move between the two towns, so to move directly from town $ i $ to town $ j $, you only have to pay $ d_ {i, j} $ yen. It takes.

At first, Gaccho is in Town 1. Gaccho should make sure that the sum of the total cost of moving and the price of the sweets you bought is within $ X $ yen, and the total price of the sweets you bought is within $ Y $ yen. I'm going to buy sweets. You must have arrived at Town 1 at the end. Gaccho wants to maximize the total satisfaction of the sweets he bought. Find the total satisfaction when you do the best thing.

Constraints

The input satisfies the following conditions.

* $ 1 \ leq N \ leq 14 $
* $ 1 \ leq X \ leq 10000 $
* $ 1 \ leq Y \ leq min (1000, X) $
* $ 1 \ leq K \ leq 300 $
* $ 1 \ leq a_i \ leq 1000 $
* $ 1 \ leq b_i \ leq 1000 $
* $ 1 \ leq c_i \ leq 1000 $
* $ 0 \ leq d_ {i, j} \ leq 10000 $
* $ d_ {i, i} = 0 $

Input

All inputs are given as integers in the following format:

$ N $ $ X $ $ Y $
Information on candy stores in town 1
Information on candy stores in town 2
...
Information on candy stores in town $ N $
$ d_ {1,1} $ $ d_ {1,2} $ ... $ d_ {1, N} $
$ d_ {2,1} $ $ d_ {2,2} $ ... $ d_ {2, N} $
...
$ d_ {N, 1} $ $ d_ {N, 2} $ ... $ d_ {N, N} $


On the first line, the number of towns $ N $, the amount of money you have $ X $, and the maximum amount you can use to buy sweets $ Y $ are given, separated by blanks.
From the second line, information on each $ N $ candy store is given.
In the following $ N $ row and $ N $ column, the amount $ d_ {i, j} $ required to go back and forth between town $ i $ and town $ j $ is given, separated by blanks.


Information on candy stores in each town is given in the following format.

$ K $
$ a_1 $ $ b_1 $ $ c_1 $
$ a_2 $ $ b_2 $ $ c_2 $
...
$ a_K $ $ b_K $ $ c_K $


The first line gives $ K $, the number of types of sweets sold at the candy store. In the following $ K $ line, the price of one candy $ a_i $, the satisfaction level $ b_i $ per candy, and the number of stocks $ c_i $ are given, separated by blanks.

Output

Output the maximum value of the total satisfaction level on one line.

Examples

Input

1 10 10
3
1 10 1
2 20 2
3 30 3
0


Output

100


Input

2 10 10
3
1 10 1
2 20 2
3 30 3
1
5 200 1
0 2
3 0


Output

200


Input

3 10 10
1
1 1 1
1
3 3 3
1
5 5 5
0 1 0
1 0 0
0 1 0


Output

10


Input

4 59 40
1
7 6 3
1
10 3 9
2
9 8 5
7 6 10
4
8 2 9
1 7 1
7 7 9
1 2 3
0 28 7 26
14 0 10 24
9 6 0 21
9 24 14 0


Output

34