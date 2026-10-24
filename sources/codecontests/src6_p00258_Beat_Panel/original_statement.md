Yuta is addicted to the popular game "Beat Panel" at a nearby arcade. The game consists of a total of 16 panel-type buttons, 4x4, arranged in a grid as shown.

<image>


As shown in the figure, the buttons are arranged in the order of button 1, button 2,…, button 16 from the upper left to the lower right. In the game, you will hear a beat sound at regular intervals and a final sound at the end. Multiple buttons light up at the same time as the beat sounds. In some cases, even one does not shine. The player can press multiple buttons at the same time using the fingers of both hands from immediately after the beat sound to the next sound. It is also possible not to press anything. The game ends as soon as the end sound is heard.

Yuta has mastered c ways of pressing, and each time a beat sounds, he decides one of those pressing methods and presses the button. If the buttons you press are lit, those buttons will be lit and the number of buttons that have disappeared will be added to the player's score. Also, once a button is lit, the light will not go out until the button is pressed.

A program that outputs the maximum score that Yuta can obtain by inputting how to illuminate the button when the beat sound is played n times and how to press the button in c ways that Yuta has learned. Please create.



input

The input consists of multiple datasets. The end of the input is indicated by two lines of zeros. Each dataset is given in the following format.


n c
a1,1 a1,2 ... a1,16
a2,1 a2,2 ... a2,16
...
an, 1 an, 2 ... an, 16
b1,1 b1,2 ... b1,16
b2,1 b2,2 ... b2,16
...
bc,1 bc,2 ... bc,16


The first line consists of two integers separated by one space. n (1 ≤ n ≤ 30) indicates the number of beat sounds, and c (1 ≤ c ≤ 30) indicates the number of button presses that you have learned. The following n + c lines give how to illuminate the button and how to press the button. The input item in the line is separated by one blank. ak and i indicate how the button i shines when the kth beat sound is heard, and bj and i indicate whether the button i is pressed by pressing the jth button in the middle of c. As for the values ​​of ak and i, 0 means "does not shine" and 1 means "shines". For the values ​​of bj and i, 0 means "do not press" and 1 means "press".

The number of datasets does not exceed 20.

output

For each data set, the maximum score is output on one line.

Example

Input

2 2
0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1
1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0
0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1
1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0
2 2
0 0 1 0 1 1 1 1 0 0 1 0 0 0 1 0
0 1 0 1 0 1 1 1 0 1 0 1 0 0 0 0
0 0 1 0 1 0 0 0 0 0 1 0 0 0 1 0
0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0
5 3
0 0 0 0 0 1 1 0 0 1 1 0 0 0 0 0
1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1
0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 1 1 0 0 1 1 0 0 0 0 0
1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0
0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 1
0 0


Output

8
7
16