The postal code in Atcoder Kingdom is A+B+1 characters long, its (A+1)-th character is a hyphen `-`, and the other characters are digits from `0` through `9`.

You are given a string S. Determine whether it follows the postal code format in Atcoder Kingdom.

Constraints

* 1≤A,B≤5
* |S|=A+B+1
* S consists of `-` and digits from `0` through `9`.

Input

Input is given from Standard Input in the following format:


A B
S


Output

Print `Yes` if S follows the postal code format in AtCoder Kingdom; print `No` otherwise.

Examples

Input

3 4
269-6650


Output

Yes


Input

1 1
---


Output

No


Input

1 2
7444


Output

No