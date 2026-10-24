#include <bits/stdc++.h>
using namespace std;
vector<long long> applyOnce(const vector<long long> &a) {
  vector<long long> ans(a.size());
  long long mx = numeric_limits<long long>::min();
  for (int i = 0; i < a.size(); i++) {
    mx = max(mx, a[i]);
  }
  for (int i = 0; i < a.size(); i++) {
    ans[i] = mx - a[i];
  }
  return ans;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto odd = applyOnce(a);
  auto even = applyOnce(odd);
  if (k % 2 == 1) {
    for (auto it : odd) cout << it << " ";
  } else {
    for (auto it : even) cout << it << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
