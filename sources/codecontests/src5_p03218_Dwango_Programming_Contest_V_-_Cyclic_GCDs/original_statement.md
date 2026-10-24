Niwango-kun has \\(N\\) chickens as his pets. The chickens are identified by numbers \\(1\\) to \\(N\\), and the size of the \\(i\\)-th chicken is a positive integer \\(a_i\\).

\\(N\\) chickens decided to take each other's hand (wing) and form some cycles. The way to make cycles is represented by a permutation \\(p\\) of \\(1, \ldots , N\\). Chicken \\(i\\) takes chicken \\(p_i\\)'s left hand by its right hand. Chickens may take their own hand.

Let us define the cycle containing chicken \\(i\\) as the set consisting of chickens \\(p_i, p_{p_i}, \ldots, p_{\ddots_i} = i\\). It can be proven that after each chicken takes some chicken's hand, the \\(N\\) chickens can be decomposed into cycles.

The beauty \\(f(p)\\) of a way of forming cycles is defined as the product of the size of the smallest chicken in each cycle. Let \\(b_i \ (1 \leq i \leq N)\\) be the sum of \\(f(p)\\) among all possible permutations \\(p\\) for which \\(i\\) cycles are formed in the procedure above.

Find the greatest common divisor of \\(b_1, b_2, \ldots, b_N\\) and print it \\({\rm mod} \ 998244353\\).

Constraints

* \\(1 \leq N \leq 10^5\\)
* \\(1 \leq a_i \leq 10^9\\)
* All numbers given in input are integers

Input

Input is given from Standard Input in the following format:


\(N\)
\(a_1\) \(a_2\) \(\ldots\) \(a_N\)


Output

Print the answer.

Examples

Input

2
4 3


Output

3


Input

4
2 5 2 5


Output

2