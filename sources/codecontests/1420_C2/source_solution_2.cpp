#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
int tc, n, q;
int a[300005];
ll t[4][1200005];
void build(int v, int vl, int vr) {
  if (vl == vr) {
    t[1][v] = a[vl];
    t[2][v] = -a[vl];
    t[0][v] = t[3][v] = -3e6;
    return;
  }
  int m = (vl + vr) >> 1;
  build(2 * v, vl, m);
  build(2 * v + 1, m + 1, vr);
  t[0][v] = max({t[0][2 * v] + t[0][2 * v + 1], t[1][2 * v] + t[2][2 * v + 1],
                 t[0][2 * v], t[0][2 * v + 1]});
  t[1][v] = max({t[0][2 * v] + t[1][2 * v + 1], t[1][2 * v] + t[3][2 * v + 1],
                 t[1][2 * v], t[1][2 * v + 1]});
  t[2][v] = max({t[2][2 * v] + t[0][2 * v + 1], t[3][2 * v] + t[2][2 * v + 1],
                 t[2][2 * v], t[2][2 * v + 1]});
  t[3][v] = max({t[2][2 * v] + t[1][2 * v + 1], t[3][2 * v] + t[3][2 * v + 1],
                 t[3][2 * v], t[3][2 * v + 1]});
}
void upd(int v, int vl, int vr, int i, int x) {
  if (vl == vr) {
    t[1][v] = x;
    t[2][v] = -x;
    t[0][v] = t[3][v] = -3e6;
    return;
  }
  int m = (vl + vr) >> 1;
  if (i <= m) {
    upd(2 * v, vl, m, i, x);
  } else {
    upd(2 * v + 1, m + 1, vr, i, x);
  }
  t[0][v] = max({t[0][2 * v] + t[0][2 * v + 1], t[1][2 * v] + t[2][2 * v + 1],
                 t[0][2 * v], t[0][2 * v + 1]});
  t[1][v] = max({t[0][2 * v] + t[1][2 * v + 1], t[1][2 * v] + t[3][2 * v + 1],
                 t[1][2 * v], t[1][2 * v + 1]});
  t[2][v] = max({t[2][2 * v] + t[0][2 * v + 1], t[3][2 * v] + t[2][2 * v + 1],
                 t[2][2 * v], t[2][2 * v + 1]});
  t[3][v] = max({t[2][2 * v] + t[1][2 * v + 1], t[3][2 * v] + t[3][2 * v + 1],
                 t[3][2 * v], t[3][2 * v + 1]});
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    build(1, 1, n);
    int l, r;
    cout << max({t[0][0], t[1][1], t[2][1], t[3][1]}) << '\n';
    while (q--) {
      cin >> l >> r;
      upd(1, 1, n, l, a[r]);
      upd(1, 1, n, r, a[l]);
      swap(a[l], a[r]);
      cout << max({t[0][0], t[1][1], t[2][1], t[3][1]}) << '\n';
    }
  }
  return 0;
}
