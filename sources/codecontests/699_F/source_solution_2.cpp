#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9 + 7;
const int N = (int)2e3 + 4;
const int K = 8;
int n, k;
int a[N], b[N], p[K];
bool to[N];
bool h[N];
vector<int> v[K][N];
long long psevdo(int x, int y, int z) {
  pair<int, int> v1 = make_pair(a[y] - a[x], b[y] - b[x]);
  pair<int, int> v2 = make_pair(a[z] - a[x], b[z] - b[x]);
  return v1.first * 1LL * v2.second - v1.second * 1LL * v2.first;
}
long long dist(int x, int y) {
  return (a[x] - a[y]) * 1LL * (a[x] - a[y]) +
         (b[x] - b[y]) * 1LL * (b[x] - b[y]);
}
bool dfs(int mask, vector<int> need) {
  if (need.empty()) {
    return 1;
  }
  if (need.size() > k) {
    return 0;
  }
  for (int i = 1; i <= k; ++i) {
    if ((mask & (1 << i)) == 0) {
      vector<int> ned = need;
      int x = ned.back();
      ned.pop_back();
      vector<int> d;
      for (auto &y : v[i][x]) {
        if (!h[y]) {
          h[y] = 1;
          d.push_back(y);
          ned.push_back(y);
          if (ned.size() > k) {
            break;
          }
        }
      }
      if (dfs(mask | (1 << i), ned)) {
        h[x] = 0;
        return 1;
      }
      for (auto &x : d) {
        h[x] = 0;
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= n + k; ++i) {
    scanf("%d%d", a + i, b + i);
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = k + 1; j <= n + k; ++j) {
      for (int t = k + 1; t <= n + k; ++t) {
        if (t != j && psevdo(i, j, t) == 0 && dist(t, i) < dist(i, j) &&
            dist(t, j) < dist(i, j)) {
          v[i][j].push_back(t);
        }
      }
    }
  }
  int ans = 0;
  for (int i = k + 1; i <= n + k; ++i) {
    h[i] = 1;
    ans += dfs(0, vector<int>(1, i));
    h[i] = 0;
  }
  printf("%d", ans);
  return 0;
}
