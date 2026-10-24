Extended Euclid Algorithm




Given positive integers a and b, find the integer solution (x, y) to ax + by = gcd(a, b), where gcd(a, b) is the greatest common divisor of a and b.

Constraints

* 1 ≤ a, b ≤ 109

Input


a b


Two positive integers a and b are given separated by a space in a line.

Output

Print two integers x and y separated by a space. If there are several pairs of such x and y, print that pair for which |x| + |y| is the minimal (primarily) and x ≤ y (secondarily).

Examples

Input

4 12


Output

1 0


Input

3 8


Output

3 -1