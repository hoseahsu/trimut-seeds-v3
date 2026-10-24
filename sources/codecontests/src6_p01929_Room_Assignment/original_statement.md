Hey!

There is a new building with N + 1 rooms lined up in a row. Each room is a residence for one person, and all rooms are currently vacant, but N new people are scheduled to live here from next month. Therefore, when they start living, one room becomes vacant.

As a landlord, you want to propose many room allocations that suit their tastes. Here, the room allocation is a table that gives which room each person lives in. For example, when N = 3, "the first person is in room 4, the second person is in room 1, and the third person is in room 2".

Of course, it would be quick to propose all possible room allocations, but that would be meaningless, so some restrictions would be set in consideration of the time and effort of the landlord and the tastes of the residents.

First, after they start living in one of the proposed room allocations, they may be told, "I want to change to another proposed room allocation." The building is new and they know they prefer a new room with no one in it yet, so a different room allocation was suggested by simply moving one person to a vacant room. This can only happen if you can change it to. However, as a landlord, I want to avoid such troubles, so I would like to adjust the proposed room allocation so that such changes are not allowed. In other words, the proposed set of room allocations must satisfy the following. "For any two different proposed room allocations A and B, moving one person to a vacant room in room allocation A does not result in room allocation B."

Next, we know that each of the N people who will live in the future has exactly one preferred person. Therefore, all the proposed room allocations should be such that people who are preferable to all people live next to each other.

What is the maximum size of a set of room allocations that satisfy these conditions? Find the remainder divided by 1,000,000,007.

Input

The input consists of multiple datasets. Each dataset is represented in the following format.

> N
> a1 a2 ... aN
>

The first line of the dataset is given the integer N, which represents the number of people who will live in the building next month. This satisfies 2 ≤ N ≤ 100,000. The second line gives information on the number ai of the person who prefers to live in the next room for the i-th person. For this, 1 ≤ ai ≤ N and ai ≠ i are satisfied. Also, the number of datasets does not exceed 50. The end of the input is represented by a line consisting of only one zero.

> ### Output

For each data set, output the remainder of dividing the maximum number of room allocations that can be proposed at the same time by 1,000,000,007 in one line, as shown in the problem statement.

Sample Input


2
twenty one
3
3 1 2
Ten
2 1 1 1 1 1 1 1 1 1
8
2 1 4 3 3 7 6 6
twenty five
2 3 2 5 4 5 8 7 8 11 10 13 12 15 14 17 16 19 18 21 20 23 22 25 24
Ten
2 1 4 3 6 5 8 7 10 9
0



Output for Sample Input


2
0
0
144
633544712
11520





Example

Input

2
2 1
3
3 1 2
10
2 1 1 1 1 1 1 1 1 1
8
2 1 4 3 3 7 6 6
25
2 3 2 5 4 5 8 7 8 11 10 13 12 15 14 17 16 19 18 21 20 23 22 25 24
10
2 1 4 3 6 5 8 7 10 9
0


Output

2
0
0
144
633544712
11520