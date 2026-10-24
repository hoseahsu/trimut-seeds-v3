There are N children, numbered 1, 2, ..., N.

Snuke has decided to distribute x sweets among them. He needs to give out all the x sweets, but some of the children may get zero sweets.

For each i (1 \leq i \leq N), Child i will be happy if he/she gets exactly a_i sweets. Snuke is trying to maximize the number of happy children by optimally distributing the sweets. Find the maximum possible number of happy children.

Constraints

* All values in input are integers.
* 2 \leq N \leq 100
* 1 \leq x \leq 10^9
* 1 \leq a_i \leq 10^9

Input

Input is given from Standard Input in the following format:


N x
a_1 a_2 ... a_N


Output

Print the maximum possible number of happy children.

Examples

Input

3 70
20 30 10


Output

2


Input

3 10
20 30 10


Output

1


Input

4 1111
1 10 100 1000


Output

4


Input

2 10
20 20


Output

0