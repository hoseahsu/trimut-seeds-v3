#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
using vi = vector<int>;
struct segtree {
  vector<int> t;
  int n;
  segtree() {}
  int combine(int a, int b) { return max(a, b); }
  void build(int m) {
    vector<int> a(m);
    iota((a).begin(), (a).end(), 0);
    n = a.size();
    t.resize(2 * n);
    for (int i = 0; i < n; i++) t[i + n] = a[i];
    for (int i = n - 1; i > 0; i--) t[i] = combine(t[i << 1], t[i << 1 | 1]);
  }
  void update(int p, int x) {
    for (t[p += n] = x; p >>= 1;) t[p] = combine(t[p << 1], t[p << 1 | 1]);
  }
  int query(int l, int r) {
    int resl = 0, resr = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = combine(resl, t[l++]);
      if (r & 1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};
void solve() {
  int n;
  cin >> n;
  vector<ppi> dom(n);
  for (int i = 0; i < n; i++) {
    pii p;
    cin >> p.first >> p.second;
    dom[i] = make_pair(p, i);
  }
  vector<int> ans(n, 1);
  segtree tree;
  tree.build(n);
  sort((dom).begin(), (dom).end());
  for (int i = n - 1; i >= 0; i--) {
    ppi p = dom[i];
    p.first.first += p.first.second - 1;
    p.first.second = 1e9;
    int j = upper_bound((dom).begin(), (dom).end(), p) - dom.begin();
    ;
    j = tree.query(i, j - 1);
    tree.update(i, j);
    ans[p.second] = j - i + 1;
  };
  for (int i = 0; i < n; i++)
    ;
  for (int i : ans) cout << i << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
}
