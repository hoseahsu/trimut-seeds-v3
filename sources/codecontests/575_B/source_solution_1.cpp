#include <bits/stdc++.h>
using namespace std;
struct edge {
  int a, b, x;
} e[100010];
int d[100010], E[2 * 100010], F[100010], L[100010], rmq[18][2 * 100010],
    repr[100010];
int s[10 * 100010], pre[2 * 100010], pw[10 * 100010];
int t, n, k;
vector<pair<int, int> > T[100010];
void euler(int x, int f) {
  d[x] = d[f] + 1;
  E[++t] = x;
  F[x] = t;
  for (int i = 0; i < T[x].size(); ++i) {
    int y = T[x][i].first;
    if (y != f) {
      repr[T[x][i].second] = y;
      euler(y, x);
      E[++t] = x;
    }
  }
  L[x] = t;
}
int lca(int a, int b) {
  a = F[a];
  b = F[b];
  if (a > b) swap(a, b);
  int l = log2(b - a + 1);
  if (d[rmq[l][a]] < d[rmq[l][b - (1 << l) + 1]]) return rmq[l][a];
  return rmq[l][b - (1 << l) + 1];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);
    e[i].a = a;
    e[i].b = b;
    e[i].x = x;
    T[a].push_back(make_pair(b, i));
    T[b].push_back(make_pair(a, i));
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &s[i]);
  }
  euler(1, 0);
  for (int i = 1; i <= t; ++i) {
    rmq[0][i] = E[i];
  }
  for (int i = 1; (1 << i) <= t; ++i) {
    for (int j = 1; j + (1 << i) - 1 <= t; ++j) {
      if (d[rmq[i - 1][j]] < d[rmq[i - 1][j + (1 << (i - 1))]])
        rmq[i][j] = rmq[i - 1][j];
      else
        rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
    }
  }
  pre[F[s[1]]]++;
  pre[F[1]]--;
  for (int i = 1; i < k; ++i) {
    int a = s[i];
    int b = s[i + 1];
    int l = lca(a, b);
    pre[F[l]] -= 2;
    pre[F[a]]++;
    pre[F[b]]++;
  }
  for (int i = 1; i <= t; ++i) pre[i] = pre[i - 1] + pre[i];
  pw[0] = 1;
  for (int i = 1; i <= k; ++i) {
    pw[i] = pw[i - 1] * 2;
    if (pw[i] >= 1000000007) pw[i] -= 1000000007;
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    int trav = pre[L[repr[i]]] - pre[F[repr[i]] - 1];
    if (e[i].x == 1) {
      if (d[e[i].a] < d[e[i].b]) {
        ans = (ans + pw[trav / 2] - 1);
        if (ans >= 1000000007) ans -= 1000000007;
        if (ans < 0) ans += 1000000007;
      } else {
        ans = (ans + pw[(trav + 1) / 2] - 1);
        if (ans >= 1000000007) ans -= 1000000007;
        if (ans < 0) ans += 1000000007;
      }
    }
  }
  cout << ans;
}
