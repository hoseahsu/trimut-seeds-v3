A cell phone company is trying out its new model of cell phone. Here's how its structure is: 

The keypad has 11 buttons corresponding to digits from 0 to 9 and one additional button called Add. After pressing any button from 0 to 9, the corresponding digit appears on the screen. The Add button replaces the last two digits appearing on the screen with their sum taken modulo 10. (See sample test for more clarity). If there are less than two digits currently on the screen, pressing Add does nothing.

Each button has a non-negative cost of pressing associated with it. The cost of pressing Add button is always 0. Given the cost of pressing each button and the target phone number, find the minimum cost of feeding that number into the phone screen using a sequence of button presses.

INPUT

The first line of input file consists of an integer T, which indicates the number of test cases. Then the description of T test cases follow. Each test case is described by 3 lines. The first of them contains 10 space separated integers, denoting the cost of pressing buttons from 0 to 9. The second line contains the length of the target phone number. The third line contains the target phone number S itself.

OUTPUT

Print the minimum cost of feeding the phone screen with the target number for each test case in a separate line.

CONSTRAINTS

1 ≤ T ≤ 1000
0 ≤ Cost of any button ≤ 1000
1 ≤ |S|≤ 1000

SAMPLE INPUT
3
3 2 2 3 2 1 1 2 3 3 
3
171
3 2 3 1 1 1 1 3 1 2 
2
16
3 3 3 1 3 1 1 2 3 2 
2
43

SAMPLE OUTPUT
6
3
4

Explanation

For Test Case 1: Button sequence with cost in brackets: Press 6 (1) -> Press 5 (1) -> Press "Add" (0) -> Press 7 (2)  -> Press 6 (1) -> Press 5 (1)-> Press "Add" (0).

Total Cost = 1 + 1 + 0 + 2 + 1 + 1 + 0 = 6.