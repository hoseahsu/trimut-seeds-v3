Hakone Ekiden is one of the Japanese New Year's traditions. In Hakone Ekiden, 10 runners from each team aim for the goal while connecting the sashes at each relay station. In the TV broadcast, the ranking change from the previous relay station is displayed along with the passing order of each team at the relay station. So, look at it and tell us how many possible passage orders for each team at the previous relay station. The number of possible transit orders can be very large, so answer by the remainder divided by 1,000,000,007.



Input

The input is given in the form:

> n
> c1
> c2
> ...
> cn
>

The number n (1 ≤ n ≤ 200) representing the number of teams is on the first line, and the ranking changes from the previous relay station in order from the first place on the following n lines. If it is'`U`', the ranking is up, if it is'`-`', the ranking is not changed) is written.

Output

Please output in one line by dividing the number of passages that could have been the previous relay station by 1,000,000,007.

Examples

Input

3
-
U
D


Output

1


Input

5
U
U
-
D
D


Output

5


Input

8
U
D
D
D
D
D
D
D


Output

1


Input

10
U
D
U
D
U
D
U
D
U
D


Output

608


Input

2
D
U


Output

0