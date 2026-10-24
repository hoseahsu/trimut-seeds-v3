Rhezo and his friend Vanya love problem solving. They have a problem set containing N problems, with points assigned to each. Rhezo wants to solve problems in such a way that he gets the maximum number of points. Rhezo has a weird habit of solving only prime number of consecutive problems, that is, if he solves X consecutive problems from the problem set, then X should be prime. Vanya has already solved all problems from the problem set and he wonders how much maximum points Rhezo can get. Vanya can answer this, but can you?

Input:

First line contains a single integer N, denoting the number of problems in the problem set. Next line contains N space separated integers denoting the points assigned to the problems.

Output:

Print a single integer, the maximum points Rhezo can get.

Constraints:

1 ≤ N ≤ 5000

1 ≤ Points of Problems ≤ 10^5

SAMPLE INPUT
4
8 1 3 7

SAMPLE OUTPUT
12

Explanation

Rhezo will solve problems 1, 2 and 3, and will get 12 points. Note that, he cannot solve all the problems because then he will solve 4(non-prime) consecutive problems.