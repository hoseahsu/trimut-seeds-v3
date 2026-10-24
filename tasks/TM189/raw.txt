We have N switches with "on" and "off" state, and M bulbs. The switches are numbered 1 to N, and the bulbs are numbered 1 to M.

Bulb i is connected to k_i switches: Switch s_{i1}, s_{i2}, ..., and s_{ik_i}. It is lighted when the number of switches that are "on" among these switches is congruent to p_i modulo 2.

How many combinations of "on" and "off" states of the switches light all the bulbs?

Constraints

* 1 \leq N, M \leq 10
* 1 \leq k_i \leq N
* 1 \leq s_{ij} \leq N
* s_{ia} \neq s_{ib} (a \neq b)
* p_i is 0 or 1.
* All values in input are integers.

Input

Input is given from Standard Input in the following format:


N M
k_1 s_{11} s_{12} ... s_{1k_1}
:
k_M s_{M1} s_{M2} ... s_{Mk_M}
p_1 p_2 ... p_M


Output

Print the number of combinations of "on" and "off" states of the switches that light all the bulbs.

Examples

Input

2 2
2 1 2
1 2
0 1


Output

1


Input

2 3
2 1 2
1 1
1 2
0 0 1


Output

0


Input

5 2
3 1 2 5
2 2 3
1 0


Output

8