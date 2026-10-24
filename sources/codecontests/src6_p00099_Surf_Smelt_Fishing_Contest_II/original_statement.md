A smelt fishing tournament was held at Lake Hibara. It seems that catch and release is recommended this time.

Create a program that reads the participant number and the number of fish caught or released in order as one event, and outputs the participant number and the number of animals that have acquired the most smelt immediately after each event. please. If there are multiple participants with the highest number of participants (or if all participants are 0), output the one with the lowest participant number.



input

The input is given in the following format.


n q
a1 v1
a2 v2
::
aq vq


n (1 ≤ n ≤ 1000000) represents the number of participants and q (1 ≤ q ≤ 100000) represents the number of events. ai (1 ≤ ai ≤ n) vi (-100 ≤ vi ≤ 100) indicates that participant ai acquired or released vi at the i-th event. For vi, a positive value indicates acquisition, a negative value indicates release, and 0 is never given.

output

For each event, the participant number and the number of participants who have acquired the most smelt at hand are output on one line separated by one blank.

Example

Input

3 5
1 4
2 5
1 3
3 6
2 7


Output

1 4
2 5
1 7
1 7
2 12