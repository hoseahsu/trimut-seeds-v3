You are given an integer N. Among the integers between 1 and N (inclusive), how many Shichi-Go-San numbers (literally "Seven-Five-Three numbers") are there?

Here, a Shichi-Go-San number is a positive integer that satisfies the following condition:

* When the number is written in base ten, each of the digits `7`, `5` and `3` appears at least once, and the other digits never appear.

Constraints

* 1 \leq N < 10^9
* N is an integer.

Input

Input is given from Standard Input in the following format:


N


Output

Print the number of the Shichi-Go-San numbers between 1 and N (inclusive).

Examples

Input

575


Output

4


Input

3600


Output

13


Input

999999999


Output

26484