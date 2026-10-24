#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
	vector<vector<int>> deg(n + 1, vector<int>(n + 1));
	for (int i = 0; i < n; i++) dp[i][i + 1] = 0, deg[i][i + 1] = i;
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l <= n; i++) {
			int j = i + l;
			for (int k = max(i + 1, deg[i][j - 1]); k <= min(j - 1, deg[i + 1][j]); k++) {
				int val = dp[i][k] + dp[k][j] + (x[k] - x[i]) + (y[k - 1] - y[j - 1]);
				if (val < dp[i][j]) {
					dp[i][j] = val;
					deg[i][j] = k;
				}
			}
		}
	}
	cout << dp[0][n] << endl;
	return 0;
}

