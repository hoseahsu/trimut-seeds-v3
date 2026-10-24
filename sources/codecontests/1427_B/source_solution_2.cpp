#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<pair<long long, long long>, long long>> a;
    long long i = 0;
    while (i < n) {
      if (s[i] == 'L') {
        i++;
        continue;
      }
      long long cnt = 0;
      long long j = i;
      while (j < n and s[j] == 'W') {
        j++;
        cnt++;
      }
      a.push_back({{i, j - 1}, cnt});
      i = j;
    }
    sort(a.begin(), a.end());
    long long mx = 0;
    set<pair<long long, pair<long long, long long>>> p;
    for (long long i = 0; i + 1 < a.size(); i++) {
      p.insert({a[i + 1].first.first - a[i].first.second - 1, {i + 1, i}});
    }
    while (1) {
      if (p.empty()) break;
      long long tp = p.begin()->first;
      if (tp <= k) {
        for (long long i = a[p.begin()->second.second].first.second;
             i <= a[p.begin()->second.first].first.first; i++) {
          s[i] = 'W';
        }
        k -= tp;
      } else {
        for (long long i = a[p.begin()->second.first].first.first - 1;
             i > a[p.begin()->second.second].first.second; i--) {
          if (k == 0) break;
          s[i] = 'W';
          k--;
        }
      }
      p.erase(p.begin());
    }
    if (k and a.size() > 0) {
      for (long long i = a[0].first.first - 1; i >= 0; i--) {
        if (k == 0) break;
        s[i] = 'W';
        k--;
      }
      for (long long i = a[a.size() - 1].first.second + 1; i < n; i++) {
        if (k == 0) break;
        s[i] = 'W';
        k--;
      }
    } else {
      for (long long i = 0; i < n; i++) {
        if (k == 0) break;
        s[i] = 'W';
        k--;
      }
    }
    i = 0;
    while (i < n) {
      if (s[i] == 'L') {
        i++;
        continue;
      }
      long long cnt = 0;
      long long j = i;
      while (j < n and s[j] == 'W') {
        cnt++;
        j++;
      }
      mx += (cnt * 2) - 1;
      i = j;
    }
    cout << mx << "\n";
  }
  return 0;
}
