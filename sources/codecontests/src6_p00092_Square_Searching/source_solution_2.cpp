#include<iostream>
#include<algorithm>
#include<string>
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
string map[1234];
int dp[1234][1234];
signed main() {
	int n; while (cin >> n, n) {
		int ans = 0;
		for0(i, n)cin >> map[i];
		for1(i, n)for1(j, n) {
			if (map[i - 1][j - 1] == '*')dp[i][j] = 0;
			else dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1],dp[i][j - 1] })+1;
			ans = max(ans, dp[i][j]);
		}
		cout << ans << endl;
	}
}
