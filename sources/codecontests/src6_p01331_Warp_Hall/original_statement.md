In 20XX, an efficient material transfer method was established for distant places, and human beings' advance into space was accelerated more and more. This transfer method was innovative in that, in principle, larger substances could be transferred when trying to transfer the substance farther. The details of the transfer method are described below.

First, the substance to be transferred is divided into particles for each unit mass at the start coordinates (1, 1). Each particle must be given a different wave energy. Wave energy is represented by a character string of arbitrary length consisting of V and H, and defines how particles drift in outer space. V means the movement on the coordinates (+1, 0), and H means the movement of (0, +1). For example, a particle given wave energy called VHHV drifts in the universe on the trajectories (2, 1), (2, 2), (2, 3) and then reaches the coordinates (3, 3).

In addition, there are multiple warp holes in outer space, which affect the trajectory of particles. The warp hole has an entrance and an exit, and when a particle moves to the entrance of the warp hole, it always warps to the coordinates of the exit. If the coordinates of the entrance and exit of the i-th warp hole are (ai, bi), (ci, di), the condition ai ≤ ci, bi ≤ di, (ai, bi) ≠ (ci, di) is satisfied. It is guaranteed that the entrance to the warp hole does not exist at the same coordinates as the entrance to other warp holes or at (1, 1). However, there may be multiple exits in the same location, or one warp hole exit may have another warp hole entrance (in this case, warp consecutively).

For example, if there is a warp hole with (1, 2) as the inlet and (3, 2) as the exit, the particles given HH and wave energy move to (1, 2) and then (3, 2). Warp to 2) and reach (3, 3).

When particles are given wave energy, they move according to it in an instant. When all the particles reach the destination at the same time, they are automatically reconstructed into the original substance.

You are a programmer of Japan Aerospace Exploration Agency. Since the target coordinates (N, M) of the transfer and the coordinate pairs of K warp holes are given, please write a program to find the maximum mass of the substance that can be transferred at one time. The answer can be very large, so print the remainder divided by 1,000,000,007.

Notes on Test Cases

Multiple datasets are given in the above input format. Create a program that outputs each data set in the above output format.

When N, M, K are all 0, it indicates the end of input.

<!-



Input


NMK
a1 b1 c1 d1
...
aK bK cK dK

Satisfy 1 ≤ N, M ≤ 105, 0 ≤ K ≤ 103. Also, for any 1 ≤ i ≤ K, ai ≤ ci, bi ≤ di, (ai, bi) ≠ (ci, di) is satisfied.

Output

Divide the maximum mass by 1,000,000,007 and output the remainder in one line.

Examples

Input

4 4 1
2 2 3 3
1 4 1
1 2 1 3
5 5 2
2 2 3 4
3 3 5 3
5 5 3
4 4 5 5
2 2 3 3
3 3 4 4
100000 100000 1
2 2 99999 99999
1 1 0
0 0 0


Output

12
1
26
18
615667476
1


Input

4 4 1
2 2 3 3


Output

12


Input

1 4 1
1 2 1 3


Output

1


Input

5 5 2
2 2 3 4
3 3 5 3


Output

26


Input

5 5 3
4 4 5 5
2 2 3 3
3 3 4 4


Output

18


Input

100000 100000 1
2 2 99999 99999


Output

615667476


Input

1 1 0


Output

1