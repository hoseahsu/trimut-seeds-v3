#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define int long long
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define all(x) x.begin(), x.end()
using pii = pair<int, int>;
using ll = long long;
ll dp[55][5];  // dp[i][j]=風船をj個盛った状態でi個目の風船を受け取るまでの移動距離
int X[55], T[55];

const ll INF = 1e18;
bool solve() {
    int N;
    cin >> N;
    if (N == 0) return false;

    REP(i, N) { cin >> X[i] >> T[i]; }
    REP(i, N + 1) { REP(k, 4) dp[i][k] = INF; }
    dp[0][0] = 0;
    int nowt = 0;
    int nowx = 0;
    REP(i, N) {
        if (i == 0)
            nowt = 0;
        else
            nowt = T[i - 1];
        if (i == 0)
            nowx = 0;
        else
            nowx = X[i - 1];
        REP(j, 4) {
            //いったん帰る
            {
                int need = nowx * (j + 1);
                need += X[i];
                if (nowt + need <= T[i] && dp[i][j] + nowx + X[i] < dp[i + 1][1]) {
                    dp[i + 1][1] = dp[i][j] + nowx + X[i];
                }
            }

            //そのまま取りに行く
            if (j <= 2) {
                int need = abs(X[i] - nowx) * (j + 1);
                if (nowt + need <= T[i] && dp[i][j] + abs(X[i] - nowx) < dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j] + abs(X[i] - nowx);
                }
            }
        }
    }
    ll ans = INF;
    REP(j, 4) {
        if (dp[N][j] < INF) {
            ans = min(ans, dp[N][j] + X[N - 1]);
        }
    }
    if (ans < INF) {
        cout << "OK"
             << " " << ans << endl;
    } else {
        cout << "NG ";
        FOR(i, 1, N + 1) {
            bool ok = false;
            REP(j, 4) {
                if (dp[i][j] < INF) ok = true;
            }
            if (!ok) {
                cout << i << endl;
                break;
            }
        }
    }
    return true;
}

signed main() {
    while (solve())
        ;
}
