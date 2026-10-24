There are N squares numbered 1 to N from left to right. Each square has a character written on it, and Square i has a letter s_i. Besides, there is initially one golem on each square.

Snuke cast Q spells to move the golems.

The i-th spell consisted of two characters t_i and d_i, where d_i is `L` or `R`. When Snuke cast this spell, for each square with the character t_i, all golems on that square moved to the square adjacent to the left if d_i is `L`, and moved to the square adjacent to the right if d_i is `R`.

However, when a golem tried to move left from Square 1 or move right from Square N, it disappeared.

Find the number of golems remaining after Snuke cast the Q spells.

Constraints

* 1 \leq N,Q \leq 2 \times 10^{5}
* |s| = N
* s_i and t_i are uppercase English letters.
* d_i is `L` or `R`.

Input

Input is given from Standard Input in the following format:


N Q
s
t_1 d_1
\vdots
t_{Q} d_Q


Output

Print the answer.

Examples

Input

3 4
ABC
A L
B L
B R
A R


Output

2


Input

8 3
AABCBDBA
A L
B R
A R


Output

5


Input

10 15
SNCZWRCEWB
B R
R R
E R
W R
Z L
S R
Q L
W L
B R
C L
A L
N L
E R
Z L
S L


Output

3