Harry has been tracking Draco Malfoy throughtout the year on the 
Marauder's Map. But suddenly one day, Harry could not locate Draco on the map. Now he decides to search the entire map. But since the
Marauder's map is of the entire Hogwarts school, it will take Harry
a lot of time to search Malfoy. So he decides to look for him only
within a small rectangle that will cover all the places that Malfoy
has visited throughout the year. Harry knows all the points that
Malfoy has been to. He has marked them using the X-Y coordinate system.
All the places on the map have integral coordinates. 

Being weak at Geometry, he leaves the task of calculating the 
rectangle to you.

Your task is to calculate the area of the minimum possible rectangle
that will cover all the points that Malfoy has visited throughout the
year with atleast one edge of the rectangle parallel to the Forbidden
third floor corridor which is the X-axis.

Incase your answer turns out to be zero, tell Harry the maximum
possible length that can be obtained on joining all the points.

Input

The first line contains T - the number of test cases.
Then T test cases follow.
The first line of each test case contains a single integer N - denoting 
the number of points that Harry has marked.
The next N lines contain two integers X and Y referring to the
points Draco Malfoy has visited.

Output

Output the minimum area of the rectangle followed by a newline.

Constraints

1 ≤ T ≤ 1000

2 ≤ N ≤ 1000

-90 ≤ X ≤ 90

-180 ≤ Y ≤ 180

All points may not be unique

Problem Setter: Vinay Kumar

SAMPLE INPUT
2
2
1 1
3 3
3
1 1
2 2
2 3

SAMPLE OUTPUT
4
2

Explanation

For the first test case, the rectange (1,1), (1,3), (3,1), (3,3) is the required rectangle
For the second test case, the rectangle (1,1), (2,1), (2,3) and (1,3) is the required rectangle