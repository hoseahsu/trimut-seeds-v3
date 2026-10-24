Problem C: Seishun 18 Kippu

A student at R University, sirokurostone, was about to attend a training camp at Atsu University. Other members plan to use the Shinkansen, but sirokurostone was going to use the Seishun 18 Ticket. Similarly, a person who likes 2D with a youth 18 ticket was also trying to participate in the training camp.

Sirokurostone, who wanted to go with him anyway, decided to pick up him who likes 2D at the station on the way. sirokurostone wants to check the delay situation before leaving R University and take a route that takes less time to reach the station where Atsu University is located. sirokurostone intends to give that information to him who likes 2D after the route is confirmed. However, sirokurostone is in trouble because he does not know which route to take to reach the station where Atsu University is located sooner even if he sees the delay situation.

So your job is to find out how long it will take to get to the station where Atsu University is located on behalf of sirokurostone from the delay situation.

Between each station, there is a distance between stations and an estimated delay time. The train shall maintain 40km / h after it starts moving. The travel time between points a and b is

* Distance / 40+ estimated delay time

Can be obtained at. The stop time at each station can be ignored.

Input

A sequence of multiple datasets is given as input. The number of datasets is guaranteed to be 50 or less. Each dataset has the following format:


n m
s p g
a1 b1 d1 t1
...
ai bi di ti
...
am bm dm tm


The integers n (3 ≤ n ≤ 500) and m (2 ≤ m ≤ 5000) represent the total number of stations and the number of tracks between each station, respectively. s, p, and g are character strings that indicate the location of the station where sirokurostone rides, the station where a person who likes 2D rides, and the station where Atsu University is located, respectively. s, p, and g are different character strings.

The following m line represents the information between stations. ai and bi are character strings indicating stations connected by railroad tracks. ai and bi can go back and forth in both directions. ai and bi never match. The integer di (40 ≤ di ≤ 10000) represents the distance between ai and bi. di is guaranteed to be a multiple of 40. The integer ti (0 ≤ ti ≤ 20) indicates the estimated delay time between ai and bi.

The character string representing the station name is represented by a character string of 20 characters or less consisting of all lowercase and uppercase letters of the alphabet. There is at most one track between stations.

The end of the input is represented by a line containing two zeros.

Output

For each input dataset, output the arrival time (unit: time) to the station where Atsu University is located. It is guaranteed that there is a route from the station where sirokurostone rides to the station where 2D lovers ride, and a route from the station where 2D lovers ride to the station where Atsu University is located.

Sample Input


4 4
A B G
A B 40 3
B C 80 0
A G 40 0
B G 80 0
5 6
Kusatsu Tokyo Aizu
Tokyo Nagoya 120 3
Kusatsu Nagoya 40 0
Kusatsu Kanazawa 40 0
Kanazawa Aizu 40 0
Tokyo Kanazawa 40 0
Tokyo Aizu 80 4
0 0



Output for Sample Input


Five
Four






Example

Input

4 4
A B G
A B 40 3
B C 80 0
A G 40 0
B G 80 0
5 6
Kusatsu Tokyo Aizu
Tokyo Nagoya 120 3
Kusatsu Nagoya 40 0
Kusatsu Kanazawa 40 0
Kanazawa Aizu 40 0
Tokyo Kanazawa 40 0
Tokyo Aizu 80 4
0 0


Output

5
4