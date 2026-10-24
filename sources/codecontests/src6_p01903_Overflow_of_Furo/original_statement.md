F: Bath overflows --Overflow of Furo -

story

The hot spring inn Paro is passionate about the hot springs that it is proud of, and is attracting professional bathers. Bath professionals mainly manage the plumbing of hot springs, and manage and coordinate the complicated and intricate plumbing network that connects multiple sources to one large communal bath.

The management and adjustment work of the piping network is also quite difficult, but the bath professionals sewn in between and made efforts every day to supply more hot water to the bathtub. As a result, bath professionals have mastered the trick of "only one pipe can be overflowed." In other words, it became possible to freely choose one pipe and remove the limitation on the amount of hot water in that pipe.

Bath professionals who have previously relied on your program to set up a plumbing network to achieve maximum hot water can reprogram to you how to use this technology to further increase the amount of hot water supplied to the bathtub. I asked you to write.

problem

There is a plumbing network with one bathtub, K sources and N junctions. The piping network consists of M pipes, and each pipe has a limit on the amount of hot water that can be flowed. Since the direction in which hot water flows is not determined for each pipe, you can freely decide and use it. At the N coupling points, the hot water flowing from some pipes can be freely distributed to some other pipes. All sources and bathtubs are at the end points of some pipes, and hot water is supplied from the source to the bathtub by adjusting the amount of hot water from the source and the amount of hot water at the joint point.

What is the maximum amount of hot water that can be supplied to the bathtub by overflowing only one of the M pipes, that is, increasing the amount of hot water that can be flowed infinitely? However, it is possible that the maximum amount of hot water supplied can be increased infinitely, but in that case the bath will overflow, so output "overfuro".

Input format

The input is given in the following format.


K N M
a_1 b_1 c_1
...
a_M b_M c_M


All inputs consist of integers. The first row gives the number of sources K, the number of coupling points N, and the number of pipes M. In the i-th line of the following M lines, three integers a_i, b_i, and c_i representing the information of the i-th pipe are given. This indicates that the points at both ends of the i-th pipe are a_i and b_i, respectively, and the limit on the amount of hot water is c_i. Here, when the end point x of the pipe is 0, it means that it is a large communal bath, when it is from 1 to K, it means that it is the xth source, and when it is from K + 1 to K + N, it means that it is the x − Kth connection point. ..

Constraint

* 1 ≤ K
* 0 ≤ N
* N + K ≤ 100
* 1 ≤ M ≤ (N + K + 1) (N + K) / 2
* 0 ≤ a_i, b_i ≤ K + N
* a_i ≠ b_i
* 1 ≤ c_i ≤ 5 {,} 000
* It is guaranteed that no more than one pipe has the same two endpoints.
* The given plumbing network is guaranteed to be able to supply at least one hot water from the source to the bathtub without overflowing the plumbing.



Output format

Output the maximum amount of hot water supplied from the source to the bathtub in one line when only one pipe overflows and the amount of hot water supplied from the source to the bathtub is maximized. However, if you can increase the maximum amount of hot water infinitely, output "overfuro" on one line.

Input example 1


2 2 4
1 3 4
2 4 2
0 3 3
4 0 5


Output example 1


8

Input example 2


2 3 7
1 0 8
2 0 9
3 0 3
0 4 5
5 0 2
1 3 2
2 4 9


Output example 2


overfuro

Input example 3


1 1 2
0 2 1
1 2 1


Output example 3


1

Input example 4


5 0 5
0 1 1
0 2 1
0 3 1
0 4 1
0 5 1


Output example 4


overfuro





Example

Input

2 2 4
1 3 4
2 4 2
0 3 3
4 0 5


Output

8