Continuing from previous version of codeXplod series i.e. CodeXplod 1.0,Chandu and daspal are still fighting over a matter of MOMO's(they are very fond of Mo Mos of sector 3..:P).This time the fight became so savior that they want to kill each other.As we all  know that during a fight it is most probable outcome that both will be injured.As their friend we don`t want that to happen so we devise a method.

We gave them two integers (x,y) as they have to play a game on these values.
Game is defined as follows:-
Players play alternative.
1-During a move they are allowed to subtract gcd(x,y) from both x and y .

2-The player which makes either one of the values to zero or both to zero will win the game and will eat all the MOMO's.

3-If neither of values after 1st step does not equal to zero then the second player gets a chance and play as described by rule 1,2,3.
 Now,You are given two integers and you have to find out who will eat all the MOMOs.

 Input Format:-

 First Line of input will contain an integer T denoting number of test cases.
 Each test cases contains 2 integers(x,y) with a strings.
 Two integers  x,y specify the integers given to them by us and string will specify who will play first i.e. String will be either of values "Chandu" and "Daspal"(Quotes only for clarity).
 Output Format:-

 Output a string either "Chandu" or "Daspal"(Qoutes for clarity) determinging who will win the game.
 Constraints:-

1 ≤ T ≤ 50

1 ≤ x,y ≤ 3000

SAMPLE INPUT
1
2 3 Chandu

SAMPLE OUTPUT
Daspal

Explanation

First gcd(2,3)=1 so Chandu subtract 1 from each so new pair now (1,2) now its Daspal's Turn he has gcd(1,2)=1 so after subtracting (0,1) now daspal have one zero so he is declared as winner of the game.Phew!!!