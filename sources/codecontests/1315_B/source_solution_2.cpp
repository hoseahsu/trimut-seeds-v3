#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, p, ans = 0, x, i, n;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    x = s.length();
    n = x;
    for (i = n - 2; i >= 0; i--) {
      if (s[i] != s[i + 1] || i == n - 2) {
        if (s[i] == 'A') {
          if (ans + a <= p) {
            ans = ans + a;
            x = i + 1;
          } else {
            break;
          }
        } else {
          if (ans + b <= p) {
            ans = ans + b;
            x = i + 1;
          } else {
            break;
          }
        }
      }
      x = i + 1;
    }
    cout << x << endl;
  }
  return 0;
}
