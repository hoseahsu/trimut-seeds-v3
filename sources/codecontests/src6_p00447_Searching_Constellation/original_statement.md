problem

You are looking for a constellation in a picture of the starry sky. The photo always contains exactly one figure with the same shape, orientation, and size as the constellation you are looking for. However, there is a possibility that extra stars are shown in the photograph other than the stars that make up the constellation.

For example, the constellations in Figure 1 are included in the photo in Figure 2 (circled). If you translate the coordinates of a star in a given constellation by 2 in the x direction and −3 in the y direction, it will be the position in the photo.

Given the shape of the constellation you want to look for and the position of the star in the picture, write a program that answers the amount to translate to convert the coordinates of the constellation to the coordinates in the picture.

<image> | <image>
--- | ---
Figure 1: The constellation you want to find | Figure 2: Photograph of the starry sky




input

The input consists of multiple datasets. Each dataset is given in the following format.

The first line of the input contains the number of stars m that make up the constellation you want to find. In the following m line, the integers indicating the x and y coordinates of the m stars that make up the constellation you want to search for are written separated by blanks. The number n of stars in the photo is written on the m + 2 line. In the following n lines, the integers indicating the x and y coordinates of the n stars in the photo are written separated by blanks.

The positions of the m stars that make up the constellation are all different. Also, the positions of the n stars in the picture are all different. 1 ≤ m ≤ 200, 1 ≤ n ≤ 1000. The x and y coordinates of a star are all 0 or more and 1000000 or less.

When m is 0, it indicates the end of input. The number of datasets does not exceed 5.

output

The output of each dataset consists of one line, with two integers separated by blanks. These show how much the coordinates of the constellation you want to find should be translated to become the coordinates in the photo. The first integer is the amount to translate in the x direction, and the second integer is the amount to translate in the y direction.

Examples

Input

5
8 5
6 4
4 3
7 10
0 10
10
10 5
2 7
9 7
8 10
10 2
1 2
8 1
6 7
6 0
0 9
5
904207 809784
845370 244806
499091 59863
638406 182509
435076 362268
10
757559 866424
114810 239537
519926 989458
461089 424480
674361 448440
81851 150384
459107 795405
299682 6700
254125 362183
50795 541942
0


Output

2 -3
-384281 179674


Input

None


Output

None