#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, k, a[105];
using ll = long long;
ll dp[105][100005];

int main()
{
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) 
	    cin>>a[i];
	
	dp[0][0] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		ll pre = 0;
		for(int j = 0; j <= k; j++)
		{
			//dp[i][j] <- dp[i-1][j-a[i]] + ..... + dp[i-1][j]
			pre += dp[i - 1][j];
			if(j - a[i] - 1 >= 0) 
			    pre -= dp[i-1][j-a[i]-1];
			
			pre = (pre + mod)%mod;
			dp[i][j] = pre;
		}
	}
	
	cout << dp[n][k] << endl;
	
	return 0;
}