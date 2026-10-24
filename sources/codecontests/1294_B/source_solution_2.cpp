#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n;
  cin >> n;
  long long first[n], second[n], x1 = 0, y1 = 0;
  string s;
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < n; i++) {
    long long first, second;
    cin >> first >> second;
    v.push_back(make_pair(first, second));
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) {
    long long first = v[i].first - x1;
    long long second = v[i].second - y1;
    if (second < 0) {
      cout << "NO"
           << "\n";
      return 0;
    }
    for (long long i = 0; i < first; i++) {
      s += 'R';
      x1++;
    }
    for (long long i = 0; i < second; i++) {
      s += 'U';
      y1++;
    }
  }
  cout << "YES"
       << "\n";
  cout << s << "\n";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
