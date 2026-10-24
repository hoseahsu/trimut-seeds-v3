#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, a[N], b[N];
double dp[N][N * N];
int main() {
    cin >> n;
    int S = 0, sb = 0;
    for(int i = 1; i <= n; i++) { cin >> a[i] >> b[i]; S += a[i]; sb += b[i]; }
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= S; j++) dp[i][j] = -1.0;
    dp[n][S] = sb;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            for(int k = a[i]; k <= S; k++) if(dp[j][k] >= 0) {
                dp[j - 1][k - a[i]] = max(dp[j - 1][k - a[i]], dp[j][k] - b[i] / 2.0);
                if(dp[j - 1][k - a[i]] > k - a[i]) dp[j - 1][k - a[i]] = k - a[i];
                // cout << i << ": " << j - 1 << " " << k - a[i] << " " << dp[j - 1][k - a[i]] << endl;
            }
    }
    cout << fixed << setprecision(9);
    for(int i = 1; i <= n; i++) {
        double mx = 0.;
        for(int j = 0; j <= S; j++) mx = max(mx, dp[i][j]);
        cout << mx << " ";
    } cout << endl;
    return 0;
}
