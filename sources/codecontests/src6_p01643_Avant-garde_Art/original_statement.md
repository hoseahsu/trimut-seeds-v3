ICPC World Finals Day 6

Russian Constructivism is an art movement in the Soviet Union that began in the mid-1910s. Inspired by such things, Tee, who had been in Country R for a long time, decided to create a cool design despite the rehearsal of the ICPC World Finals. Mr. Tee says: "A circle and a line segment are enough for the symbol. It is important how beautifully the line segments intersect."

problem

Assign \\ (n \\) coordinates \\ (1, 2,…, n \\) to the circumference at equal intervals. There is exactly one line segment from each coordinate, and the line segment of the coordinate \\ (i \\) is connected to a different coordinate \\ (a_ {i} \\). (Conversely, the line segment of the coordinate \\ (a_ {i} \\) is connected to the coordinate \\ (a_ {a_ {i}} = i \\).) From this state, at most \\ (k) \\) You can reconnect the line segments of a book (freely regardless of coordinates and length) on the circumference. Answer the maximum size of a set of line segments that intersect each other.

input


n k
a1 a2… an


The number of coordinates \\ (n \\) and the number of line segments that can be reconnected \\ (k \\) are given on the first line, separated by blanks. On the second line, \\ (a_ {i} \\) representing the coordinates connecting the line segments of the coordinates \\ (i \\) is given, separated by blanks.

output

At most \\ (k \\) After reconnecting the line segments, output the maximum size of the set of line segments that intersect each other on one line.

Constraint

* \\ (2 \ leq n \ leq 8000 \\)
* \\ (n \\) is an even number
* \\ (0 \ leq k \ leq \ min (n / 2, 20) \\)
* \\ (1 \ leq a_ {i} \ leq n \\)
* \\ (a_ {i} \ not = i \\)
* Never connect a line segment to yourself
* \\ (a_ {i} \ not = a_ {j} (i \ not = j) \\)
* No more than one line segment can be connected at the same coordinates
* \\ (a_ {a_ {i}} = i \\)
* If a line segment is connected from \\ (i \\) to \\ (j \\), a line segment is connected from \\ (j \\) to \\ (i \\)



Input / output example

Input 1


8 0
7 4 6 2 8 3 1 5


Output 1


2


The line segments that intersect each other are represented by the red line segments in the figure below.

http://k-operafan.info/static/uecpc2013/files/art_sample_1.png

Input 2


8 1
7 4 6 2 8 3 1 5


Output 2


3


By reconnecting the line segments connecting 1 and 7 as shown in the figure below, three line segments that intersect each other can be obtained.

http://k-operafan.info/static/uecpc2013/files/art_sample_2.png

Input 3


8 0
5 6 7 8 1 2 3 4


Output 3


Four


Since all line segments intersect each other, the maximum number of intersecting line segments is four.

http://k-operafan.info/static/uecpc2013/files/art_sample_3.png





Example

Input

n k
a


Output

2