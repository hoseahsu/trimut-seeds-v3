You are given three strings A, B and C. Check whether they form a word chain.

More formally, determine whether both of the following are true:

* The last character in A and the initial character in B are the same.
* The last character in B and the initial character in C are the same.



If both are true, print `YES`. Otherwise, print `NO`.

Constraints

* A, B and C are all composed of lowercase English letters (`a` - `z`).
* 1 ≤ |A|, |B|, |C| ≤ 10, where |A|, |B| and |C| are the lengths of A, B and C, respectively.

Input

Input is given from Standard Input in the following format:


A B C


Output

Print `YES` or `NO`.

Examples

Input

rng gorilla apple


Output

YES


Input

yakiniku unagi sushi


Output

NO


Input

a a a


Output

YES


Input

aaaaaaaaab aaaaaaaaaa aaaaaaaaab


Output

NO