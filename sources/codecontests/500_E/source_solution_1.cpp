#include <bits/stdc++.h>
using namespace std;
int n;
int x[411111], d[411111];
int go[20][411111], w[20][411111];
int ma[20][411111];
int comp(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  if (x[a] + d[a] > x[b] + d[b]) return a;
  return b;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &d[i]);
  for (int i = 0; i < n; i++) ma[0][i] = i;
  for (int i = 1; i < 20; i++)
    for (int j = 0; j < n; j++)
      if (j + (1ll << (i)) <= n) {
        int a = ma[i - 1][j];
        int b = ma[i - 1][j + (1ll << (i - 1))];
        ma[i][j] = comp(a, b);
      }
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      go[0][i] = i;
      w[0][i] = 0;
      continue;
    }
    if (x[i] + d[i] < x[i + 1]) {
      go[0][i] = i + 1;
      w[0][i] = x[i + 1] - (x[i] + d[i]);
      continue;
    }
    int best = -1;
    int t = i + 1;
    for (int j = 19; j >= 0; j--)
      if (t + (1ll << (j)) <= n && x[t + (1ll << (j)) - 1] <= x[i] + d[i]) {
        best = comp(best, ma[j][t]);
        t += (1ll << (j));
      }
    if (comp(best, i) == i) {
      if (t == n) {
        go[0][i] = i;
        w[0][i] = 0;
      } else {
        go[0][i] = t;
        w[0][i] = x[t] - (x[i] + d[i]);
      }
    } else {
      go[0][i] = best;
      w[0][i] = 0;
    }
  }
  for (int i = 1; i < 20; i++)
    for (int j = 0; j < n; j++) {
      go[i][j] = go[i - 1][go[i - 1][j]];
      w[i][j] = w[i - 1][j] + w[i - 1][go[i - 1][j]];
    }
  int m;
  cin >> m;
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    int ans = 0;
    for (int i = 19; i >= 0; i--)
      if (go[i][a] <= b) {
        ans += w[i][a];
        a = go[i][a];
      }
    if (x[a] + d[a] < x[b]) ans += x[b] - (x[a] + d[a]);
    printf("%d\n", ans);
  }
  return 0;
}
