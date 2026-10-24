A prime number is one which is divisible by exactly two numbers 1 and itself.
Given a number, find out if the number obtained by summing all digits of that number is a prime.

Input Format:
The input begins with number of test-cases t in a single line. In each of next tlines there is a number n.

Output Format
In each line print YES if sum of digits of the number is a prime.Otherwise print NO.

t < 100000, 1 < n < 1000000

Example
There are 3 test cases here 32, 51, 101

Input:

3

32

51

101

Output

YES

NO

YES

Explanation

Number of test cases t = 3

32 -> 3 + 2 = 5 . Since 5 is a prime , we print YES

51 -> 5 + 1 = 6 . Since 6 is not a prime , we print NO

101 ->1+0+1 = 2 . Since 2 is a prime , we print YES

SAMPLE INPUT
2
33
122

SAMPLE OUTPUT
NO
YES