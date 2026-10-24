Suppose that there are some light sources and many spherical balloons. All light sources have sizes small enough to be modeled as point light sources, and they emit light in all directions. The surfaces of the balloons absorb light and do not reflect light. Surprisingly in this world, balloons may overlap.

You want the total illumination intensity at an objective point as high as possible. For this purpose, some of the balloons obstructing lights can be removed. Because of the removal costs, however, there is a certain limit on the number of balloons to be removed. Thus, you would like to remove an appropriate set of balloons so as to maximize the illumination intensity at the objective point.

The following figure illustrates the configuration specified in the first dataset of the sample input given below. The figure shows the xy-plane, which is enough because, in this dataset, the z-coordinates of all the light sources, balloon centers, and the objective point are zero. In the figure, light sources are shown as stars and balloons as circles. The objective point is at the origin, and you may remove up to 4 balloons. In this case, the dashed circles in the figure correspond to the balloons to be removed.

<image>

Figure G.1: First dataset of the sample input.



Input

The input is a sequence of datasets. Each dataset is formatted as follows.

N M R
S1x S1y S1z S1r
...
SNx SNy SNz SNr
T1x T1y T1z T1b
...
TMx TMy TMz TMb
Ex Ey Ez


The first line of a dataset contains three positive integers, N, M and R, separated by a single space. N means the number of balloons that does not exceed 2000. M means the number of light sources that does not exceed 15. R means the number of balloons that may be removed, which does not exceed N.

Each of the N lines following the first line contains four integers separated by a single space. (Six, Siy, Siz) means the center position of the i-th balloon and Sir means its radius.

Each of the following M lines contains four integers separated by a single space. (Tjx, Tjy, Tjz) means the position of the j-th light source and Tjb means its brightness.

The last line of a dataset contains three integers separated by a single space. (Ex, Ey, Ez) means the position of the objective point.

Six, Siy, Siz, Tjx, Tjy, Tjz, Ex, Ey and Ez are greater than -500, and less than 500. Sir is greater than 0, and less than 500. Tjb is greater than 0, and less than 80000.

At the objective point, the intensity of the light from the j-th light source is in inverse proportion to the square of the distance, namely

Tjb / { (Tjx − Ex)2 + (Tjy − Ey)2 + (Tjz − Ez)2 },

if there is no balloon interrupting the light. The total illumination intensity is the sum of the above.

You may assume the following.

1. The distance between the objective point and any light source is not less than 1.
2. For every i and j, even if Sir changes by ε (|ε| < 0.01), whether the i-th balloon hides the j-th light or not does not change.


The end of the input is indicated by a line of three zeros.

Output

For each dataset, output a line containing a decimal fraction which means the highest possible illumination intensity at the objective point after removing R balloons. The output should not contain an error greater than 0.0001.

Example

Input

12 5 4
0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 -1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1
0 10 0 240
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2
0 0 0
12 5 4
0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 -1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1
0 10 0 260
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2
0 0 0
5 1 3
1 2 0 2
-1 8 -1 8
-2 -3 5 6
-2 1 3 3
-4 2 3 5
1 1 2 7
0 0 0
5 1 2
1 2 0 2
-1 8 -1 8
-2 -3 5 6
-2 1 3 3
-4 2 3 5
1 1 2 7
0 0 0
0 0 0


Output

3.5
3.6
1.1666666666666667
0.0