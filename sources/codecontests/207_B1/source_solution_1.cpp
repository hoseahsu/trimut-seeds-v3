#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250000;
const int MAXLOG = 21;
int a[MAXN * 2 + 10], Fa[MAXN * 2 + 10][MAXLOG + 1];
pair<int, int> Min[MAXN * 2 * 4 + 10];
void build(int u, int l, int r) {
  if (l == r) {
    Min[u] = make_pair(max(1, l - a[l]), l);
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  Min[u] = min(Min[u << 1], Min[u << 1 | 1]);
}
pair<int, int> Query(int u, int l, int r, int L, int R) {
  if (L <= l && r <= R) return Min[u];
  int mid = (l + r) >> 1;
  pair<int, int> ret = make_pair(0x3f3f3f3f, 0);
  if (L <= mid) ret = min(ret, Query(u << 1, l, mid, L, R));
  if (R > mid) ret = min(ret, Query(u << 1 | 1, mid + 1, r, L, R));
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[n + i] = a[i];
  }
  build(1, 1, 2 * n);
  for (int i = 2 * n; i >= 1; i--)
    Fa[i][0] = Query(1, 1, 2 * n, max(1, i - a[i]), i).second;
  for (int j = 1; j <= MAXLOG; j++)
    for (int i = 1; i <= 2 * n; i++) Fa[i][j] = Fa[Fa[i][j - 1]][j - 1];
  long long sum = 0;
  for (int i = 2 * n; i > n; i--) {
    if (i - a[i] <= i - n + 1) {
      sum++;
      continue;
    }
    int tar = i - n + 1, ans = 0, cur = i;
    for (int j = MAXLOG; j >= 0; j--) {
      if (Fa[cur][j] - a[Fa[cur][j]] > tar) {
        ans += (1 << j);
        cur = Fa[cur][j];
      }
    }
    sum += ans + 2;
  }
  printf("%I64d\n", sum);
  return 0;
}
