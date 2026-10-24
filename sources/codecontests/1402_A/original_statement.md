Everybody knows that Balázs has the fanciest fence in the whole town. It's built up from N fancy sections. The sections are rectangles standing closely next to each other on the ground. The ith section has integer height h_i and integer width w_i. We are looking for fancy rectangles on this fancy fence. A rectangle is fancy if: 

  * its sides are either horizontal or vertical and have integer lengths 
  * the distance between the rectangle and the ground is integer 
  * the distance between the rectangle and the left side of the first section is integer 
  * it's lying completely on sections 

What is the number of fancy rectangles? This number can be very big, so we are interested in it modulo 10^9+7.

Input

The first line contains N (1≤ N ≤ 10^{5}) – the number of sections. The second line contains N space-separated integers, the ith number is h_i (1 ≤ h_i ≤ 10^{9}). The third line contains N space-separated integers, the ith number is w_i (1 ≤ w_i ≤ 10^{9}).

Output

You should print a single integer, the number of fancy rectangles modulo 10^9+7. So the output range is 0,1,2,…, 10^9+6.

Scoring

 \begin{array}{|c|c|c|} \hline Subtask & Points & Constraints \\\ \hline 1 & 0 & sample\\\ \hline 2 & 12 & N ≤ 50 \: and \: h_i ≤ 50 \: and \: w_i = 1 \: for all \: i \\\ \hline 3 & 13 & h_i = 1 \: or \: h_i = 2 \: for all \: i \\\ \hline 4 & 15 & all \: h_i \: are equal \\\ \hline 5 & 15 & h_i ≤ h_{i+1} \: for all \: i ≤ N-1 \\\ \hline 6 & 18 & N ≤ 1000\\\ \hline 7 & 27 & no additional constraints\\\ \hline \end{array} 

Example

Input


2
1 2
1 2


Output


12

Note

The fence looks like this: <image>

There are 5 fancy rectangles of shape: <image>

There are 3 fancy rectangles of shape: <image>

There is 1 fancy rectangle of shape: <image>

There are 2 fancy rectangles of shape: <image>

There is 1 fancy rectangle of shape: <image>