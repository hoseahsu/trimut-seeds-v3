Navi is at the Beer Bar where he has ordered N beers. After seeing his love with the beers, Bar's Manager has decided to make as much money as they can by asking Navi to pay  K * i^3 Rupees for the i^th beer. But Navi has only M Rupees in his purse. So you are required to lent him some money so that he can still be able to pay for all of the N beers.

Input:

First line will contain T (No. of test cases).
Each test case will contain only one line having three space separated integers : N, K and M
Output:

For every test case, print the required answer in a new line.

Constraints: 
1 ≤ T ≤ 10^5
1 ≤ N, K ≤ 10^3
1 ≤ M ≤ 10^6
Sample Code:

  #include <iostream>
    using namespace std;

    int main()
    {
        //taking input for number of test cases, T.
        cin>>T;

        //For every test case, taking input for N , K and M.
        cin>>N>>K>>M;
        //let the answer be in variable **Ans**
        cout << Ans << endl; //print your answer for every test case.
        return 0;
    }

SAMPLE INPUT
1
2 2 10

SAMPLE OUTPUT
8

Explanation

Total Money required is : 2 * 1^3 + 2 * 2^3 = 18 but he already has 10 so ans is 8.