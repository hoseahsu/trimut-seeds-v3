We have N integers. The i-th integer is A_i.

Find \sum_{i=1}^{N-1}\sum_{j=i+1}^{N} (A_i \mbox{ XOR } A_j), modulo (10^9+7).

What is \mbox{ XOR }?

The XOR of integers A and B, A \mbox{ XOR } B, is defined as follows:

* When A \mbox{ XOR } B is written in base two, the digit in the 2^k's place (k \geq 0) is 1 if either A or B, but not both, has 1 in the 2^k's place, and 0 otherwise.

For example, 3 \mbox{ XOR } 5 = 6. (In base two: 011 \mbox{ XOR } 101 = 110.)

Constraints

* 2 \leq N \leq 3 \times 10^5
* 0 \leq A_i < 2^{60}
* All values in input are integers.

Input

Input is given from Standard Input in the following format:


N
A_1 A_2 ... A_N


Output

Print the value \sum_{i=1}^{N-1}\sum_{j=i+1}^{N} (A_i \mbox{ XOR } A_j), modulo (10^9+7).

Examples

Input

3
1 2 3


Output

6


Input

10
3 1 4 1 5 9 2 6 5 3


Output

237


Input

10
3 14 159 2653 58979 323846 2643383 27950288 419716939 9375105820


Output

103715602