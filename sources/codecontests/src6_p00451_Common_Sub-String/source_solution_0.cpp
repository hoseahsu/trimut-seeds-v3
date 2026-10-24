#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define int long long
#define mod 1000000007
using namespace std;
string s, t;
int dp[4005][4005], ans;
signed main() {
	while (cin >> s >> t) {
		for (int i = 0; i <= 4000; i++)for (int j = 0; j <= 4000; j++)dp[i][j] = 0;
		ans = 0;
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= t.size(); j++) {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					ans = max(dp[i][j], ans);
				}
			}
		}
		cout << ans << endl;
	}
}
