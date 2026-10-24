The restaurant AtCoder serves the following five dishes:

* ABC Don (rice bowl): takes A minutes to serve.
* ARC Curry: takes B minutes to serve.
* AGC Pasta: takes C minutes to serve.
* APC Ramen: takes D minutes to serve.
* ATC Hanbagu (hamburger patty): takes E minutes to serve.



Here, the time to serve a dish is the time between when an order is placed and when the dish is delivered.

This restaurant has the following rules on orders:

* An order can only be placed at a time that is a multiple of 10 (time 0, 10, 20, ...).
* Only one dish can be ordered at a time.
* No new order can be placed when an order is already placed and the dish is still not delivered, but a new order can be placed at the exact time when the dish is delivered.



E869120 arrives at this restaurant at time 0. He will order all five dishes. Find the earliest possible time for the last dish to be delivered.
Here, he can order the dishes in any order he likes, and he can place an order already at time 0.

Constraints

* A, B, C, D and E are integers between 1 and 123 (inclusive).

Input

Input is given from Standard Input in the following format:


A
B
C
D
E


Output

Print the earliest possible time for the last dish to be delivered, as an integer.

Examples

Input

29
20
7
35
120


Output

215


Input

101
86
119
108
57


Output

481


Input

123
123
123
123
123


Output

643