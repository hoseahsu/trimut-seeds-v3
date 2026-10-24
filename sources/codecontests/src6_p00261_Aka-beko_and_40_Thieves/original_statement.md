Aka Beko, trying to escape from 40 bandits, got lost in the city of A. Aka Beko wants to go to City B, where the new hideout is, but the map has been stolen by a bandit.

Kobborg, one of the thieves, sympathized with Aka Beko and felt sorry for him. So I secretly told Aka Beko, "I want to help you go to City B, but I want to give you direct directions because I have to keep out of my friends, but I can't tell you. I can answer. "

When Kobborg receives the question "How about the route XX?" From Aka Beko, he answers Yes if it is the route from City A to City B, otherwise. Check the directions according to the map below.

<image>


Each city is connected by a one-way street, and each road has a number 0 or 1. Aka Beko specifies directions by a sequence of numbers. For example, 0100 is the route from City A to City B via City X, Z, and W. If you choose a route that is not on the map, you will get lost in the desert and never reach City B. Aka Beko doesn't know the name of the city in which she is, so she just needs to reach City B when she finishes following the directions.

Kobborg secretly hired you to create a program to answer questions from Aka Beko. If you enter a question from Aka Beko, write a program that outputs Yes if it is the route from City A to City B, otherwise it outputs No.



input

The input consists of multiple datasets. The end of the input is indicated by a single # (pound) line. Each dataset is given in the following format.


p


A sequence of numbers 0, 1 indicating directions is given on one line. p is a string that does not exceed 100 characters.

The number of datasets does not exceed 100.

output

Print Yes or No on one line for each dataset.

Example

Input

0100
0101
10100
01000
0101011
0011
011111
#


Output

Yes
No
Yes
No
Yes
No
Yes