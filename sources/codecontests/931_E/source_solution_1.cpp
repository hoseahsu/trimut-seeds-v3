#include <bits/stdc++.h>
using namespace std;
;
bool ch[26];
int is[26], a[5000], coun[26];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  for (int i = (0); i < (n); ++i) {
    a[i] = s[i] - 'a';
  };
  int m = 0;
  for (int c = (0); c < (26); ++c) {
    int mx = 0;
    for (int s = (1); s < (n); ++s) {
      vector<int> is(26, 0);
      for (int i = (0); i < (n); ++i) {
        if (a[i] == c) is[a[(i + s) % n]]++;
      }
      int cur = 0;
      for (int i = (0); i < (26); ++i) cur += (is[i] == 1);
      mx = max(mx, cur);
    }
    m += mx;
  }
  cout << 1.0 * m / n << endl;
  return 0;
}
