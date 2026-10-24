In the spring of 2014, a student successfully passed the university and started living alone. The problem here is what to do with the supper. He decided to plan a supper for the next N days.

He wants to maximize the total happiness he gets in N days. Of course, the more delicious or favorite you eat, the higher your happiness.

His dinner options are two, either head to a nearby dining room or cook for himself.

The happiness you get in the cafeteria depends on the menu of the day. The menu changes daily, but there is only one type every day, and all the menus for N days have already been released. So he knows all the information that if you go to the cafeteria on day i (1 ≤ i ≤ N) you will get the happiness of Ci.

The happiness obtained by self-catering is the self-catering power at the start of self-catering multiplied by a constant P. The initial value of self-catering power is Q, which is -1 if you go to the restaurant every day, +1 if you cook yourself, and fluctuates at the end of the meal of the day.

Find the maximum sum of happiness for him.

Constraints

* 1 ≤ N ≤ 500,000
* 0 ≤ P ≤ 500,000
* | Q | ≤ 500,000
* | Ci | ≤ 500,000

Input

The input is given in the following format as N + 1 line.


N P Q
C1
C2
::
CN


* The first line is given three integers N, P, and Q, which are the number of days, the constant for calculating the happiness of self-catering, and the initial value of self-catering power.
* From the 2nd line to the N + 1st line, one integer is given, and the i + 1st line gives the happiness obtained when going to the cafeteria on the i day.

Output

Output the maximum value of happiness that can be taken in one line.

Examples

Input

1 1 1
2


Output

2


Input

3 2 1
3
3
3


Output

12


Input

3 1 -1
2
-3
2


Output

2


Input

3 1 -10
-10
-10
-10


Output

-27