You are given strings S and T consisting of lowercase English letters.

You can perform the following operation on S any number of times:

Operation: Choose two distinct lowercase English letters c_1 and c_2, then replace every occurrence of c_1 with c_2, and every occurrence of c_2 with c_1.

Determine if S and T can be made equal by performing the operation zero or more times.

Constraints

* 1 \leq |S| \leq 2 \times 10^5
* |S| = |T|
* S and T consists of lowercase English letters.

Input

Input is given from Standard Input in the following format:


S
T


Output

If S and T can be made equal, print `Yes`; otherwise, print `No`.

Examples

Input

azzel
apple


Output

Yes


Input

chokudai
redcoder


Output

No


Input

abcdefghijklmnopqrstuvwxyz
ibyhqfrekavclxjstdwgpzmonu


Output

Yes