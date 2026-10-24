Tower of JOIOI

The JOIOI Tower is a game that uses a disk to be played by one person.

This game is played using several disks with the letters J, O, and I written on them. The discs have different diameters, and at the start of the game, these discs are stacked from bottom to top in descending order of diameter. You want to use these disks to build as many mini JOIOI towers as possible. The mini JOIOI tower consists of three disks, which can be read as JOI or IOI in ascending order of diameter. However, the same disk cannot be used more than once.

<image>


Figure: Two mini JOIOI towers can be built from JOIOII

Task

The characters written on the prepared disks are given as a character string S of length N in order from the one with the smallest diameter of the disk. Create a program to find the maximum number of mini JOIOI towers that can be made using these disks.

Limits

* 1 ≤ N ≤ 1 000 000 Length of string S



input

Read the following data from standard input.

* The integer N is written on the first line. N represents the length of the string S.
* The character string S is written on the second line.



output

Output an integer representing the maximum number of mini JOIOI towers that can be created to the standard output on one line.

Input / output example

Input example 1


6
JOIIOI


Output example 1


2


JOIIOI contains one JOI and one IOI as a subsequence, and there are two mini JOIOI towers that can be created.




Input example 2


Five
JOIOI


Output example 2


1


It contains JOI and IOI as subsequences, but cannot be retrieved at the same time because the characters cannot be used more than once.




Input example 3


6
JOIOII


Output example 3


2


This input / output example corresponds to the example in the problem statement.




Input example 4


15
JJOIIOOJOJIOIIO


Output example 4


Four





The question text and the data used for the automatic referee are the question text and the test data for scoring, which are created and published by the Japan Committee for Information Olympics.





Example

Input

6
JOIIOI


Output

2