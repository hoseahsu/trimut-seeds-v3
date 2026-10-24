#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s, h;
    cin >> s >> h;
    if (h.size() < s.size()) {
      cout << "NO" << endl;
      continue;
    }
    sort(s.begin(), s.end());
    int o = 0;
    for (int i = 0; i + s.size() - 1 < h.size(); i++) {
      string z;
      for (int j = i; j - i < s.size(); j++) {
        z += h[j];
      }
      sort(z.begin(), z.end());
      if (z == s) {
        o = 1;
        break;
      }
    }
    if (o == 1) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
