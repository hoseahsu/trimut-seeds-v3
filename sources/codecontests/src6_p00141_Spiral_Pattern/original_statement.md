I decided to create a program that displays a "round and round pattern". The "round and round pattern" is as follows.

* If the length of one side is n, it is displayed as a character string with n rows and n columns.
* A spiral pattern that rotates clockwise with the lower left corner as the base point.
* The part with a line is represented by # (half-width sharp), and the blank part is represented by "" (half-width blank).
* Leave a space between the lines.



Create a program that takes an integer n as an input and outputs a "round and round pattern" with a side length of n.



Input

The input is given in the following format:


d
n1
n2
::
nd


The number of datasets d (d ≤ 20) is given to the first line, and the side length ni (1 ≤ ni ≤ 100) of the i-th round pattern is given to each of the following d lines.

Output

Please output a round and round pattern for each data set. Insert a blank line between the datasets.

Example

Input

2
5
6


Output

#####
#   #
# # #
# # #
# ###

######
#    #
# ## #
# #  #
# #  #
# ####