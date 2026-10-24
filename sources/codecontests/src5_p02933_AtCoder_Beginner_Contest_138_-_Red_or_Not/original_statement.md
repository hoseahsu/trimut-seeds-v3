You will be given an integer a and a string s consisting of lowercase English letters as input.

Write a program that prints s if a is not less than 3200 and prints `red` if a is less than 3200.

Constraints

* 2800 \leq a < 5000
* s is a string of length between 1 and 10 (inclusive).
* Each character of s is a lowercase English letter.

Input

Input is given from Standard Input in the following format:


a
s


Output

If a is not less than 3200, print s; if a is less than 3200, print `red`.

Examples

Input

3200
pink


Output

pink


Input

3199
pink


Output

red


Input

4049
red


Output

red