#include <bits/stdc++.h>
using namespace std;
long long a, b, c, ans, sum, i, stp;
vector<char> v;
int main() {
  long long n, t;
  string s;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    for (i = 0; i < n; i++) {
      if ((s[i] - '0') % 2 != 0) v.push_back(s[i]);
    }
    if (v.size() >= 2)
      cout << v[0] << v[1] << "\n";
    else
      cout << -1 << "\n";
    v.clear();
  }
}
