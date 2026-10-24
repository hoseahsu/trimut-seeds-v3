Ramesh and Suresh were in the same class and got home work from their mathematics teacher. The Homework consists of N strings and each string consists of only digits. The task which they need to perform is that they need to divide the string into 4 integers such that their sum is maximum.

Note:

Each integer should be ≤ 10^12 and should not contain any leading zeroes.

As we know that Suresh and Ramesh are weak in mathematics and also they don't want to be punished. So, they need your help for finding the answer.
INPUT:
First line contains an integer N denoting the number of strings. Next N lines contain N strings each consists of digits only.
OUTPUT:
For each test case, Print the required answer if exists. Print "unlucky" otherwise.

CONSTRAINTS:

1 ≤ N ≤ 10^4
1 ≤ size of each string ≤ 20

SUBTASKS:

subtask 1 : 1 ≤ N ≤ 10^2 : ( 50 pts )
subtask 2 : 1 ≤ N ≤ 10^4 : ( 50 pts )

SAMPLE INPUT
3
4251
52310
00006

SAMPLE OUTPUT
12
56
unlucky

Explanation

In test case 1: 4 integers are 4,2,5,1. So maximum sum is 12.
In test case 2: 4 integers are 52,3,1,0. So maximum sum is 56.
In test case 3: None of division (0 , 0 , 0 , 06) , (0 , 00 , 0 , 6 ) is valid.