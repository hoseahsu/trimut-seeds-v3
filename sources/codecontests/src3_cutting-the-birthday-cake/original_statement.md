Its Alice's birthday and her friend Bob gets him a birthday cake. Its nice delicious circle shaped cake of radius  R. Now they need to cut and eat that cake, so Alice fetches a cutter from her kitchen. It is a rectangular cutter of length A and breadth B that would knock of the part of the cake when the cutter is placed over it.

They decided to take turns to cut and eat their cake. Because it is Alice's birthday, she starts first. In each turn, they place the cutter over the cake, such that it is fully over the cake (i.e., no part of the cutter is outside the cake, or even over some previously cut region of the cake). You need to determine who will get more to eat, given both of them will use the optimal strategies.

Input and Output
The first line will contain the number of test cases T. Each of the next T lines will contain three space separated numbers R A B.

For each test case, you need to determine who will eat more. Print on a line "ALICE", "BOB" or "EQUAL" accordingly.

Constraints
1 ≤ T, R, A, B ≤ 1000

SAMPLE INPUT
2
1 2 2
1 1 1

SAMPLE OUTPUT
EQUAL
ALICE

Explanation
The cutter is bigger than the cake, hence nothing can be cut out.
Only one piece can be cut out from the cake. Hence Alice wins.