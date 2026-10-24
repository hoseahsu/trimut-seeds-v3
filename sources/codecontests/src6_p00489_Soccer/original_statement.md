problem

Soccer is popular in JOI, and a league match called the JOI League is held every week.

There are N teams in the JOI league, numbered from 1 to N. All combinations of matches are played exactly once. In other words, N × (N -1) / 2 games are played. The outcome of each match is determined by the score of each team. The winning team has 3 points and the losing team has 0 points. In the case of a draw, both teams have one point. The ranking is determined by the total points earned by each team, and the difference in points is not considered. Teams with the same total points will be ranked higher.

As an example, consider a league match with four teams. 4 × (4-1) / 2 = 6 Matches will be played. Suppose those results are as shown in the table below. The left side of the hyphen is the score of the team next to it, and the right side is the score of the team vertically.

Team 1 | Team 2 | Team 3 | Team 4 | Wins | Loss | Draws | Points
--- | --- | --- | --- | --- | --- | --- | --- | ---
Team 1 | --- | 0 --1 | 2 --1 | 2 --2 | 1 | 1 | 1 | 4
Team 2 | 1 --0 | --- | 1 --1 | 3 --0 | 2 | 0 | 1 | 7
Team 3 | 1 --2 | 1 --1 | --- | 1 --3 | 0 | 2 | 1 | 1
Team 4 | 2 --2 | 0 --3 | 3 --1 | --- | 1 | 1 | 1 | 4



At this time, Team 2 with the most points is in first place. The teams with the next most points are Team 1 and Team 4, and both teams are in second place. Team 3 with the fewest points is in 4th place.

Create a program to find the ranking of each team given the results of all matches.

input

The number of teams N (2 ≤ N ≤ 100) is written on the first line of the input file. The following N × (N -1) / 2 lines describe the results of each match. The integers Ai, Bi, Ci, Di (1 ≤ Ai ≤ N, 1 ≤ Bi ≤ N, 0 ≤ Ci ≤ 100, 0) are in the first line (1 ≤ i ≤ N x (N-1) / 2). ≤ Di ≤ 100) is written with a blank as a delimiter, indicating that Team Ai and Team Bi played against each other, and Team Ai scored Ci points and Team Bi scored Di points. Ai ≠ Bi for all i, and the same combination of matches is never written.

output

The output consists of N lines. Each row consists of one integer, and the integer on the i-th row (1 ≤ i ≤ N) represents the rank of team i.

Input / output example

Input example 1


Four
1 2 0 1
1 3 2 1
1 4 2 2
2 3 1 1
2 4 3 0
3 4 1 3


Output example 1


2
1
Four
2


Input / output example 1 corresponds to the example in the problem statement.

Input example 2


Five
1 2 1 1
3 4 3 1
5 1 1 2
2 3 0 0
4 5 2 3
1 3 0 2
5 2 2 2
4 1 4 5
3 5 4 0
2 4 0 1


Output example 2


2
Four
1
Four
3


The results of input / output example 2 are as follows.

| Wins | Loss | Draws | Points
--- | --- | --- | --- | ---
Team 1 | 2 | 1 | 1 | 7
Team 2 | 0 | 1 | 3 | 3
Team 3 | 3 | 0 | 1 | 10
Team 4 | 1 | 3 | 0 | 3
Team 5 | 1 | 2 | 1 | 4



The question text and the data used for the automatic referee are the question text and the test data for scoring, which are created and published by the Japan Committee for Information Olympics.





Example

Input

4
1 2 0 1
1 3 2 1
1 4 2 2
2 3 1 1
2 4 3 0
3 4 1 3


Output

2
1
4
2