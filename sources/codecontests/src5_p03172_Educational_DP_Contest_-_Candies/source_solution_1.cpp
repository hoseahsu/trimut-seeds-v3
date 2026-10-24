#include <bits/stdc++.h>
using namespace std;
int n , TotalK , a[110];
long long dp[101][100010] , mod = 1e9 + 7;

int main()
{
    cin >> n >> TotalK;
    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    dp[n][0] = 1;
    for(int i = n-1 ; i >= 0 ; i--)
        for(int k = 0 ; k <= TotalK ; k++)
            dp[i][k] = ((dp[i+1][k] + (k?dp[i][k-1]:0))%mod + (k > a[i] ? mod - dp[i+1][k-a[i]-1] : 0))%mod;
    cout << dp[0][TotalK] << '\n';
    return 0;
}
