Notice: unusual memory limit!

After the war, destroyed cities in the neutral zone were restored. And children went back to school.

The war changed the world, as well as education. In those hard days, a new math concept was created.

As we all know, logarithm function can be described as: $$$ log(p_1^{a_1}p_2^{a_2}...p_k^{a_2}) = a_1 log p_1 + a_2 log p_2 + ... + a_k log p_k  Where p_1^{a_1}p_2^{a_2}...p_k^{a_2}$$$ is the prime factorization of a integer. A problem is that the function uses itself in the definition. That is why it is hard to calculate.

So, the mathematicians from the neutral zone invented this: $$$ exlog_f(p_1^{a_1}p_2^{a_2}...p_k^{a_2}) = a_1 f(p_1) + a_2 f(p_2) + ... + a_k f(p_k) $$$

Notice that exlog_f(1) is always equal to 0.

This concept for any function f was too hard for children. So teachers told them that f can only be a polynomial of degree no more than 3 in daily uses (i.e., f(x) = Ax^3+Bx^2+Cx+D).

"Class is over! Don't forget to do your homework!" Here it is: $$$ ∑_{i=1}^n exlog_f(i) $$$

Help children to do their homework. Since the value can be very big, you need to find the answer modulo 2^{32}.

Input

The only line contains five integers n, A, B, C, and D (1 ≤ n ≤ 3 ⋅ 10^8, 0 ≤ A,B,C,D ≤ 10^6).

Output

Print the answer modulo 2^{32}.

Examples

Input

12 0 0 1 0


Output

63


Input

4 1 2 3 4


Output

136

Note

In the first sample:

exlog_f(1) = 0

exlog_f(2) = 2

exlog_f(3) = 3

exlog_f(4) = 2 + 2 = 4

exlog_f(5) = 5

exlog_f(6) = 2 + 3 = 5

exlog_f(7) = 7

exlog_f(8) = 2 + 2 + 2 = 6

exlog_f(9) = 3 + 3 = 6

exlog_f(10) = 2 + 5 = 7

exlog_f(11) = 11

exlog_f(12) = 2 + 2 + 3 = 7

 ∑_{i=1}^{12} exlog_f(i)=63 

In the second sample:

exlog_f(1) = 0

exlog_f(2) = (1 × 2^3 + 2 × 2^2 + 3 × 2 + 4) = 26

exlog_f(3) = (1 × 3^3 + 2 × 3^2 + 3 × 3 + 4) = 58

exlog_f(4) = 2 × exlog_f(2) = 52

 ∑_{i=1}^4 exlog_f(i)=0+26+58+52=136 