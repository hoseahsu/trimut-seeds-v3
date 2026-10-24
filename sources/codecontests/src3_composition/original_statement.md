We all know that every positive integer can be represented as the sum of one or more odd integers. 
For eg: 4 = 1 + 1 + 1 + 1. Now, your task in this question is to find out the value of G(n), which equals to the number of all possible representations, as described above, of the given integer, n.  Since the answer could be very large, you need to output it modulo 1000000007 (10^9 +7). 

Note : Order in which the odd integers appear in the representation of n does matter . For eg : Two possible representations of 4 are :  1 + 3 and 3 + 1 are counted individually.  
Input :
The first line of the input contains an integer T, the number of test cases. Then T test cases follow. Each test case consists of a line which contains a positive integer, n.

Output :
Output on a new line the value of G(n).

Constraints :
1 ≤ T ≤ 1000

1 ≤ n ≤10^18

Warning : large Input/Output data, be careful with certain languages.
SAMPLE INPUT
2
1
4

SAMPLE OUTPUT
1
3