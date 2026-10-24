**
Problem Statement is Updated
**

Xenny had N colors with him, all arranged in a straight line. He was interested in picking up a particular subarray of colors.

A pre-set is a set that contains all subarrays of colors that start from the first color and do not contain the last color.

An end-set is a set that contains all subarrays of colors that end at the last color and do not contain the first color.

Xenny wants to choose the longest subarray that is contained in both - pre-set as well as end-set.

Then Xenny will write that number in list L.

Now, Xenny will delete the last color and apply the same procedure till only first color remains.

Now Xenny will have  N numbers which he has written in list L.

You have to print maximum number in that list.

You have 
Input Format

First line contains a single integer T - denoting number of testcases.

For each testcase:

First line contains an integer N - denoting the no. of colors

Second line contains N space-separated integers that denote the i^th color.

Output  format

Print a single integer - length of the longest subset that is contained in the pre-set as well as end-set.

Note: Please use Fast I/O as input may be as large as 25 MB.

Array size will be upto 10^6.

SAMPLE INPUT
1
4
1 2 1 2

SAMPLE OUTPUT
2

Explanation

The pre-sets for given array, {1, 2, 1, 2} ,are 
{1}, {1, 2}, {1, 2, 1}

The end-sets are
{2, 1, 2}, {1, 2}, {2}

The common sets in both these sets are

The set with maximum number of elements is

The length of this set is 2.

So 2 will get added to list.

Now delete the last number from array, we get {1, 2, 1}
The pre-sets for {1, 2, 1} ,are 
{1}, {1, 2}

The end-sets are
{2, 1}, {1}

The common sets in both these sets are

The set with maximum number of elements is

The length of this set is 1.

So 1 will get added to list.

Now delete the last number from array, we get {1, 2}
The pre-sets for {1, 2} ,are 

The end-sets are

The common sets in both these sets are
NULL

The set with maximum number of elements is
The length of this set is 0.

So 0 will get added to list.

Now printing maximum of list [2, 1, 0] = 2

Hence the answer.