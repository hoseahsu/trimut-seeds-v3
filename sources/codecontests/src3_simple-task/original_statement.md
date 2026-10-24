Given an array A. Delete an single element from the array such that sum of the differences of adjacent elements should be minimum.  

For more clarification Sum for an array A having N element is defined as :  
abs( A[0] - A[1] )  + abs( A[1] - A[2] ) + abs( A[2] - A[3] ) +............ + abs( A[N-2] - A[N-1] )    

Input:
First line contains number of test cases T. Each test cases contains two lines. First line contains an integer N, size of the array and second line contains N space separated elements of array A.   

Output:
For each test case print the index of the element in the array A, which if deleted, minimizes the value of the sum.. If there is multiple answer possible print the lowest index value.  

NOTE:
We are using is 0-based indexing for array.  

Constraints:
1 ≤ T ≤ 5
1<N ≤ 100000
1 ≤ Arri ≤ 10^9

SAMPLE INPUT
1
5
1 10 20 40 60

SAMPLE OUTPUT
4