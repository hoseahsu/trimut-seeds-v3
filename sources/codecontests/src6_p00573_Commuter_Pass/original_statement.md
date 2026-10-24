There are N stations in the city where JOI lives, and they are numbered 1, 2, ..., and N, respectively. In addition, there are M railway lines, numbered 1, 2, ..., and M, respectively. The railway line i (1 \ leq i \ leq M) connects station A_i and station B_i in both directions, and the fare is C_i yen.

JOI lives near station S and attends IOI high school near station T. Therefore, I decided to purchase a commuter pass that connects the two. When purchasing a commuter pass, you must specify one route between station S and station T at the lowest fare. With this commuter pass, you can freely get on and off the railway lines included in the specified route in both directions.

JOI also often uses bookstores near Station U and Station V. Therefore, I wanted to purchase a commuter pass so that the fare for traveling from station U to station V would be as small as possible.

When moving from station U to station V, first select one route from station U to station V. The fare to be paid on the railway line i included in this route is

* If railway line i is included in the route specified when purchasing the commuter pass, 0 yen
* If railway line i is not included in the route specified when purchasing the commuter pass, C_i yen



It becomes. The total of these fares is the fare for traveling from station U to station V.

I would like to find the minimum fare for traveling from station U to station V when the route specified when purchasing a commuter pass is selected successfully.

Task

Create a program to find the minimum fare for traveling from station U to station V when you have successfully selected the route you specify when purchasing a commuter pass.

input

Read the following input from standard input.

* Two integers N and M are written on the first line. These indicate that there are N stations and M railroad lines in the city where JOI lives.
* Two integers S and T are written on the second line. These indicate that JOI purchases a commuter pass from station S to station T.
* Two integers U and V are written on the third line. These indicate that JOI wants to minimize the fare for traveling from station U to station V.
* Three integers A_i, B_i, and C_i are written in the i-th line (1 \ leq i \ leq M) of the following M lines. These indicate that the railway line i connects station A_i and station B_i in both directions, and the fare is C_i yen.



output

Output the minimum fare for traveling from station U to station V on one line to the standard output when the route from station S to station T is properly specified when purchasing a commuter pass.

Limits

All input data satisfy the following conditions.

* 2 \ leq N \ leq 100 000.
* 1 \ leq M \ leq 200 000.
* 1 \ leq S \ leq N.
* 1 \ leq T \ leq N.
* 1 \ leq U \ leq N.
* 1 \ leq V \ leq N.
* S ≠ T.
* U ≠ V.
* S ≠ U or T ≠ V.
* You can reach any other station from any station using one or more railway lines.
* 1 \ leq A_i <B_i \ leq N (1 \ leq i l \ leq M).
* 1 For \ leq i <j \ leq M, A_i ≠ A_j or B_i ≠ B_j.
* 1 \ leq C_i \ leq 1 000 000 000 (1 \ leq i \ leq M).



Input / output example

Input example 1


6 6
1 6
14
1 2 1
2 3 1
3 5 1
2 4 3
4 5 2
5 6 1


Output example 1


2


In this input example, the route that can be specified when buying a commuter pass is limited to the route of station 1-> station 2-> station 3-> station 5-> station 6.

To minimize the fare for traveling from station 1 to station 4, choose the route station 1-> station 2-> station 3-> station 5-> station 4. If you choose this route, the fare to be paid on each railway line is

* 2 yen for railway line 5 connecting station 4 and station 5.
* 0 yen for other railway lines.



Therefore, the total fare is 2 yen.

Input example 2


6 5
1 2
3 6
1 2 1000000000
2 3 1000000000
3 4 1000000000
4 5 1000000000
5 6 1000000000


Output example 2


3000000000


In this input example, the commuter pass is not used to move from station 3 to station 6.

Input example 3


8 8
5 7
6 8
1 2 2
2 3 3
3 4 4
1 4 1
1 5 5
2 6 6
3 7 7
4 8 8


Output example 3


15


Input example 4


5 5
1 5
twenty three
1 2 1
2 3 10
2 4 10
3 5 10
4 5 10


Output example 4


0


Input example 5


10 15
6 8
7 9
2 7 12
8 10 17
1 3 1
3 8 14
5 7 15
2 3 7
1 10 14
3 6 12
1 5 10
8 9 1
2 9 7
1 4 1
1 8 1
2 4 7
5 6 16


Output example 5


19





Creative Commons License
Information Olympics Japan Committee work "17th Japan Information Olympics (JOI 2017/2018) Final Selection"





Example

Input

6 6
1 6
1 4
1 2 1
2 3 1
3 5 1
2 4 3
4 5 2
5 6 1


Output

2