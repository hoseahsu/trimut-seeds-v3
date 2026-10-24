Beakers of various capacities are given. First, choose one of the largest beakers and pour it through the faucet until it is full. Next, transfer the water from the beaker to another beaker according to the following rules.

* All water in the beaker must be transferred to another beaker without leaving. However, if it is not possible to transfer all the water to one beaker, it may be divided into multiple beakers.
* When you fill the beaker with water, you must pour water until it is full. Also, do not spill water.
* Do not pour water from multiple beakers into the same beaker at once.
* Only water the same beaker once.

<image>



When following this rule, create a program that inputs the number of beakers n and the capacity of each beaker, determines whether water can be poured into all beakers, and outputs it. Output YES (half-width uppercase letters) when water can be poured into all beakers, and NO (half-width uppercase letters) when water cannot be poured.



Input

A sequence of multiple datasets is given as input. The end of the input is indicated by a single line of zeros. Each dataset is given in the following format:


n
c1 c2 ... cn


The number of beakers n (1 ≤ n ≤ 50) is given on the first line. The second line is given the integer ci (1 ≤ ci ≤ 100), which represents the capacity of the i-th beaker.

The number of datasets does not exceed 105.

Output

The judgment result is output to one line for each data set.

Example

Input

10
11 2 23 4 2 12 8 5 2 10
8
2 1 3 11 2 3 1 4
9
5 9 1 2 4 8 17 1 8
8
3 38 9 4 18 14 19 5
1
1
0


Output

YES
YES
YES
NO
YES