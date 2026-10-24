#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const long long inf = 2e6;
const long long mod = 1e9 + 7;
const int N = 3e5 + 11;
const long long INF64 = 3e18 + 1;
const double eps = 1e-14;
const double PI = acos(-1);
int n, m, a[N], q;
struct yes {
  long long pp, pm, make_pair, mm;
};
yes t[4 * N];
yes merge(yes a, yes b) {
  yes c;
  c.pp = max({max(a.pp, b.pp), a.pp + b.make_pair, a.pm + b.pp});
  c.make_pair = max(
      {max(a.make_pair, b.make_pair), a.make_pair + b.make_pair, a.mm + b.pp});
  c.pm = max({max(a.pm, b.pm), a.pp + b.mm, a.pm + b.pm});
  c.mm = max({max(a.mm, b.mm), a.mm + b.pm, a.make_pair + b.mm});
  return c;
}
void update(int v, int l, int r, int pos, int val) {
  if (l == r) {
    t[v].pp = val;
    t[v].pm = -INF64;
    t[v].make_pair = -INF64;
    t[v].mm = -val;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(2 * v, l, mid, pos, val);
  else
    update(2 * v + 1, mid + 1, r, pos, val);
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, i, 0);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(1, 1, n, i, a[i]);
  }
  cout << t[1].pp << '\n';
  while (q--) {
    int l, r;
    cin >> l >> r;
    update(1, 1, n, l, a[r]);
    update(1, 1, n, r, a[l]);
    swap(a[l], a[r]);
    cout << t[1].pp << '\n';
  }
}
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
