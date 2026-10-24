One fine day, Benny decided to calculate the number of kilometers that she traveled by her bicycle. Therefore, she bought an odometer and installed it onto her bicycle. But the odometer was broken. It was not able to display the digit 3. This would precisely mean, that the odometer won't be able to display the numbers having one of their digits as 3.

For example, after the number 1299, the odometer will show 1400.

Benny was traveling a lot and now she wants to know the number of kilometers that she has traveled.  You will be given only the number that Benny saw on the odometer. Your task is to determine the real distance.

Input format

The input consists of several test cases.
The first line contains one integer T denoting the number of test cases.
The next T lines contain a single integer N denoting the number that Benny saw on odometer.

Output format

For each test case, print  the real distance in a single line.

Constraints
1 ≤ T ≤ 10^5
0 ≤ N < 10^9 

SAMPLE INPUT
5
5
14
76
67
40

SAMPLE OUTPUT
4
12
59
51
27

Explanation
In the first sample test case, the odometer skipped the number 3 and displayed 4 after it. Hence, the numbers were displayed in the order of [1, 2, 4, 5] accounting to distance of four kilometers travelled.
In the second sample test case, the sequence in which odometer displayed numbers would be [1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14]  and it skipped [3, 13]. Thus, a total of 12 kilometers were travelled.