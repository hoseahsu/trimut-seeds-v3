Given an integer N.  Find out the PermutationSum where PermutationSum for integer N is defined as the maximum sum of difference of adjacent elements in all arrangement of numbers from 1 to N. 

NOTE: Difference between two elements A and B will be considered as abs(A-B) or |A-B| which always be a positive number.

Input:
First line of input contains number of test case T. Each test case contains a single integer N.  

Output:
For each test case print the maximum value of PermutationSum.

Constraints:
1 ≤ T ≤ 10000
1 ≤ N ≤ 10^5

SAMPLE INPUT
3
1
2
3SAMPLE OUTPUT
1
1
3

Explanation

Test Case #3:
For N=3, possible arrangements are :
{1,2,3}
{1,3,2}
{2,1,3}
{2,3,1}
{3,1,2}
{3,2,1}   
Value of PermutationSum for arrangement {1,2,3} is 2 i.e abs(1-2)+abs(2-3)=2
Value of PermutationSum for arrangement {1,3,2} is 3.
Value of PermutationSum for arrangement {2,1,3} is 3.
Value of PermutationSum for arrangement {2,3,1} is 3.
Value of PermutationSum for arrangement {3,1,2} is 3.
Value of PermutationSum for arrangement {3,2,1} is 2.
So the maximum value of PermutationSum for all arrangements is 3.