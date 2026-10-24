Tak has N cards. On the i-th (1 \leq i \leq N) card is written an integer x_i. He is selecting one or more cards from these N cards, so that the average of the integers written on the selected cards is exactly A. In how many ways can he make his selection?

Constraints

* 1 \leq N \leq 50
* 1 \leq A \leq 50
* 1 \leq x_i \leq 50
* N,\,A,\,x_i are integers.

Input

The input is given from Standard Input in the following format:


N A
x_1 x_2 ... x_N


Output

Print the number of ways to select cards such that the average of the written integers is exactly A.

Examples

Input

4 8
7 9 8 9


Output

5


Input

3 8
6 6 9


Output

0


Input

8 5
3 6 2 8 7 6 5 9


Output

19


Input

33 3
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3


Output

8589934591