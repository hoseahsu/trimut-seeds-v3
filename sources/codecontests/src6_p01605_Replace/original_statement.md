replace replace

Problem Statement

Given the string S. The following processing is performed in the order of Q pieces.

* Replace all the characters c_i contained in S with the character string p_i at the same time.



Finally, output (1-indexed) from the A character to the B character of the character string S.

Constraints

* 1 ≤ Q ≤ 3 \ times 10 ^ 5
* 1 ≤ A ≤ B ≤ 10 ^ {18}
* B-A ≤ 10 ^ 5
* 1 ≤ | S | ≤ 10
* 1 ≤ | p_i | ≤ 10
* S is a character string consisting of lowercase alphabets.
* c_i is one lowercase alphabetic character.
* p_i is a string consisting of one "." (Period) or a lowercase alphabet. When p_i = "." (Period), treat p_i as an empty string.

Input

Input follows the following format. All given numbers are integers.


S
Q A B
c_1 p_1
...
c_Q p_Q

Output

After performing Q processes in order, if B is larger than | S |, output "." (Period) on one line.
In other cases, output (1-indexed) from the A character to the B character of the character string S.

Examples

Input

abaz
3 1 5
a cab
b .
c x


Output

xaxaz


Input

original
1 2 5
x notchange


Output

rigi


Input

aaaa
2 1 1
a .
a nothing


Output

.