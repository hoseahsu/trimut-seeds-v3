There is a frog known as "CHAMELEON" because he has a special feature to change its body's color similar to stone's color on which he sits. There are N colorful stones lying in a row, but of only 1 to 100 different colors. Frog can hopp on another stone if the stone has same color as its body or (i-1)th stone if it is currently on ith stone. Frog needs to hopp from position 'S' to 'E' via 'M'. Finds the minimum no. of jumps he needs to take to reach E from S via M.

INPUT:

First line contain a integer N. Next line contain N stones(0- based index) each ith stone is denoted by a number which is color of the stone.
Next line contain Q (no. of queries). Each query contain S,M,E.

3 ≤ N ≤ 10^5.

1 ≤ Q ≤ 50

0 ≤ S,M,E<N 

OUTPUT:

Answer of each query. Print -1 if it will not able to reach the destination point.

SAMPLE INPUT
6
2 3 1 3 2 4
2
1 0 4
2 3 5

SAMPLE OUTPUT
2
-1