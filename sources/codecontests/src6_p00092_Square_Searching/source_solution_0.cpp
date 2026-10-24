#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[3000][3000], n, x[3000][3000], maxn; char a;
int main() {
	while (true) {
		memset(dp, 0, sizeof(dp));
		cin >> n; if (!n) { break; }
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a;
				if (a == '*') {
					x[i][j] = 1;
				}
				else { x[i][j] = 0; }
			}
		}
		maxn = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (x[i][j] == 1) { dp[i][j] = 0; }
				else {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
				maxn = max(maxn, dp[i][j]);
			}
		}
		cout << maxn << endl;
	}
}