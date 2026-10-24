There are N boxes .The i^th box contains ai candies . The frog Om Nom is sitting in box number 1 .Om Nom wants to collect as many candies as he can . However , Om Nom jumps in a peculiar fashion . Om Nom can jump from box number j to box number i only if j | i (j divides i) . Whenever Om Nom lands in a box , he collects all the candies in that box. You have to report the maximum number of Candies that Om Nom can collect for all i from 1 to N if i is the last box that Om Nom visits.See the samples for more details.    

Constraints
0 ≤ ai ≤ 100000
1 ≤ N ≤ 100000   

Input
The first line contains the number N.
The second line contains the array a , the i^th integer denoting the number of candies in the i^th box.  

Output
Print N integers-the i^th integer should be the maximum number of candies that Om Nom can collect if the i^th box is his final box (i.e his sequence of jumps ends at i).  

SAMPLE INPUT
5
2 3 1 4 6

SAMPLE OUTPUT
2 5 3 9 8

Explanation

For i=1,Om Nom stops at box number 1 itself and so he can collect only 2 candies.
For i=2,the sequence of jumps is 1 2(array indices)
For i=3,the sequence of jumps is 1 3
For i=4,the sequence of jumps is 1 2 4
For i=5,the sequence of jumps is 1 5