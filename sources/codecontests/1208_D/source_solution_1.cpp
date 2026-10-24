#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e6 + 5;
long long tree[4 * maxn], lazy[4 * maxn], a[maxn];
int kq[maxn];
int n;
void down(int g) {
  if (lazy[g] != 0) {
    tree[g << 1] += lazy[g];
    lazy[g << 1] += lazy[g];
    tree[(g << 1) | 1] += lazy[g];
    lazy[(g << 1) | 1] += lazy[g];
    lazy[g] = 0;
  }
}
void buld(int g, int l, int r) {
  if (l == r) {
    tree[g] = a[l];
  } else {
    int m = (l + r) >> 1;
    buld(g << 1, l, m);
    buld((g << 1) | 1, m + 1, r);
    tree[g] = min(tree[g << 1], tree[(g << 1) | 1]);
  }
}
void update(int g, int l, int r, int u, int v, long long val) {
  if (r < u || v < l) return;
  if (u <= l && r <= v) {
    tree[g] += val;
    lazy[g] += val;
  } else {
    down(g);
    int m = (l + r) >> 1;
    update(g << 1, l, m, u, v, val);
    update((g << 1) | 1, m + 1, r, u, v, val);
    tree[g] = min(tree[g << 1], tree[(g << 1) | 1]);
  }
}
int find_zero(int g, int l, int r) {
  if (l == r)
    return l;
  else {
    down(g);
    int m = (l + r) >> 1;
    int res = -1;
    if (tree[(g << 1) | 1] == 0)
      res = find_zero((g << 1) | 1, m + 1, r);
    else
      res = find_zero(g << 1, l, m);
    tree[g] = min(tree[g << 1], tree[(g << 1) | 1]);
    return res;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  buld(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int pos = find_zero(1, 1, n);
    kq[pos] = i;
    update(1, 1, n, pos, pos, 1e18);
    update(1, 1, n, pos + 1, n, -i);
  }
  for (int i = 1; i <= n; i++) cout << kq[i] << " ";
  return 0;
}
