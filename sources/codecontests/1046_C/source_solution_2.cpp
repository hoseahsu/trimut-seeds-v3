#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (long long i = 0, _ = n; i < _; i++) cin >> a[i];
  map<int, int> p;
  int tar;
  cin >> tar;
  tar += a[d - 1];
  for (long long i = 0, _ = n - 1; i < _; i++) {
    int x;
    cin >> x;
    p[x]++;
  }
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i == d - 1) continue;
    auto it = p.lower_bound(tar - a[i]);
    if (it == p.end()) {
      ans++;
      it--;
      it->second--;
      if (it->second == 0) {
        p.erase(it);
      }
    } else if (it->first + a[i] == tar) {
      ans++;
      it->second--;
      if (it->second == 0) {
        p.erase(it);
      }
    } else if (it != p.begin()) {
      ans++;
      it--;
      it->second--;
      if (it->second == 0) {
        p.erase(it);
      }
    } else {
      break;
    }
  }
  cout << n - ans << endl;
  return 0;
}
