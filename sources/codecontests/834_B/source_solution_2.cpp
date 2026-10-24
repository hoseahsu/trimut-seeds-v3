#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  map<char, int> m;
  set<int> s;
  cin >> n >> k;
  char a[n];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) m[a[i]] = i;
  for (int i = 1; i <= n; i++) {
    s.insert(a[i]);
    if (s.size() > k) {
      cout << "YES" << endl;
      return;
    } else {
      if (i == m[a[i]]) {
        s.erase(a[i]);
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long T;
  T = 1;
  for (int t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
