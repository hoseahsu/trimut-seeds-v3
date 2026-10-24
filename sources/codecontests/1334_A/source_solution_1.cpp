#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, p, c;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
      cin >> p >> c;
      v.push_back({p, c});
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (i + 1 < n && v[i].first == v[i + 1].first &&
          v[i].second == v[i + 1].second)
        continue;
      if ((i + 1 < n && v[i].first > v[i + 1].first) ||
          (i + 1 < n && v[i].second > v[i + 1].second) ||
          v[i].first < v[i].second ||
          (i + 1 < n &&
           (v[i + 1].first - v[i].first) < (v[i + 1].second - v[i].second))) {
        ok = 0;
        break;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
