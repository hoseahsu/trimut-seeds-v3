#include <bits/stdc++.h>
using namespace std;
const int N = 228228, INF = 1e9 + 228 + 666 + 1337;
int n, k, s, t;
int c[N], v[N], a[N];
bool can(int m) {
  int x = s;
  int i = k;
  int tim = 0;
  while (i >= 0 && x > 0) {
    int dist = x - a[i];
    if (m < dist) {
      return false;
    }
    int f = min(dist, m - dist);
    tim += (f + (dist - f) * 2);
    x = a[i];
    --i;
  }
  return tim <= t;
}
int main() {
  scanf("%d %d %d %d", &n, &k, &s, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &c[i], &v[i]);
  }
  vector<int> g(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &g[i]);
  }
  sort(g.begin(), g.end());
  for (int i = 0; i < k; ++i) {
    a[i + 1] = g[i];
  }
  int l = 0, r = INF;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (can(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  int vmin = r;
  int min_cost = INF;
  for (int i = 0; i < n; ++i) {
    if (v[i] >= vmin) {
      min_cost = min(min_cost, c[i]);
    }
  }
  if (min_cost == INF) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", min_cost);
  return 0;
}
