#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int a = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-') ++a;
  }
  if (a == n || a % (n - a) == 0)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
