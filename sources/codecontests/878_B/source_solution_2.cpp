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
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  int interior = 0;
  vector<pair<int, int>> t;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (t.empty() || t.back().first != x)
      t.push_back({x, 1});
    else {
      t.back().second++;
      if (t.back().second == k) {
        t.pop_back();
        ++interior;
      }
    }
  }
  vector<pair<int, int>> memo = t;
  int border = 0;
  int start = 0;
  while ((int)t.size() - start >= 2 && t[start].first == t.back().first &&
         t[start].second + t.back().second >= k) {
    int tmp = t[start].second + t.back().second;
    border += tmp / k;
    tmp -= tmp / k * k;
    if (tmp == 0) {
      ++start;
      t.pop_back();
    } else {
      t.pop_back();
      t[start].second = tmp;
    }
  }
  debug() << " ["
          << "interior"
             ": "
          << (interior)
          << "] "
             " ["
          << "border"
             ": "
          << (border) << "] ";
  long long answer =
      (long long)interior * m * k + (long long)border * (m - 1) * k;
  if ((int)t.size() == start + 1) {
    long long a = (long long)m * t[start].second;
    answer += a / k * k;
    a -= a / k * k;
    if (a == 0) {
      debug() << "spec case";
      vector<pair<int, int>> nowy;
      for (int i = 0; i < start; ++i) nowy.push_back(memo[i]);
      for (int i = (int)t.size(); i < (int)memo.size(); ++i)
        nowy.push_back(memo[i]);
      debug() << " ["
              << "nowy"
                 ": "
              << (nowy) << "] ";
      vector<pair<int, int>> dwa;
      for (pair<int, int> p : nowy) {
        if (dwa.empty() || dwa.back().first != p.first)
          dwa.push_back(p);
        else {
          dwa.back().second += p.second;
          answer += dwa.back().second / k * k;
          dwa.back().second %= k;
          if (dwa.back().second == 0) dwa.pop_back();
        }
      }
    }
  }
  printf("%lld\n", (long long)n * m - answer);
}
