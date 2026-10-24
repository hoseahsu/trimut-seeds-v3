Princess in Danger

Princess crisis

English text is not available in this practice contest.

A brave princess in a poor country's tomboy is married to another country for a political marriage. However, a villain who was trying to kill the princess attacked him on the way to his wife, and the princess was seriously injured and was taken to a nearby hospital. However, the villain used a special poison to make sure the princess was dead. Therefore, in order to help the princess, she had to hurry to bring special medicine and frozen relatives' blood from her home country.

This blood is transported frozen, but must be re-frozen in a blood freezing facility within up to M minutes of the previous freezing to keep it fresh. However, there are only a few places where refrigeration facilities are installed.

Blood is safe for M minutes from a fully frozen state without refreezing. If the remaining time without refrigeration is S minutes and the product is transported without freezing for T minutes, the remaining time without refrigeration is S-T minutes. The remaining time that does not require refreezing can be restored up to M minutes by refreezing. The time it takes to refreeze blood depends on how much it is frozen. Every minute the blood is frozen in a freezing facility, the remaining time that does not need to be re-frozen recovers by 1 minute.

At the time of departure from the capital of the home country, the remaining time without refrigerating the blood is M minutes.

As a princess's servant, you must calculate the route to keep the blood fresh from the capital of your home country to the hospital where the princess was transported, in order to save the life of your precious lord. Yes, your mission is to figure out the shortest route from your home capital to the hospital and find the shortest time.

Input

The input consists of multiple datasets. The first row of each dataset contains six non-negative integers N (2 ≤ N ≤ 100), M (1 ≤ M ≤ 100), L (0 ≤ L ≤ N-2), K, A (0 ≤). A <N) and H (0 ≤ H <N) are given. These are the number of towns, the time limit for refrigeration, the number of towns with freezing facilities, the number of roads connecting towns directly, the number representing the capital of the home country, and the hospital where the princess was transported. Represents the town number. The capital of the home country and the hospital where the princess was transported are different towns. It is assumed that the towns are assigned numbers from 0 to N-1. The following lines are given L non-negative integers separated by a single space. These represent the numbers of the towns where the freezing facilities are located. The capital of the home country and the hospital where the princess was transported are not included in this list, but it can be considered that there is a freezing facility. The following line K gives information on the roads connecting the towns. In the i-th line, three non-negative integers X, Y, and T are given separated by one space, which means that there is a direct connection between town X and town Y, and it takes time T to move. Represents that. This road is bidirectional. Also, there is at most one road that directly connects town X and town Y.

The input ends when N = M = L = K = A = H = 0, which is not included in the dataset.

Output

For each dataset, output the shortest time that blood can be delivered while maintaining its freshness. If it cannot be delivered, output "Help!".

Sample Input


2 1 0 1 0 1
0 1 2
3 1 1 2 0 1
2
0 2 1
1 2 1
3 2 1 2 0 1
2
0 2 1
1 2 1
4 4 1 4 1 3
2
0 1 2
1 2 4
0 2 1
3 0 3
5 3 2 6 0 3
1 2
2 1 2
1 0 1
3 4 1
2 4 1
4 1 2
2 0 2
5 4 2 6 0 3
1 2
4 2 4
2 1 2
4 3 1
0 1 5
1 4 2
2 0 3
0 0 0 0 0 0


Output for the Sample Input


Help!
3
2
Ten
Five
12






Example

Input

2 1 0 1 0 1
0 1 2
3 1 1 2 0 1
2
0 2 1
1 2 1
3 2 1 2 0 1
2
0 2 1
1 2 1
4 4 1 4 1 3
2
0 1 2
1 2 4
0 2 1
3 0 3
5 3 2 6 0 3
1 2
2 1 2
1 0 1
3 4 1
2 4 1
4 1 2
2 0 2
5 4 2 6 0 3
1 2
4 2 4
2 1 2
4 3 1
0 1 5
1 4 2
2 0 3
0 0 0 0 0 0


Output

Help!
3
2
10
5
12