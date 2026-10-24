#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, t, su;
    cin >> s >> t;
    sort(s.begin(), s.end());
    long long int i, c = 0;
    if (t.size() >= s.size()) {
      for (i = 0; i <= (t.size() - s.size()); i++) {
        su = t.substr(i, s.size());
        sort(su.begin(), su.end());
        if (su == s) {
          c = 1;
          break;
        }
      }
      if (c == 0)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
