C: Mod! Mod!

story

That's right! I'm looking for eyewitness testimony! A phantom thief has appeared in Aizu! Everyone's horse stick was stolen! Who is the culprit! ?? Unravel! Mod! Mod!

Problem statement

"Eyes" ... it's a miracle bud that swells in the hearts of the chosen ones ... You can steal anything with the special ability "Eyes".

Aizu Maru, the biggest phantom thief in Aizu, decides to steal a "horse stick" from n detectives in order to fill the world with a mystery. Umauma sticks are just sweets that Maru loves, and each of the n detectives has several horse sticks. Also, because Aizumaru is greedy, when he steals a horse stick from each detective, he steals all the horse sticks that the detective has.

Aizumaru, who is addicted to eating three horse sticks at the same time, when he has three or more horse sticks at hand, he keeps three horse sticks until he loses the temptation and has less than three horse sticks. I will eat it. However, Aizumaru loses his eyes in shock if he does not have a horse stick at hand, and he cannot steal any more horse sticks. In other words, in order to steal a horse horse stick, it is necessary to have one or more horse horse sticks on hand, and when it reaches 0, it becomes impossible to steal any more horse horse sticks.

Aizuma, who wants to steal horse sticks from as many detectives as possible, noticed that the number of detectives who can steal horse sticks depends on which detective steals the horse sticks in order. However, I don't know how difficult it is to get together. "Hate?" Aizumaru's excellent subordinate, you decided to write a program to ask how many detectives you can steal a horse stick instead of Aizumaru.

Since the number of detectives n and how many horse sticks to steal from each of n detectives are given, when stealing horse sticks from detectives in the optimum order, it is possible to steal horse sticks from up to how many detectives. Create a program that outputs what you can do. However, although the number of horse sticks on hand at the beginning is 0, it is assumed that the horse sticks can be stolen even if the number of horse sticks on hand is 0 only at the beginning.

Input format

The input consists of two lines and is given in the following format.


n
a_1 a_2… a_n


The first line is given the integer n, which is the number of detectives stealing horse sticks. On the second line, n number of horse sticks to steal from each detective are given, separated by blanks.

Constraint

* 1 ≤ n ≤ 500 {,} 000
* 1 ≤ a_i ≤ 9 (1 ≤ i ≤ n)



Output format

When you steal a horse stick from a detective in the optimal order, print out in one line how many detectives you can steal a horse stick from.

Input example 1


6
2 5 2 5 2 1


Output example 1


Five

If you steal in the order of 2 5 1 2 5, you can steal from 5 people. No matter what order you steal, you cannot steal from six people.

Input example 2


3
3 6 9


Output example 2


1

No matter which one you steal from, the number of horse sticks you have will be 0 and you will lose your eyes.

Input example 3


6
1 2 3 4 5 6


Output example 3


6





Example

Input

6
2 5 2 5 2 1


Output

5