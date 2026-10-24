#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

long long  mod = 1000000007;
ll dp[210][210];

int main(){
	ll m;
	cin >> m;
	vector<int> v;
	v.push_back(0);
	for(ll i=0;i<m;i++){
		char s;
		cin >> s;
		if(s=='U'){
			v.push_back(-1);
		}
		if(s=='D'){
			v.push_back(1);
		}
	}
	int n = v.size()-1;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(v[i]==-1){
				dp[i][j] = (dp[i][j]+dp[i-1][j]*j)%mod;
				if(j>=1)dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
			}else{
				dp[i][j] = (dp[i][j]+dp[i-1][j]*j)%mod;
				dp[i][j] = (dp[i][j]+dp[i-1][j+1]*(j+1)*(j+1))%mod;
			}
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}