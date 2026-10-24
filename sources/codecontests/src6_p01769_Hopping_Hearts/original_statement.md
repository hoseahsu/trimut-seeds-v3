Problem statement

N-winged rabbit is on a balance beam of length L-1. The initial position of the i-th rabbit is the integer x_i, which satisfies 0 ≤ x_ {i} \ lt x_ {i + 1} ≤ L−1. The coordinates increase as you move to the right. Any i-th rabbit can jump to the right (ie, move from x_i to x_i + a_i) any number of times, just a distance a_i. However, you cannot jump over another rabbit or enter a position below -1 or above L. Also, at most one rabbit can jump at the same time, and at most one rabbit can exist at a certain coordinate.

How many possible states of x_ {0},…, x_ {N−1} after starting from the initial state and repeating the jump any number of times? Find by the remainder divided by 1 \, 000 \, 000 \, 007.

input

The input is given in the following format.


N L
x_ {0}… x_ {N−1}
a_ {0}… a_ {N−1}


Constraint

* All inputs are integers
* 1 \ ≤ N \ ≤ 5 \,000
* N \ ≤ L \ ≤ 5 \,000
* 0 \ ≤ x_ {i} \ lt x_ {i + 1} \ ≤ L−1
* 0 \ ≤ a_ {i} \ ≤ L−1



output

Print the answer in one line.

sample

Sample input 1


13
0
1


Sample output 1


3


If 1/0 is used to express the presence / absence of a rabbit, there are three ways: 100, 010, and 001.

Sample input 2


twenty four
0 1
1 2


Sample output 2


Four


There are four ways: 1100, 1001, 0101, 0011.

Sample input 3


10 50
0 1 2 3 4 5 6 7 8 9
1 1 1 1 1 1 1 1 1 1


Sample output 3


272278100


The binomial coefficient C (50,10) = 10 \, 272 \, 278 \, 170, and the remainder obtained by dividing it by 1 \, 000 \, 000 \, 007 is 272 \, 278 \, 100.





Example

Input

1 3
0
1


Output

3