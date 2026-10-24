#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _dbg(char const *s, const T &t) {
  cout << s << "=" << t << endl;
}
template <typename T, typename... TA>
void _dbg(char const *s, const T &t, const TA &...ta) {
  while (*s != ',') cout << *s++;
  cout << "=" << t << ",";
  _dbg(s + 1, ta...);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream &print_iterable(ostream &os, T beg, T end) {
  os << '[';
  for (auto it = beg; it != end; ++it) {
    if (it != beg) os << ", ";
    os << *it;
  }
  return os << ']';
}
template <typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &x) {
  return print_iterable(os, x.begin(), x.end());
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &x) {
  return print_iterable(os, x.begin(), x.end());
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &x) {
  return print_iterable(os, x.begin(), x.end());
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &x) {
  return print_iterable(os, x.begin(), x.end());
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &x) {
  return print_iterable(os, x.begin(), x.end());
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &x) {
  return print_iterable(os, x.begin(), x.end());
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const unordered_map<T1, T2> &x) {
  return print_iterable(os, x.begin(), x.end());
}
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
const int N = 2750133;
void Solve() {
  int n, k, c, d;
  vector<ll> dp(10);
  vector<vector<pii>> steps = {{{3, 1}}, {{2, 1}}, {{2, 1}, {1, 1}},
                               {{1, 1}}, {{1, 2}}, {{1, 3}}};
  dp[0] = 1;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &k);
    vector<vector<int>> vc(4);
    while (k--) {
      scanf("%d%d", &c, &d);
      vc[c].push_back(d);
    }
    for (int i = 1; i < 4; ++i) {
      sort((vc[i]).begin(), (vc[i]).end());
      reverse((vc[i]).begin(), (vc[i]).end());
    }
    vector<ll> tmpdp = dp;
    for (auto &step : steps) {
      vector<int> tmp;
      bool flag = true;
      int cnt = 0;
      ll sum = 0;
      for (auto &x : step) {
        if ((int)vc[x.first].size() < x.second) {
          flag = false;
          continue;
        }
        cnt += x.second;
        for (int i = 0; i < x.second; ++i) {
          tmp.push_back(vc[x.first][i]);
          sum += tmp.back();
        }
      }
      if (!flag) {
        continue;
      }
      sort((tmp).begin(), (tmp).end());
      for (int i = 0; i < 10 - cnt; ++i) {
        if (!dp[i]) continue;
        tmpdp[i + cnt] = max(tmpdp[i + cnt], dp[i] + sum);
      }
      for (int i = 10 - cnt; i < 10; ++i) {
        if (!dp[i]) continue;
        tmpdp[i + cnt - 10] =
            max(tmpdp[i + cnt - 10], dp[i] + sum + tmp.back());
      }
    }
    swap(dp, tmpdp);
  }
  ll mx = 0;
  for (auto &x : dp) {
    mx = max(mx, x);
  }
  printf("%lld\n", mx - 1);
}
int main() {
  Solve();
  return 0;
}
