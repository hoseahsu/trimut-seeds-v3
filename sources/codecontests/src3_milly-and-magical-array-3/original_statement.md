Milly is playing with an Array A of size N. She wants to convert this array into a magical array. This magical array satisfies the condition Ai-1 < Ai where i ∈ [2, N] . She can add a value X to any element of this array any number of times. Your task is to tell her the minimum number of such addition of X are required in order to get the magical array. 

Input

First line of the input will contain T(No. of test cases). 
For every test case, first line will contain two space separated integers denoting N and X. Next line will contain N space separated integers denoting Ai.

Output
For every test case, print the required answer in a new line.
Constraints

1 ≤ T ≤ 10
2 ≤ N ≤ 10^5
1 ≤ X ≤ 10^9
1 ≤ Ai ≤ 10^9

SAMPLE INPUT
2
2 1
1 1
3 1
1 1 2

SAMPLE OUTPUT
1
2

Explanation

Test case #1: Add 1 to the second value. 
Test case #2: Add 1 to the second value and add 1 to the third value.