You are given an integer n (n ≥ 0) represented with k digits in base (radix) b. So,

$$$n = a_1 ⋅ b^{k-1} + a_2 ⋅ b^{k-2} + … a_{k-1} ⋅ b + a_k.$$$

For example, if b=17, k=3 and a=[11, 15, 7] then n=11⋅17^2+15⋅17+7=3179+255+7=3441.

Determine whether n is even or odd.

Input

The first line contains two integers b and k (2≤ b≤ 100, 1≤ k≤ 10^5) — the base of the number and the number of digits.

The second line contains k integers a_1, a_2, …, a_k (0≤ a_i < b) — the digits of n.

The representation of n contains no unnecessary leading zero. That is, a_1 can be equal to 0 only if k = 1.

Output

Print "even" if n is even, otherwise print "odd".

You can print each letter in any case (upper or lower).

Examples

Input

13 3
3 2 7


Output

even


Input

10 9
1 2 3 4 5 6 7 8 9


Output

odd


Input

99 5
32 92 85 74 4


Output

odd


Input

2 2
1 0


Output

even

Note

In the first example, n = 3 ⋅ 13^2 + 2 ⋅ 13 + 7 = 540, which is even.

In the second example, n = 123456789 is odd.

In the third example, n = 32 ⋅ 99^4 + 92 ⋅ 99^3 + 85 ⋅ 99^2 + 74 ⋅ 99 + 4 = 3164015155 is odd.

In the fourth example n = 2.