#include <bits/stdc++.h>
using namespace std;
int way[5005][5005];
const int mod = 1000000007;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  for (int i = n - 1; i >= 0; i--) {
    way[i][m] = way[n][m] = 0;
    for (int j = m - 1; j >= 0; j--) {
      way[n][j] = 0;
      if (s[i] == t[j])
        way[i][j] = (way[i + 1][j + 1] + way[i][j + 1] + 1) % mod;
      else
        way[i][j] = way[i][j + 1];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = (ans + way[i][0]) % mod;
  cout << ans << endl;
  cin >> s;
  return 0;
}
