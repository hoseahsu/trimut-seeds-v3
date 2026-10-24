#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e6 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k, p, t;
  cin >> n >> k;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> p >> t;
    p = -p;
    mp[make_pair(p, t)]++;
  }
  int cnt = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cnt += it->second;
    if (cnt >= k) {
      cout << it->second << '\n';
      break;
    }
  }
}
