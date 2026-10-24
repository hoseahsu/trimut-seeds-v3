You are given a positive integer N. Find the number of the pairs of integers u and v (0≦u,v≦N) such that there exist two non-negative integers a and b satisfying a xor b=u and a+b=v. Here, xor denotes the bitwise exclusive OR. Since it can be extremely large, compute the answer modulo 10^9+7.

Constraints

* 1≦N≦10^{18}

Input

The input is given from Standard Input in the following format:


N


Output

Print the number of the possible pairs of integers u and v, modulo 10^9+7.

Examples

Input

3


Output

5


Input

1422


Output

52277


Input

1000000000000000000


Output

787014179