Description

KULASIS is the name of a system developed and operated by the Higher Education Research and Development Promotion Organization for the purpose of providing information on common subjects throughout the university on the Web, supporting students and faculty members, and improving services. KULASIS started with the development of the online syllabus in 2003, and has gradually expanded the system to include Web bulletin boards, course registration, grades (scoring registration, scoring confirmation from students).
Students can use functions such as confirmation of academic affairs information (class cancellations, class changes, reports), course registration, and scoring confirmation from both inside and outside the university from a personal computer or mobile phone. The number of logins exceeds 10,000 on many days, and it has become widespread as an academic affairs information system at Kyoto University, and is indispensable for taking common courses throughout the university. We are developing this KULASIS so that it can be applied not only to common subjects throughout the university, but also to undergraduate specialized courses and graduate schools.
http://www.z.k.kyoto-u.ac.jp/introduction_kulasis.html

Q, a student at Kyoto University, was logged in to KULASIS to form a late syllabus. When I was wondering which subject I was going to enter, KULASIS suddenly gave off a dazzling light and moved to another page.
The page to which the transition was made was as shown in the figure below. The subject name and evaluation (impossible, acceptable, good, excellent) are written in the 5x5 square, and 16 ● buttons are arranged on the grid.
It was Q that I did not know what happened, but apparently when I press the ● button on the grid, the evaluation of the subjects in the upper right, lower right, upper left, and lower left is not possible → Yes, Yes → Good, Good → Excellent, Excellent → Impossible.


<image>


You can press the ● button as many times as you like.
I'm not sure if KULASIS has been rewritten by someone or if I'm dreaming, but if I can confirm my grades with this, Q wanted to get as good a grade as possible.
Confident that he was collecting a lot of credits, Q decided to maximize his fighting power in preparation for his assignment to the laboratory six months later than the number of credits itself.
Combat power is the total value of the evaluation of each subject converted into impossible → 0 points, acceptable → 60 points, good → 70 points, excellent → 80 points. It is thought (in the Q department) to show how superior it is.

Now that the subjects displayed on the KULASIS screen and their evaluations are given, please describe the program that outputs the maximum value of the combat power that can be obtained.



Input

The number of test cases is given on the first line of input. The number of test cases is guaranteed to be 100 or less.
From the second line onward, 5x5 numbers are lined up, and the evaluation of the subject displayed on the KULASIS screen is given, and 1,2,3,4 correspond to impossible, acceptable, good, and excellent, respectively.
If it is 0, no subject is registered in that frame.
The test cases are separated by a blank line.

Output

Output the maximum value of combat power that can be obtained for each test case.

Example

Input

5

1 1 0 3 3
1 1 0 3 3
0 0 0 0 0
2 2 0 4 4
2 2 0 4 4

1 1 1 0 0
1 1 1 1 0
1 0 1 1 0
0 0 1 1 1
1 1 1 1 1

0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

4 3 4 3 4
3 4 3 4 3
4 3 4 3 4
3 4 3 4 3
4 3 4 3 4

2 2 2 2 2
0 0 0 2 0
2 2 0 2 0
2 2 0 2 0
0 0 0 2 0


Output

1280
1420
0
1920
1020