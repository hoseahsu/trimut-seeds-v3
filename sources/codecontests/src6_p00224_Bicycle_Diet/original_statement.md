Mr. A loves sweets, but recently his wife has told him to go on a diet. One day, when Mr. A went out from his home to the city hall, his wife recommended that he go by bicycle. There, Mr. A reluctantly went out on a bicycle, but Mr. A, who likes sweets, came up with the idea of ​​stopping by a cake shop on the way to eat cake.

If you ride a bicycle, calories are consumed according to the mileage, but if you eat cake, you will consume that much calories. The net calories burned is the calories burned on the bike minus the calories burned by eating the cake. Therefore, the net calories burned may be less than zero.

If you buy a cake at a cake shop, Mr. A will eat all the cake on the spot. Mr. A does not stop at all cake shops, but when he passes through the point where the cake shop exists, he always stops and buys and eats one cake. However, it's really tempting to pass in front of the same cake shop many times, so each cake shop should only be visited once. In addition, you may stop by the cake shop after passing the destination city hall, and then return to the city hall to finish your work, and you may visit as many times as you like except the cake shop.

Enter the map information from Mr. A's home to the city hall, a list of calories of cakes that can be eaten at the cake shop on the way, and the calories burned by traveling a unit distance, from leaving home to entering the city hall. Create a program that outputs the minimum net calories burned.

The map shows Mr. A's home and city hall, a cake shop and a landmark building. The input data representing the map contains a line consisting of a symbol representing the two points and the distance between them, when there is a road connecting Mr. A's home, city hall, cake shop and each point of the landmark. For example, if the distance between the 5th cake shop and the 3rd landmark is 10, the input data will contain a line similar to the following:


C5 L3 10


In this way, cake shops are represented by C, and landmarks are represented by L in front of the number. Also, Mr. A's home is represented by H and the city hall is represented by D. If the input data is given two points and the distance between them, advance between the two points in either direction. For example, in the example above, you can go from a cake shop to a landmark and vice versa. In addition, you must be able to reach the city hall from your home. Other input data given are the number of cake shops m, the number of landmarks n, the calories burned per unit distance k, and the cakes that can be bought at each of the first cake shop to the mth cake shop. The total number of m data representing calories and distance data d.



Input

A sequence of multiple datasets is given as input. The end of the input is indicated by four 0 lines. Each dataset is given in the following format:


m n k d
c1 c2 ... cm
s1 t1 e1
s2 t2 e2
::
sd td ed


Number of cake shops m (1 ≤ m ≤ 6), number of landmarks n (1 ≤ n ≤ 100), calories burned per unit distance k (1 ≤ k ≤ 5), distance data on the first line The total number d (5 ≤ d ≤ 256) is given.

The second line gives the calories ci (1 ≤ ci ≤ 100) of the cake you buy at each cake shop.

The following d line is given the distance data si, ti, ei (1 ≤ ei ≤ 20) between the i-th two points.

The number of datasets does not exceed 100.

Output

Outputs the minimum total calories burned on one line for each input dataset.

Example

Input

1 1 2 5
35
H L1 5
C1 D 6
C1 H 12
L1 D 10
C1 L1 20
2 1 4 6
100 70
H L1 5
C1 L1 12
C1 D 11
C2 L1 7
C2 D 15
L1 D 8
0 0 0 0


Output

1
-2