We have an H-by-W matrix. Let a_{ij} be the element at the i-th row from the top and j-th column from the left. In this matrix, each a_{ij} is a lowercase English letter.

Snuke is creating another H-by-W matrix, A', by freely rearranging the elements in A. Here, he wants to satisfy the following condition:

* Every row and column in A' can be read as a palindrome.



Determine whether he can create a matrix satisfying the condition.

Constraints

* 1 ≤ H, W ≤ 100
* a_{ij} is a lowercase English letter.

Input

Input is given from Standard Input in the following format:


H W
a_{11}a_{12}...a_{1W}
:
a_{H1}a_{H2}...a_{HW}


Output

If Snuke can create a matrix satisfying the condition, print `Yes`; otherwise, print `No`.

Examples

Input

3 4
aabb
aabb
aacc


Output

Yes


Input

2 2
aa
bb


Output

No


Input

5 1
t
w
e
e
t


Output

Yes


Input

2 5
abxba
abyba


Output

No


Input

1 1
z


Output

Yes