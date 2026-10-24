Golu is given a task of clearing coins fallen down  on floor. Naughty being his modus operandi, he thought of playing a game while clearing coins. He arranges the coins like an M X N matrix with random heads (1) and tails (0).

In every move, he chooses a sub-matrix of size L X B [such that max(L,B) >1] and interchanges all heads to tails and vice-versa present in the chosen sub-matrix. Then if he finds a 2X2 sub-matrix exclusively of heads anywhere in the M X N matrix, he removes those coins.

Your task is simple. You have to report the minimum no. of moves taken by him before he clears his first 2X2 sub-matrix.

Input:

Your first line of input consists of two numbers M, N. Each of the next M lines consists of N space-separated integers which are either 0 or 1.

Output:

Output a single line answer giving the minimum no. of steps taken before his first clearance. If it is impossible for him to do so, print "-1" (quotes for clarity).

Constraints :

2 ≤ M,N ≤ 10

Author : Srinivas

Testers : Shubham Parekh , Shreyans

(By IIT Kgp HackerEarth Programming Club)

SAMPLE INPUT
2 4
0 0 1 1
0 0 1 1

SAMPLE OUTPUT
0