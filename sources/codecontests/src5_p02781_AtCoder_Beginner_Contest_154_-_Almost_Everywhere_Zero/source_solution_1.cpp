#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

int solve(const string &n, int k) {
    int m = n.length();

    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
    dp[0][0][0] = 1;
    rep(i, 0, m) {
        int d = n[i] - '0';
        rep(flag, 0, 2) rep(j, 0, k + 1) rep(l, 0, (flag ? 10 : d + 1)) {
            dp[i + 1][flag || (l < d)][(l != 0 ? j + 1 : j)] += dp[i][flag][j];
        }
    }

    return dp[m][0][k] + dp[m][1][k];
}

int main() {
    string n;
    cin >> n;

    int k;
    cin >> k;

    cout << solve(n, k) << endl;
    
    return 0;
}