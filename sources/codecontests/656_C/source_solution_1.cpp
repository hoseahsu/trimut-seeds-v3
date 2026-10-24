#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int x, i, j, k, ans = 0;
  for (auto ch : s) {
    if ((ch >= 'A') && (ch <= 'Z')) ans += ch - 'A' + 1;
    if ((ch >= 'a') && (ch <= 'z')) ans -= ch - 'a' + 1;
  }
  cout << ans << "\n";
  return 0;
}
