#include <bits/stdc++.h>
using namespace std;
const int N = 112345;
vector<long long> a(N);
int n;
int ans = (1 << 30) - 1;
void dfs(vector<long long> &v, int mx, int bits) {
  if (v.empty()) return;
  if ((int)(v).size() == 1) {
    ans = ((ans) < (mx) ? (ans) : (mx));
    return;
  }
  if (bits < 0) {
    ans = ((ans) < (mx) ? (ans) : (mx));
    return;
  }
  vector<long long> l, r;
  for (auto k : v) {
    if (k & (1 << bits))
      r.push_back(k & ((1 << bits) - 1));
    else
      l.push_back(k & ((1 << bits) - 1));
  }
  mx |= (1 << bits);
  if (l.empty() or r.empty()) mx ^= (1 << bits);
  dfs(l, mx, bits - 1);
  dfs(r, mx, bits - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  dfs(a, 0, 29);
  cout << ans << endl;
}
