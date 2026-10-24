Vipul has N empty boxes, numbered from 1 to N, with infinite capacity. He performs M operations. Each operation is described by 3 integers, a, b, and k. Here, a and b are indices of the boxes, and k is the number of marbles to be added inside each box whose index lies between a and b (both inclusive). Can you tell the average number of marbles after M operations?

Input Format

The first line contains two integers, N and M, separated by a single space. 
M lines follow; each of them contains three integers, a, b, and k, separated by spaces.

Output Format

A single line containing the average number of marbles across N boxes, rounded down to the nearest integer.

Constraints 

3≤N≤10^7 
1≤M≤10^5 
1≤a≤b≤N 
0≤k≤10^6

Note: Rounded down means finding the greatest integer which is less than or equal to the given number. E.g. 13.65 and 13.23 are rounded down to 13, while 12.98 is rounded down to 12.

SAMPLE INPUT
5 3
1 2 100
2 5 100
3 4 100

SAMPLE OUTPUT
160

Explanation

Initially each of the jars contains 0 candies

0 0 0 0

First operation:

100 100 0 0 0  

Second operation:

100 200 100 100 100  

Third operation:

100 200 200 200 100  

Total = 800, 
Average = 800/5 = 160