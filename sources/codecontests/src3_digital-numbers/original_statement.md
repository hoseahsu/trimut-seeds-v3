Bosky is a very curious child who turned 13 yesterday. His parents gifted him a digital watch which he really liked. He was amazed to see how each number can be represented inside one cell only by switching different edges on and off.

Today, while he was in his home alone, getting bored looking at his watch, an idea popped up in his scientific mind. He immediately went to the garage and picked up a long rectangular cardboard, which was 2 units wide and L units long, and lots of thin LED tubes which were 1 unit long.

Bosky wanted to place LED tubes on the rectangular cardboard in such a way that he can represent as many digits as possible using the LED tubes and rectangular board similar to how digits are represented on his watch.

He realized that none of the LED tubes are working so he decided to purchase new LED tubes.

Each LED tube will cost Rs. 7

He has Rs. M with him and he now goes to market and spends all the money purchasing LED tubes.

After he brought all the LED tubes home, he wondered how many different digits he can represent on the rectangular board such that he doesn't have to repeat a number again.

But Bosky is tired now and does not want to try all the possible combinations to figure out how many digits he can represent on the board. He knows that you are a great programmer and you would surely help him. He calls you and tells you the length L and the amount of money M he has. Now, you have to tell him how many different digits he can represent on the rectangular board such that none of the digits is repeated, given:

0 requires -- 6 tubes

1 requires -- 2 tubes

2 requires -- 5 tubes

3 requires -- 5 tubes

4 requires -- 4 tubes

5 requires -- 5 tubes

6 requires -- 6 tubes

7 requires -- 3 tubes

8 requires -- 7 tubes

9 requires -- 6 tubes

[NOTE: Each digit occupies exactly 1 unit length on the board]

Input:

Input will contain a number T denoting the number of test cases. 

Then T test cases follow, each one consisting of two space-separated integers L and M .

Output

For each test case, output a single integer - the number of different digits Bosky can represent on the rectangular board such that none of the number is repeated and all the digits fit on the board.

Constraints

1  ≤ T  ≤ 100

0 ≤ M ≤ 2000

0 ≤ L ≤ 10

SAMPLE INPUT
4
1 14
1 50
4 28
5 700

SAMPLE OUTPUT
1
10
3
32491

Explanation

Case 1: He has 14 rupees and he can purchase 2 LED tubes using which he can represent only '1' on the board.

Case 2: He can purchase 7 LED tubes using 50 rupees and the number of digits he can represent using 7 tubes are 10.