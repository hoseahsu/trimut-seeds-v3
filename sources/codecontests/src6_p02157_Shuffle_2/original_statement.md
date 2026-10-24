Problem

There is a bundle of $ n $ cards, with $ i $ written on the $ i $ th card from the bottom. Shuffle this bundle as defined below $ q $ times.


* When looking at the bundle from below, consider a bundle $ x $ made by stacking odd-numbered cards on top, and a bundle $ y $ made by stacking even-numbered cards on top. Then do whatever you like out of the following $ 2 $.
* Operation $ 0 $: Put the bundle $ y $ on the bundle $ x $ to make a bundle of $ 1 $.
* Operation $ 1 $: Put the bundle $ x $ on the bundle $ y $ to make a bundle of $ 1 $.



For example, if you consider shuffling $ 1 $ times for a bundle of $ 6 $ cards (123456 from the bottom), the bundle you get when you perform the operation $ 0 $ is ~~ 246135 ~~ from the bottom. 135246, the bundle obtained by performing the operation $ 1 $ is ~~ 135246 ~~ 246135 from the bottom. (Corrected at 14:52)

After $ q $ shuffle, I want the card with $ k $ to be $ d $ th from the bottom of the bunch.
If possible, print $ q $ of shuffle operations in sequence, and if not, print $ -1 $.

Constraints

The input satisfies the following conditions.

* $ 2 \ le n \ le 10 ^ {15} $
* $ 1 \ le q \ le 10 ^ 6 $
* $ 1 \ le k, d \ le n $
* $ n $ is even

Input

The input is given in the following format.


$ n $ $ q $ $ k $ $ d $


Output

If it is possible to shuffle the conditions, output the shuffle operation on the $ q $ line.

If not possible, output $ -1 $.

Examples

Input

4 2 1 1


Output

0
0


Input

4 2 3 1


Output

0
1


Input

4 1 1 4


Output

-1


Input

7834164883628 15 2189823423122 5771212644938


Output

0
1
1
1
1
1
0
1
0
1
0
0
0
0
0