Problem statement

JOI decided to start a new social game from tomorrow.

In this social game, you can log in up to once a day, and you will get A coins each time you log in.

Also, if you log in for 7 consecutive days from Monday to Sunday, you will get an additional B coins each time.

No other coins will be given.

Tomorrow is Monday. Find the minimum number of times JOI must log in to get at least C coins.

Constraint

* 1 ≤ A ≤ 1000
* 0 ≤ B ≤ 1000
* 1 ≤ C ≤ 1000000 (= 10 ^ 6)

Input Output

input
Input is given from standard input in the following format.
A B C

output
Output the minimum number of times JOI must log in to get at least C coins.

<!-

Subtask

1. (40 points) B = 0
2. (60 points) There are no additional restrictions.



->

Input / output example

Input example 1


3 0 10


Output example 1


Four


* I want to get 3 coins per login and collect 10 coins.
* JOI can get 12 coins by logging in for 4 consecutive days from Monday.
* Since you cannot get more than 10 coins by logging in 3 times or less, the minimum number of times JOI must log in is 4. Therefore, 4 is output.



Input example 2


1 2 10


Output example 2


8


* You can get 1 coin for each login. Apart from that, you can get 2 coins by logging in for a week in a row. I want to collect 10 coins.
* If you log in consecutively from Monday to Sunday, you will get 2 coins in addition to 7 daily coins, so you will get a total of 9 coins. Therefore, if you log in one more time, you will get 10 coins.
* Since you cannot get more than 10 coins by logging in 7 times or less, the minimum number of times JOI must log in is 8. Therefore, 8 is output.




Creative Commons License

Information Olympics Japan Committee work "18th Japan Information Olympics JOI 2018/2019 Qualifying Competition Tasks"





Example

Input

3 0 10


Output

4