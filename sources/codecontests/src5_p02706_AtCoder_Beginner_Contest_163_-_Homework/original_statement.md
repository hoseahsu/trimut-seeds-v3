Takahashi has N days of summer vacation.

His teacher gave him M summer assignments. It will take A_i days for him to do the i-th assignment.

He cannot do multiple assignments on the same day, or hang out on a day he does an assignment.

What is the maximum number of days Takahashi can hang out during the vacation if he finishes all the assignments during this vacation?

If Takahashi cannot finish all the assignments during the vacation, print `-1` instead.

Constraints

* 1 \leq N \leq 10^6
* 1 \leq M \leq 10^4
* 1 \leq A_i \leq 10^4

Input

Input is given from Standard Input in the following format:


N M
A_1 ... A_M


Output

Print the maximum number of days Takahashi can hang out during the vacation, or `-1`.

Examples

Input

41 2
5 6


Output

30


Input

10 2
5 6


Output

-1


Input

11 2
5 6


Output

0


Input

314 15
9 26 5 35 8 9 79 3 23 8 46 2 6 43 3


Output

9