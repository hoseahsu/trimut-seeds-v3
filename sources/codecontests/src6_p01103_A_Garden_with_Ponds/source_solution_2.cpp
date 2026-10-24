#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int d, w;
int e[10][10];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> d >> w, d) {
        REP (i, d) REP (j, w) cin >> e[i][j];
        int ans = 0;
        REP (i, d) REP (j, w) FOR (k, i + 2, d) FOR (l, j + 2, w) {
            int minh = 10;
            FOR (y, i, k + 1) minh = min({minh, e[y][j], e[y][l]});
            FOR (x, j, l + 1) minh = min({minh, e[i][x], e[k][x]});
            int sum = 0, ok = 1;
            FOR (y, i + 1, k) FOR (x, j + 1, l) {
                sum += minh - e[y][x];
                if (e[y][x] >= minh) ok = 0;
            }
            if (ok) ans = max(ans, sum);
        }
        cout << ans << endl;
    }
}
