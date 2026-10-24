There are N stones arranged in a row. Every stone is painted white or black. A string S represents the color of the stones. The i-th stone from the left is white if the i-th character of S is `.`, and the stone is black if the character is `#`.

Takahashi wants to change the colors of some stones to black or white so that there will be no white stone immediately to the right of a black stone. Find the minimum number of stones that needs to be recolored.

Constraints

* 1 \leq N \leq 2\times 10^5
* S is a string of length N consisting of `.` and `#`.

Input

Input is given from Standard Input in the following format:


N
S


Output

Print the minimum number of stones that needs to be recolored.

Examples

Input

3
#.#


Output

1


Input

3
.#


Output

1


Input

5
.##.


Output

2


Input

9
.........


Output

0