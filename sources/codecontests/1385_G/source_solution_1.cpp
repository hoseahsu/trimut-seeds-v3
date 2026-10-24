#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<vector<int>> ind(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ind[a[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    ind[b[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (ind[i].size() != 2) {
      cout << "-1\n";
      return;
    }
  }
  vector<bool> used(n);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    used[i] = true;
    pair<int, int> p{a[i], b[i]};
    vector<int> fi, si;
    si.push_back(i);
    while (p.first != p.second) {
      int i1 = used[ind[p.first][0]] ? ind[p.first][1] : ind[p.first][0];
      int i2 = used[ind[p.second][0]] ? ind[p.second][1] : ind[p.second][0];
      if (a[i1] == p.first) {
        p.first = b[i1];
        fi.push_back(i1);
      } else {
        p.first = a[i1];
        si.push_back(i1);
      }
      used[i1] = true;
      if (i1 == i2) break;
      if (b[i2] == p.second) {
        p.second = a[i2];
        fi.push_back(i2);
      } else {
        p.second = b[i2];
        si.push_back(i2);
      }
      used[i2] = true;
    }
    if (fi.size() < si.size())
      for (int i = 0; i < fi.size(); i++) ans.push_back(fi[i]);
    else
      for (int i = 0; i < si.size(); i++) ans.push_back(si[i]);
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(12);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
