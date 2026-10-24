One fine day Sasha went to the park for a walk. In the park, he saw that his favorite bench is occupied, and he had to sit down on the neighboring one. He sat down and began to listen to the silence. Suddenly, he got a question: what if in different parts of the park, the silence sounds in different ways? So it was. Let's divide the park into 1 × 1 meter squares and call them cells, and numerate rows from 1 to n from up to down, and columns from 1 to m from left to right. And now, every cell can be described with a pair of two integers (x, y), where x — the number of the row, and y — the number of the column. Sasha knows that the level of silence in the cell (i, j) equals to f_{i,j}, and all f_{i,j} form a permutation of numbers from 1 to n ⋅ m. Sasha decided to count, how many are there pleasant segments of silence?

Let's take some segment [l … r]. Denote S as the set of cells (i, j) that l ≤ f_{i,j} ≤ r. Then, the segment of silence [l … r] is pleasant if there is only one simple path between every pair of cells from S (path can't contain cells, which are not in S). In other words, set S should look like a tree on a plain. Sasha has done this task pretty quickly, and called the algorithm — "algorithm of silence's sounds".

Time passed, and the only thing left from the algorithm is a legend. To prove the truthfulness of this story, you have to help Sasha and to find the number of different pleasant segments of silence. Two segments [l_1 … r_1], [l_2 … r_2] are different, if l_1 ≠ l_2 or r_1 ≠ r_2 or both at the same time.

Input

The first line contains two integers n and m (1 ≤ n, m ≤ 1000, 1 ≤ n ⋅ m ≤ 2 ⋅ 10^5) — the size of the park.

Each from next n lines contains m integers f_{i,j} (1 ≤ f_{i,j} ≤ n ⋅ m) — the level of silence in the cell with number (i, j).

It is guaranteed, that all f_{i,j} are different.

Output

Print one integer — the number of pleasant segments of silence.

Examples

Input

1 5
1 2 3 4 5


Output

15

Input

2 3
1 2 3
4 5 6


Output

15

Input

4 4
4 3 2 16
1 13 14 15
5 7 8 12
6 11 9 10


Output

50

Note

In the first example, all segments of silence are pleasant.

In the second example, pleasant segments of silence are the following:

<image>