#include <bits/stdc++.h>
using namespace std;
string s, s1;
long long a, b, n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  cin >> s1;
  n = (long long)s.size();
  for (long long i = 0; i < n; i += 2) {
    if (s[i] == s1[i]) continue;
    if (s[i] == '8') {
      if (s1[i] == '(')
        b++;
      else
        a++;
    }
    if (s[i] == '(') {
      if (s1[i] == '[')
        b++;
      else
        a++;
    }
    if (s[i] == '[') {
      if (s1[i] == '8')
        b++;
      else
        a++;
    }
  }
  if (a == b) {
    cout << "TIE";
    return 0;
  }
  if (a > b)
    cout << "TEAM 1 WINS";
  else
    cout << "TEAM 2 WINS";
  return 0;
}
