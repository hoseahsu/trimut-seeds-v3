#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
int32_t main() {
	int n, m; cin>>n>>m;
	vector<int> dp(n + 1);
	map<int, int> broken;
	for(int i = 0; i < m; i++){
		int x; cin>>x;
		broken[x] = 1;
	}
	dp[0] = 1;
	dp[1] = (broken[1] ? 0 : 1);
	for(int i = 2; i <= n; ++i){
		if(broken[i]) dp[i] = 0;
		else dp[i] = (dp[i-1] + dp[i-2]) % mod;
	}
	cout<<dp[n]<<endl;
}
