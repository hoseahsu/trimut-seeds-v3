The University of Aizu Elementary School (Aizu University and Small) is famous as one of Japan's leading competition programmer training schools. Of course, it is essential to practice the algorithm even when attending an athletic meet.

Of course you, the director of the competitive programming department, want to win this tournament as well. This time we will focus on a certain competition.

A certain competition is a traditional competition held in Aizu, large and small. There are n cones in the schoolyard. Four colors of corn are available. Several pairs of cones are connected by arrows drawn with white lines. The arrow is attached to only one side, and an integer is also written.

Athletes act as a team of k people. Move in that direction from the cone at the starting point to the cone at the goal point on the arrow. However, each k person needs to have a different route to the goal point.

The fact that route 1 and route 2 are different means that

* Condition 1 If the number of arrows that pass through Route 1 and Route 2 is the same, there must be an i that has a different arrow that goes through the i-th in Route 1 and the arrow that goes through in the i-th in Route 2.
* Condition 2 The number of arrows passing through Route 1 and Route 2 is different.



It can be said that the route is different if any of the above is satisfied.

In addition, there is a prohibited color pattern in how to follow the cone, and players who include that pattern on the route from the start point to the goal point will be retired. However, other routes may follow any route, and may pass through the same cone (including the cone at the start point and the goal point) many times. In addition, the numbers written along with the arrows are added as scores. The competition is won by the team with more teammates reaching the goal cone with a smaller total score.

You, the director, should of course be able to solve this problem with programming. Find the maximum number of people who can move to the goal. Also, find the minimum score when you reach the maximum number of people.

However, if you can reduce the score as much as you want, output -1.



Input

The input consists of multiple test cases. The number of test cases does not exceed 20.


n
col1
col2
...
coln
m
a1 b1 c1
a2 b2 c2
...
am bm cm
k
pattern


n (2 ≤ n ≤ 100) represents the number of cones. coli (1 ≤ coli ≤ 4) indicates the color of the i-th cone. m (0 ≤ m ≤ 1,000) represents the number of arrows. ai is the number of the cone at the start of the arrow, bi is the number of the cone at the end, and ci is the score of the arrow. Also, up to 10 arrows can extend from one cone. (1 ≤ ai, bi ≤ n, -1,000 ≤ ci ≤ 1,000) k indicates the number of teams competing. (1 ≤ k ≤ 10) pattern is a character string consisting of numbers 1 to 4 with a length of 10 or less, and indicates a pattern in which movement is prohibited. The starting cone is the first cone and the nth cone is the goal. The numbers given in the input (n, col, m, a, b, c, k) are all integers. The end of the input is indicated by one line containing 0.

Output

The output consists of two integers separated by blanks. The first is the number of people that can be reached, and the second is its minimum cost. If you can reduce the score as much as you want, output one line containing only -1. If no one can reach it, output 0 0.

Example

Input

2
1
1
2
1 2 1
2 1 1
1
1111
2
1
1
2
1 2 1
2 1 1
1
11
2
1
1
2
1 2 1
2 1 1
10
1111
2
1
1
2
1 2 1
2 1 1
10
111111
2
1
1
2
1 2 -1
2 1 0
10
11
2
1
1
2
1 2 -1
2 1 0
10
1111
2
1
1
2
1 2 -1
2 1 0
10
12
2
1
1
2
1 2 -1
2 1 0
10
1111111111
0


Output

1 1
0 0
1 1
2 4
0 0
1 -1
-1
4 -10