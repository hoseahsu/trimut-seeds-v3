#include <bits/stdc++.h>
using namespace std;
void InOut();
const int maxn = 100010;
const int inf = 0x3f3f3f3f;
int n, m, k;
string s;
int cnt[2];
void solve() {
  cin >> n;
  cin >> s;
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    cnt[(s[i] - '0') % 2]++;
  }
  if (cnt[1] <= 1) {
    cout << -1 << '\n';
  } else {
    cnt[1] -= cnt[1] % 2;
    for (int i = 0; i < n; ++i) {
      if (s[i] % 2) {
        if (cnt[1] > 0) cout << s[i];
        --cnt[1];
      }
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
void InOut() {
  freopen(
      "abc"
      ".inp",
      "r", stdin);
  freopen(
      "abc"
      ".out",
      "w", stdout);
}
