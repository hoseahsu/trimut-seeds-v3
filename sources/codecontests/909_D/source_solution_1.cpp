#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long inf = 4e18;
const long long N = 1e5;
long long opr(vector<pair<long long, char> > &v) {
  long long n = v.size();
  long long o = inf, ind = -1;
  for (long long i = 0; i < n; i++) {
    long long s;
    if (i == 0 || i == n - 1)
      s = v[i].first;
    else
      s = (v[i].first + 1) / 2;
    if (s < o) {
      o = s;
      ind = i;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (i == 0 || i == n - 1)
      v[i].first -= o;
    else
      v[i].first -= 2 * o;
  }
  vector<pair<long long, char> > baal;
  for (long long i = 0; i < n; i++) {
    if (v[i].first > 0) {
      if (baal.size() && baal.back().second == v[i].second)
        baal.back().first += v[i].first;
      else
        baal.emplace_back(v[i]);
    }
  }
  v = baal;
  return o;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long n = s.length();
  vector<pair<long long, char> > v;
  long long cnt = 1;
  for (long long i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      v.emplace_back(cnt, s[i - 1]);
      cnt = 1;
    } else
      cnt++;
  }
  v.emplace_back(cnt, s[n - 1]);
  long long o = 0;
  while (v.size() > 1) o += opr(v);
  cout << o << endl;
}
