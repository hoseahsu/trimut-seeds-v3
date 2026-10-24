Gorillas in Kyoto University are good at math. They are currently trying to solve problems to find the value of an expression that contains two functions, `_` , `^`. Each of these functions takes two input values. `_` function returns the smaller of the two input values and `^` function returns the larger. Gorillas know that integers in the expression are non-negative and less than or equal to 99, but can not find out the length of the expression until they read a terminal symbol `?` that represents the end of the expression. The number of characters included in each expression is less than or equal to 1000, but they do not even know this fact. Ai, a smart gorilla, noticed that she may be able to know the value of the expression even if they don't read the whole expression.

For example,

Assume you read the following sentence from the left.


^(41,3)?

When you read the sixth character, that is, when you read the following expression,


^(41,3

you can tell the second input value of the funcion is whether 3 or an integer between 30 and 39, and the value turns out 41.

Since Ai wants to solve problems earlier than other gorillas, she decided to solve the problems such that she reads as fewer characters as possible from the left. For each expression, Find the value of the expression and the minimum number of characters Ai needs to read to know the value.

Constraints

* 1 \leq Q \leq 200
* The number of characters each expression contains is less than or equal to 1000.

Input

The input consists of multiple test cases and is given from Standard Input in the following format:


Q
statement_1
...
statement_Q

Input

The input consists of multiple test cases and is given from Standard Input in the following format:


Q
statement_1
...
statement_Q

Output

Output consists of Q lines. On line i (1 \leq i \leq Q), print the value of the expression and the number of character Ai needs to read for the test case i separated by space.

Examples

Input

4
_(4,51)?
^(99,_(3,67))?
_(0,87)?
3?


Output

4 5
99 4
0 3
3 2


Input

7
_(23,^(_(22,40),4))?
_(0,99)?
^(99,_(^(19,2),5))?
_(^(43,20),^(30,29))?
^(_(20,3),_(50,41))?
^(_(20,3),_(3,41))?
^(_(20,3),_(4,41))?


Output

22 18
0 3
99 4
30 17
41 17
3 14
4 15