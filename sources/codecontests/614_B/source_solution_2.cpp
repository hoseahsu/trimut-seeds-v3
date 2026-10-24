#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, zero = 0;
  bool f = 1;
  string s, start = "";
  cin >> n;
  for (__typeof(n) i = 0; i < (n); i++) {
    cin >> s;
    if (s[0] == '0') {
      cout << "0";
      return 0;
    }
    if (f) {
      if (s[0] != '1') f = 0;
      for (__typeof(s.length() - 1) j = 0; j < (s.length() - 1); j++) {
        if (s[j + 1] != '0') f = 0;
      }
      if (!f) {
        start = s;
      } else
        zero += (s.length() - 1);
    } else
      zero += (s.length() - 1);
  }
  cout << start;
  if (start == "") cout << "1";
  for (__typeof(zero) i = 0; i < (zero); i++) cout << "0";
  return 0;
}
