You have just purchased a new mobile phone and you want to call all of your relatives to brag about your new phone. You have N relatives. You will talk to i^th relative for exactly Ti minutes. Each minute costs you 1 dollar . However, your relatives are generous. Hence after the conversation, they will add a recharge of Xi dollars in your mobile. Initially, you have M dollars balance in your mobile phone.
Find the minimum value of M, that you must have initially, in your phone, so that you don't run out of balance during any of the call (encounter negative balance). 

Note : You can call relatives in any order. Each relative will be called exactly once.

INPUT
The first line will contain N, the number of relatives. Next N lines will have two space separated integers, "Ti Xi" (quotes for clarity), representing call duration with the i^th relative and the amount of recharge you will get from that relative after the conversation.

OUTPUT
Output a single integer M, the minimum required initial balance in your mobile phone.

CONSTRAINTS
1 ≤ N,X,T  ≤ 10^5 

SAMPLE INPUT
2
1 1
2 1

SAMPLE OUTPUT
2