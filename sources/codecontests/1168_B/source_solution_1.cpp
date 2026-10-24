#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> v(n + 1, n);
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    v[i] = v[i + 1];
    for (int k = 1; i + 2 * k < v[i]; k++) {
      if (s[i] == s[i + k] && s[i + k] == s[i + 2 * k]) {
        v[i] = i + 2 * k;
      }
    }
    ans += n - v[i];
  }
  cout << ans << endl;
}
