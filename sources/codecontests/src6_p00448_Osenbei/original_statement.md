problem

At IOI Confectionery, rice crackers are baked using the traditional method since the company was founded. This traditional method is to bake the front side for a certain period of time with charcoal, turn it over when the front side is baked, and bake the back side for a certain period of time with charcoal. While keeping this tradition, rice crackers are baked by machine. This machine arranges and bake rice crackers in a rectangular shape with vertical R (1 ≤ R ≤ 10) rows and horizontal C (1 ≤ C ≤ 10000) columns. Normally, it is an automatic operation, and when the front side is baked, the rice crackers are turned over and the back side is baked all at once.

One day, when I was baking rice crackers, an earthquake occurred just before turning over the rice crackers, and some rice crackers turned over. Fortunately, the condition of the charcoal fire remained appropriate, but if the front side was baked any more, the baking time set by the tradition since the establishment would be exceeded, and the front side of the rice cracker would be overcooked and could not be shipped as a product. .. Therefore, I hurriedly changed the machine to manual operation and tried to turn over only the rice crackers that had not been turned inside out. This machine can turn over several horizontal rows at the same time and several vertical columns at the same time, but unfortunately it cannot turn over rice crackers one by one.

If it takes time to turn it over, the front side of the rice cracker that was not turned over due to the earthquake will be overcooked and cannot be shipped as a product. Therefore, we decided to increase the number of rice crackers that can be baked on both sides without overcooking the front side, that is, the number of "rice crackers that can be shipped". Consider the case where no horizontal rows are flipped, or no vertical columns are flipped. Write a program that outputs the maximum number of rice crackers that can be shipped.

Immediately after the earthquake, the rice crackers are in the state shown in the following figure. The black circles represent the state where the front side is burnt, and the white circles represent the state where the back side is burnt.

<image>

If you turn the first line over, you will see the state shown in the following figure.

<image>

Furthermore, when the 1st and 5th columns are turned over, the state is as shown in the following figure. In this state, 9 rice crackers can be shipped.

<image>



input

The input consists of multiple datasets. Each dataset is given in the following format.

Two integers R and C (1 ≤ R ≤ 10, 1 ≤ C ≤ 10 000) are written on the first line of the input, separated by blanks. The following R line represents the state of the rice cracker immediately after the earthquake. In the (i + 1) line (1 ≤ i ≤ R), C integers ai, 1, ai, 2, ……, ai, C are written separated by blanks, and ai, j are i. It represents the state of the rice cracker in row j. If ai and j are 1, it means that the front side is burnt, and if it is 0, it means that the back side is burnt.

When both C and R are 0, it indicates the end of input. The number of data sets does not exceed 5.

output

For each data set, the maximum number of rice crackers that can be shipped is output on one line.

Examples

Input

2 5
0 1 0 1 0
1 0 0 0 1
3 6
1 0 0 0 1 0
1 1 1 0 1 0
1 0 1 1 0 1
0 0


Output

9
15


Input

None


Output

None