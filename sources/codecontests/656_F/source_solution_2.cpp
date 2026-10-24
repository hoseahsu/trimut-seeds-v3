#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout << (fixed) << setprecision(9);
  string s;
  while (cin >> s) {
    long long res = 0;
    for (char c : s) {
      if (c == 'A') continue;
      if (c == '0')
        res += 9;
      else
        res += c - '0';
    }
    ++res;
    cout << res << endl;
  }
}
