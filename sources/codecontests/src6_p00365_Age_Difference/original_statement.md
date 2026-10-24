A trick of fate caused Hatsumi and Taku to come to know each other. To keep the encounter in memory, they decided to calculate the difference between their ages. But the difference in ages varies depending on the day it is calculated. While trying again and again, they came to notice that the difference of their ages will hit a maximum value even though the months move on forever.

Given the birthdays for the two, make a program to report the maximum difference between their ages. The age increases by one at the moment the birthday begins. If the birthday coincides with the 29th of February in a leap year, the age increases at the moment the 1st of March arrives in non-leap years.



Input

The input is given in the following format.


y_1 m_1 d_1
y_2 m_2 d_2


The first and second lines provide Hatsumi’s and Taku’s birthdays respectively in year y_i (1 ≤ y_i ≤ 3000), month m_i (1 ≤ m_i ≤ 12), and day d_i (1 ≤ d_i ≤ Dmax) format. Where Dmax is given as follows:

* 28 when February in a non-leap year
* 29 when February in a leap-year
* 30 in April, June, September, and November
* 31 otherwise.



It is a leap year if the year represented as a four-digit number is divisible by 4. Note, however, that it is a non-leap year if divisible by 100, and a leap year if divisible by 400.

Output

Output the maximum difference between their ages.

Examples

Input

1999 9 9
2001 11 3


Output

3


Input

2008 2 29
2015 3 1


Output

8