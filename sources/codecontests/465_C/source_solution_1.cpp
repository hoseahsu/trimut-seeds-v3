#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  s = 'a' + s;
  for (long long i = n; i >= 1; i--) {
    long long tt = s[i] - 'a';
    for (long long j = tt + 1; j < p; j++) {
      bool f1 = true;
      char c = (char)(j + 'a');
      if (i != 1) {
        if (c == s[i - 1]) f1 = false;
      }
      if (i >= 3) {
        if (c == s[i - 2]) f1 = false;
      }
      if (f1 == true) {
        s[i] = c;
        for (long long j = i + 1; j <= n; j++) {
          for (long long k = 0; k < p; k++) {
            bool f2 = true;
            c = (char)(k + 'a');
            if (j != 1) {
              if (c == s[j - 1]) f2 = false;
            }
            if (j >= 3) {
              if (c == s[j - 2]) f2 = false;
            }
            if (f2) {
              s[j] = c;
              break;
            }
          }
        }
        s = s.substr(1, n);
        cout << s << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
