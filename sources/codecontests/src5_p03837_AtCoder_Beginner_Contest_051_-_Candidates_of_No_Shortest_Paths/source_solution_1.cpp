#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, u[1003] = {}, v[1003] = {}, w[1003] = {}, z = 0, d[102][102] = {};
    vector<pii> g[102] = {};
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) d[i][j] = 890328;
    for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> w[i], d[u[i]][v[i]] = d[v[i]][u[i]] = w[i];
    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 0; i < m; i++) if (d[u[i]][v[i]] < w[i]) z++;
    cout << z;
}
