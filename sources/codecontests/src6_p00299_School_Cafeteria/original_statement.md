Today is the open campus of Z University. Every year during the lunch break on this day, many high school students line up for the school cafeteria. Therefore, the secretariat of Z University decided to predict the maximum distance of the procession. As a result of the preliminary survey, we know the following.

* The matrix is ​​lined with N people, each numbered from 1 to N.
* For each pair of C high school students (ai, bi), there are two types of restrictions:
* The first constraint is on the order and is one of the following:
ai must be ahead of bi or in the same position
ai must line up after or in the same position as bi
ai can be before, in the same position, or after bi

* The second constraint is on distance and is one of the following:
ai and bi must be at least di meters apart
ai and bi must line up within di meters




We also know that multiple people can be lined up at the same distance from the beginning, and that the number 1 person is always at the beginning of the procession.

Create a program to find the distance when the matrix that satisfies all the given C constraints is arranged so that the distance from the beginning to the end is the maximum. However, output inf if it can be separated indefinitely, and -1 if it is not possible to arrange in a way that satisfies the constraint.



input

The input is given in the following format.


N C
constraint1
constraint2
::
constraintC


The number of high school students in the queue on the first line N (2 ≤ N ≤ 100) and the number of constraints C (0 ≤ C ≤ 200) are given. Each constraint constrainti is given in the following C line in the following format.


aioibisidi


The constraint does not include spaces. The meanings of ai, oi, bi, si and di are shown below.

* ai and bi (1 ≤ ai, bi ≤ N and ai ≠ bi) are high school student numbers, and di is an integer representing the distance (0 ≤ d ≤ 10000).
* oi is a string of <=,> =, * that specifies the order constraint, and if <=, "ai must precede bi or be in the same position",> = In the case of, "ai must be after bi or in the same position", and in the case of *, it means that "ai can be before, in the same position, or after bi". However, no more than 7 constraints with oi as * can be given.
* si is the + or-character that specifies the distance constraint, for + "ai and bi must be at least di meters apart", for-"ai and bi must be within di meters" It means that.



However, it is assumed that multiple constraints are not given to a pair.

output

The distance from the beginning to the end is output on one line.

Example

Input

3 2
1


Output

3