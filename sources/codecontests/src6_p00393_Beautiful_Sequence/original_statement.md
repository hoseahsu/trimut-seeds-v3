Alice is spending his time on an independent study to apply to the Nationwide Mathematics Contest. This year’s theme is "Beautiful Sequence." As Alice is interested in the working of computers, she wants to create a beautiful sequence using only 0 and 1. She defines a "Beautiful" sequence of length $N$ that consists only of 0 and 1 if it includes $M$ successive array of 1s as its sub-sequence.

Using his skills in programming, Alice decided to calculate how many "Beautiful sequences" she can generate and compile a report on it.

Make a program to evaluate the possible number of "Beautiful sequences" given the sequence length $N$ and sub-sequence length $M$ that consists solely of 1. As the answer can be extremely large, divide it by $1,000,000,007 (= 10^9 + 7)$ and output the remainder.



Input

The input is given in the following format.


$N$ $M$


The input line provides the length of sequence $N$ ($1 \leq N \leq 10^5$) and the length $M$ ($1 \leq M \leq N$) of the array that solely consists of 1s.

Output

Output the number of Beautiful sequences in a line.

Examples

Input

4 3


Output

3


Input

4 2


Output

8