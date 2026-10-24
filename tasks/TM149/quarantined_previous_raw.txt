PowerShell had N natural numbers. He wanted to test Xenny's speed in finding the sum and difference of several numbers.

He decided to ask Xenny several questions. In each question, he gave him two positive integers L and R. He asked him to find the sum of all integers from index L to index R (inclusive) and the difference of all integers from index R to index L (inclusive).

(Numbers are 1-indexed) 

He asked Xenny Q such questions.

Your task is to report the answer that Xenny gave to each of the Q questions.

Input Format:

First line contains 2 space-separated integers - N and Q.

Second line contains N space-separated natural numbers.

Q lines follow - each line contains 2 space-separated postiive integers L and R.

Output Format:

Output Q lines - the answer to each question.

Each line should contain 2 space-separated integers - the required sum and difference.

Constraints:

1 ≤ N ≤ 10^6

1 ≤ L ≤ R ≤ 10^6

1 ≤ Q ≤ 10^5

-1000000 ≤ Numbers ≤ 1000000

SAMPLE INPUT
4 1
1 2 3 4
1 3

SAMPLE OUTPUT
6 0

Explanation

1 + 2 + 3 = 6

3 - 2 - 1 = 0