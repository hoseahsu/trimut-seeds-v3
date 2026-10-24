C - Iyasugigappa

Problem Statement

Three animals Frog, Kappa (Water Imp) and Weasel are playing a card game.

In this game, players make use of three kinds of items: a guillotine, twelve noble cards and six action cards. Some integer value is written on the face of each noble card and each action card. Before stating the game, players put twelve noble cards in a line on the table and put the guillotine on the right of the noble cards. And then each player are dealt two action cards. Here, all the noble cards and action cards are opened, so the players share all the information in this game.

Next, the game begins. Each player takes turns in turn. Frog takes the first turn, Kappa takes the second turn, Weasel takes the third turn, and Frog takes the fourth turn, etc. Each turn consists of two phases: action phase and execution phase in this order.

In action phase, if a player has action cards, he may use one of them. When he uses an action card with value on the face y, y-th (1-based) noble card from the front of the guillotine on the table is moved to in front of the guillotine, if there are at least y noble cards on the table. If there are less than y cards, nothing happens. After the player uses the action card, he must discard it from his hand.

In execution phase, a player just remove a noble card in front of the guillotine. And then the player scores x points, where x is the value of the removed noble card.

The game ends when all the noble cards are removed.

Each player follows the following strategy:

* Each player assume that other players would follow a strategy such that their final score is maximized.
* Actually, Frog and Weasel follows such strategy.
* However, Kappa does not. Kappa plays so that Frog's final score is minimized.
* Kappa knows that Frog and Weasel would play under ``wrong'' assumption: They think that Kappa would maximize his score.
* As a tie-breaker of multiple optimum choises for each strategy, assume that players prefer to keep as many action cards as possible at the end of the turn.
* If there are still multiple optimum choises, players prefer to maximuze the total value of remaining action cards.



Your task in this problem is to calculate the final score of each player.

Input

The input is formatted as follows.


x_{12} x_{11} x_{10} x_9 x_8 x_7 x_6 x_5 x_4 x_3 x_2 x_1
y_1 y_2
y_3 y_4
y_5 y_6


The first line of the input contains twelve integers x_{12}, x_{11}, …, x_{1} (-2 \leq x_i \leq 5). x_i is integer written on i-th noble card from the guillotine. Following three lines contains six integers y_1, …, y_6 (1 \leq y_j \leq 4). y_1, y_2 are values on Frog's action cards, y_3, y_4 are those on Kappa's action cards, and y_5, y_6 are those on Weasel's action cards.

Output

Print three space-separated integers: the final scores of Frog, Kappa and Weasel.

Sample Input 1


3 2 1 3 2 1 3 2 1 3 2 1
1 1
1 1
1 1


Output for the Sample Input 1


4 8 12


Sample Input 2


4 4 4 3 3 3 2 2 2 1 1 1
1 2
2 3
3 4


Output for the Sample Input 2


8 10 12


Sample Input 3


0 0 0 0 0 0 0 -2 0 -2 5 0
1 1
4 1
1 1


Output for the Sample Input 3


-2 -2 5






Example

Input

3 2 1 3 2 1 3 2 1 3 2 1
1 1
1 1
1 1


Output

4 8 12