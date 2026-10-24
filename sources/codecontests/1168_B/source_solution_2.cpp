#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long int ans = 0;
  long long int n = s.size();
  vector<long long int> v(n + 1, n);
  for (long long int i = n - 1; i >= 0; i--) {
    v[i] = v[i + 1];
    for (int j = 1; i + 2 * j < v[i]; j++) {
      if (s[i] == s[i + j] && s[i + j] == s[i + 2 * j]) {
        v[i] = i + 2 * j;
      }
    }
  }
  for (long long int i = 0; i <= n - 1; i++) {
    ans = ans + (n - v[i]);
  }
  cout << ans << endl;
  return 0;
}
