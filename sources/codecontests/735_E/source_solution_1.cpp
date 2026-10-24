#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-8;
const int dx4[4] = {1, 0, 0, -1};
const int dy4[4] = {0, -1, 1, 0};
const int inf = 0x3f3f3f3f;
const int MOD = 1E9 + 7;
const int N = 105;
int n, k, ans, f[N][50], g[50];
vector<int> edge[N];
int F(int x) { return x + k; }
int Add(long long x, long long y) { return (x + y) % MOD; }
int Mul(long long x, long long y) { return x * y % MOD; }
void dfs(int u, int pre) {
  f[u][F(-k)] = f[u][F(1)] = 1;
  for (auto v : edge[u]) {
    if (v == pre) continue;
    dfs(v, u);
    memset(g, 0, sizeof(g));
    for (int i = -k; i <= k; i++) {
      if (!f[u][F(i)]) continue;
      for (int j = -k; j <= k; j++) {
        int t = Mul(f[u][F(i)], f[v][F(j)]);
        if (i <= 0 && j <= 0) {
          int A = min(i, j + 1);
          g[F(A)] = Add(g[F(A)], t);
        } else if (i > 0 && j > 0) {
          int A = max(i, j + 1);
          g[F(A)] = Add(g[F(A)], t);
        } else if (i <= 0 && j > 0) {
          int A = (-i >= j) ? i : j + 1;
          g[F(A)] = Add(g[F(A)], t);
        } else if (i > 0 && j <= 0) {
          int A = (-j >= i) ? j + 1 : i;
          g[F(A)] = Add(g[F(A)], t);
        }
      }
    }
    memcpy(f[u], g, sizeof(g));
  }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(1, -1);
  for (int i = 0; i <= k; i++) ans = (ans + f[1][i]) % MOD;
  cout << ans << endl;
  return 0;
}
