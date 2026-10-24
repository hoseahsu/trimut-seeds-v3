Apple adventure

square1001 and E869120 got lost in the grid world of $ H $ rows and $ W $ rows!

Said the god of this world.

"When you collect $ K $ apples and they meet, you'll be back in the original world."

Upon hearing this word, square1001 decided to collect more than $ K $ of apples and head to the square where E869120 is.




Here, each cell in the grid is represented as follows.

's': square1001 This is the square where you are.

'e': E869120 This is the square where you are.

'a': A square with one apple on it. You can get an apple the first time you visit this trout. There are no more than 20 squares on this grid.

'#': It's a wall. You cannot visit this square.

'.': A square with nothing. You can visit this square.




square1001 You try to achieve your goal by repeatedly moving from the square you are in to the squares that are adjacent to each other up, down, left, and right. However, you cannot get out of the grid.

square1001 Find the minimum number of moves you need to achieve your goal.

However, it is assumed that E869120 will not move. Also, square1001 shall be capable of carrying $ K $ or more of apples.

If the goal cannot be achieved, output "-1".

input

Input is given from standard input in the following format.

Let $ A_ {i, j} $ be the characters in the $ i $ square from the top of the grid and the $ j $ square from the left.


$ H $ $ W $ $ K $
$ A_ {1,1} A_ {1,2} A_ {1,3} \ cdots A_ {1, W} $
$ A_ {2,1} A_ {2,2} A_ {2,3} \ cdots A_ {2, W} $
$ A_ {3,1} A_ {3,2} A_ {3,3} \ cdots A_ {3, W} $
$ \ ldots $
$ A_ {H, 1} A_ {H, 2} A_ {H, 3} \ cdots A_ {H, W} $


output

square1001 Find the minimum number of moves you need to reach your goal. However, if this is not possible, output "-1".

However, insert a line break at the end.

Constraint

* $ 1 \ leq H \ leq 1000 $
* $ 1 \ leq W \ leq 1000 $
* $ 1 \ leq K \ leq 20 $
* $ H, W, K $ are integers.
* $ A_ {i, j} $ is one of's','e','a','#','.'.
* The grid contains only one's' and one'e'.
* The number of'a'in the grid is greater than or equal to $ K $ and less than or equal to $ 20 $.



Input example 1


5 5 2
s .. # a
. # ...
a # e. #
... # a
. # ...


Output example 1


14


Input example 2


7 7 3
.......
.s ... a.
a ## ... a
.. ### ..
.a # e # .a
. ### ..
a .. # .. a


Output example 2


-1


If the purpose cannot be achieved, output "-1".

Input example 3


12 12 10
. ##### ......
.## ..... # ...
.... a.a # a .. #
. # .. # a ......
..... a # s ..
..a ###. ##. #
.e #. #. #. # A ..
.. # a # ..... #.
.. ## a ......
.a ... a.a .. #.
a .... # a.aa ..
... a. # ... # a.


Output example 3


30






Example

Input

5 5 2
s..#a
.#...
a#e.#
...#a
.#...


Output

14