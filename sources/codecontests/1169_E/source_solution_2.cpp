#include <bits/stdc++.h>
using namespace std;
int tree[1500005][25], w[300005], n, m;
void build(int v, int l, int r) {
  if (l == r) {
    for (int i = 0; i <= 20; i++)
      if (w[l] & (1 << i)) tree[v][i] = w[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(v << 1, l, mid), build(v << 1 | 1, mid + 1, r);
  for (int i = 0; i <= 20; i++) {
    tree[v][i] = tree[v << 1][i];
    for (int j = 0; j <= 20; j++)
      if (tree[v << 1][i] & (1 << j)) tree[v][i] |= tree[v << 1 | 1][j];
    tree[v][i] |= tree[v << 1 | 1][i];
  }
}
int query(int v, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    int pp = z;
    for (int i = 0; i <= 20; i++)
      if (pp >> i & 1) z |= tree[v][i];
    return z;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) z = query(v << 1, l, mid, x, min(y, mid), z);
  if (y > mid) z = query(v << 1 | 1, mid + 1, r, max(x, mid + 1), y, z);
  return z;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  build(1, 1, n);
  for (int i = 1, x, y, z; i <= m; i++) {
    scanf("%d%d", &x, &y), z = query(1, 1, n, x + 1, y, w[x]);
    printf((z & w[y]) ? "Shi\n" : "Fou\n");
  }
  return 0;
}
