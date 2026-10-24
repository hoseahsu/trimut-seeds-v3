#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct BIT {
  int n;
  double b[N];
  void init(int _n) {
    n = _n;
    for (int i = 0; i <= n; i++) b[i] = 0.0;
  }
  void add(int i, double x) {
    for (; i <= n; i += i & -i) {
      b[i] += x;
    }
  }
  double sum(int i) {
    double s = 0.0;
    for (; i > 0; i -= i & -i) {
      s += b[i];
    }
    return s;
  }
} B;
int n, q, u, v, t, L[N], R[N], fa[N];
double x, p[N], dp[N][2];
vector<int> G[N];
void dfs(int u, int f) {
  fa[u] = f;
  L[u] = ++t;
  dp[u][0] = 0.0;
  dp[u][1] = 1.0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == f) continue;
    dfs(v, u);
    dp[u][0] += p[v] * dp[v][1] + (1.0 - p[v]) * dp[v][0];
    dp[u][1] += p[v] * (dp[v][1] - 1.0) + (1.0 - p[v]) * dp[v][0];
  }
  R[u] = t;
}
double get_ans() {
  double sum = B.sum(n) - B.sum(1);
  double dp0 = dp[0][0] + sum;
  double dp1 = dp[0][1] + sum;
  return p[0] * dp1 + (1.0 - p[0]) * dp0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &p[i]);
    p[i] = 1.0 - p[i];
  }
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  t = 0;
  dfs(0, -1);
  B.init(n);
  scanf("%d", &q);
  while (q--) {
    scanf("%d %lf", &v, &x);
    x = 1.0 - x;
    if (v != 0) {
      double det = x - p[v];
      double sum = B.sum(R[v]) - B.sum(L[v]);
      double dp0 = dp[v][0] + sum;
      double dp1 = dp[v][1] + sum;
      u = fa[v];
      dp[u][0] += det * (dp1 - dp0);
      dp[u][1] += det * (dp1 - dp0 - 1);
      B.add(L[u], det * (dp1 - dp0 - p[u]));
    }
    p[v] = x;
    printf("%.6f\n", get_ans());
  }
}
