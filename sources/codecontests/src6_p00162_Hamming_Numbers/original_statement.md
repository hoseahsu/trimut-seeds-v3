The number obtained by multiplying 1 by 2, 3, 5 several times (0 or more times) is called the Hamming numbers. For example

* 1
* 1 x 2 x 2 = 4
* 1 x 2 x 2 x 3 x 5 x 5 = 300



Etc. are humming numbers, but 11, 13, 14 etc. are not humming numbers.

All humming numbers are divisible by a power of 60 (for example, 54 is divisible by 603 = 21600), so they have long been known as convenient numbers for sexagesimal calculations such as time. In just intonation, which is one of the scales used for tuning musical instruments, the ratio of the frequencies of the sounds is a sequence of humming numbers of 24, 27, 30, 32, 36, 40, 45, 48.

Create a program that takes integers m and n as inputs and outputs the number of humming numbers that are m or more and n or less.



Input

A sequence of multiple datasets is given as input. The end of the input is indicated by a single line of zeros.

For each dataset, two integers m and n (1 ≤ m, n ≤ 1000000, m ≤ n) are given on one line, separated by blanks.

The number of datasets does not exceed 20.

Output

Outputs the number of humming numbers from m to n for each data set on one line.

Example

Input

3 8
1 27
1 86
0


Output

5
17
31