One day Alice was experimenting with the numbers to make new algorithms. He introduce a new term Rsum.
Rsum of any number is defined as number obtained by iterative summing of digits of the given number until single digit number is obtained. 
For example: 
365 --> (3+6+5) = 14
 14  --> 1+4 = 5  
Rsum(365)=5   

Naughty Bob came in the room of Alice in his absence and change all the numbers on which Alice was experimenting by their corresponding factorials. For example Bob will change 3 with  6 (3!=321). Consider 0!=0.

When Alice start experimenting without knowing that the numbers are now changed. He got some ambiguous results and unable to find some pattern for his algorithm.  So he wants your help. You are given a range [A,B] of actual numbers and your task is to find sum of all Rsum values in range [A,B] of new changed numbers.

Input:
First line consist of T test cases. Next T line contain two integers a,b in each line.  

Output:
Find Sum of Rsum of all numbers in given range [A,B].  

Constraints:
1 ≤ T ≤ 10^5
0 ≤ A ≤ B ≤ 10^6 

SAMPLE INPUT
2
1 3
3 4

SAMPLE OUTPUT
9
12

Explanation

Test case 1:
1!=1 and Rsum(1)=1,
2!=2 and Rsum(2)=2,
3!=6 and Rsum(6)=6.
So the sum of Rsums is 1+2+6=9.

Similarly for Test case 2.