Little Chiku is very choosy about numbers. He considers 0 and 1 together as bad omen. So he hates 0 and 1 appearing adjacent to each other. So he wants you to remove these 0 and 1 combinations from a string. So you proceed like this : Choose any two adjacent positions in the string, and if one them contains 0, and the other contains 1, then you are allowed to remove these two digits from the string, obtaining a string of length n-2 as a result.

Now Chiku ponders about what is the minimum length of the string that will remain after applying the above operation repeatedly many times (possibly, zero) .Help little Chiku to calculate this number.

Input:
First line contains T, the number of test cases to follow. (1 ≤ T ≤ 1000)
Each test case contains the string of length n consisting only from zeros and ones. (1 ≤ n ≤ 2*10^5),

Output:
Output the minimum length of the string that may remain after applying the described operations several times.

SAMPLE INPUT
3
11101111
1100
01010

SAMPLE OUTPUT
6
0
1

Explanation

**Sample Input**
3
11101111
1100
01010

**Output:**
6
0
1
**Explanation**
In the sample test it is possible to change the string like the following: 
11101111-> removing adjacent zero and one from the string ->111111(String of length 6 remains)
Likewise:
1100->remove adjacent zero and one->10-> remove adjacent zero and one ->None(0 length string remains)
01010-> remove adjacent zero and one-> 010-> remove adjacent zero and one ->0 (1 length string remains)