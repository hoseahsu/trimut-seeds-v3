Once upon a time, there was a king who loved beautiful costumes very much. The king had a special cocoon bed to make excellent cloth of silk. The cocoon bed had 16 small square rooms, forming a 4 × 4 lattice, for 16 silkworms. The cocoon bed can be depicted as follows:

<image>

The cocoon bed can be divided into 10 rectangular boards, each of which has 5 slits:

<image>

Note that, except for the slit depth, there is no difference between the left side and the right side of the board (or, between the front and the back); thus, we cannot distinguish a symmetric board from its rotated image as is shown in the following:

<image>

Slits have two kinds of depth, either shallow or deep. The cocoon bed should be constructed by fitting five of the boards vertically and the others horizontally, matching a shallow slit with a deep slit.

Your job is to write a program that calculates the number of possible configurations to make the lattice. You may assume that there is no pair of identical boards. Notice that we are interested in the number of essentially different configurations and therefore you should not count mirror image configurations and rotated configurations separately as different configurations.

The following is an example of mirror image and rotated configurations, showing vertical and horizontal boards separately, where shallow and deep slits are denoted by '1' and '0' respectively.

<image>

Notice that a rotation may exchange position of a vertical board and a horizontal board.



Input

The input consists of multiple data sets, each in a line. A data set gives the patterns of slits of 10 boards used to construct the lattice. The format of a data set is as follows:


XXXXX XXXXX XXXXX XXXXX XXXXX XXXXX XXXXX XXXXX XXXXX XXXXX


Each x is either '0' or '1'. '0' means a deep slit, and '1' a shallow slit. A block of five slit descriptions corresponds to a board. There are 10 blocks of slit descriptions in a line. Two adjacent blocks are separated by a space.

For example, the first data set in the Sample Input means the set of the following 10 boards:

<image>

The end of the input is indicated by a line consisting solely of three characters "END".

Output

For each data set, the number of possible configurations to make the lattice from the given 10 boards should be output, each in a separate line.

Example

Input

10000 01000 00100 11000 01100 11111 01110 11100 10110 11110
10101 01000 00000 11001 01100 11101 01110 11100 10110 11010
END


Output

40
6