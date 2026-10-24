#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, n, m, k, q, l, r;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin >> l >> r;
  a = r - l;
  if (r - l < 100) {
    map<long long, long long> mp;
    map<long long, long long>::iterator it;
    for (int i = l; i <= r; i++) {
      a = i;
      for (int x = 2; x * x <= a; x++) {
        if (a % x == 0) {
          mp[a / x]++;
          mp[x]++;
        }
      }
      if (a > 1) {
        mp[a]++;
      }
    }
    for (it = mp.begin(); it != mp.end(); it++) {
      b = max(b, it->second);
    }
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second == b) {
        cout << it->first;
        return 0;
      }
    }
  } else {
    cout << 2;
  }
}
