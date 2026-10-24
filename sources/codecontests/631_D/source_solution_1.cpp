#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxN = (int)5e5 + 10;
const int maxL = 20;
const long long LLINF = (int)2e9 + 42;
const int mod = (int)1e9 + 7;
vector<pair<long long, int> > a;
vector<pair<long long, int> > b;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int l = atoi(s.substr(0, s.length() - 2).c_str());
    int x = s[s.length() - 1] - 'a';
    if (a.size() > 0 && a.back().second == x) {
      a.back().first += l;
    } else {
      a.push_back(make_pair(l, x));
    }
  }
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    int l = atoi(s.substr(0, s.length() - 2).c_str());
    int x = s[s.length() - 1] - 'a';
    if (b.size() > 0 && b.back().second == x) {
      b.back().first += l;
    } else {
      b.push_back(make_pair(l, x));
    }
  }
  n = a.size();
  m = b.size();
  long long res = 0LL;
  if (m == 1) {
    for (int i = 0; i < n; ++i) {
      if (b[0].second == a[i].second) {
        res += max(0LL, a[i].first - b[0].first + 1);
      }
    }
    cout << res << '\n';
    return 0;
  }
  if (m == 2) {
    for (int i = 0; i < n - 1; ++i) {
      if (b[0].second == a[i].second && b[1].second == a[i + 1].second) {
        if (b[0].first > a[i].first) continue;
        if (b[1].first > a[i + 1].first) continue;
        res++;
      }
    }
    cout << res << '\n';
    return 0;
  }
  vector<pair<int, int> > x;
  for (int i = 1; i < m - 1; ++i) {
    x.push_back(b[i]);
  }
  x.push_back(make_pair(-1, -1));
  for (int i = 1; i < n - 1; ++i) {
    x.push_back(a[i]);
  }
  vector<int> z(x.size());
  for (int i = 1, l = 0, r = 0; i < z.size(); ++i) {
    if (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    }
    while (i + z[i] < z.size() && x[z[i]] == x[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] >= r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  for (int i = m - 1; i < z.size(); ++i) {
    if (z[i] >= m - 2) {
      int start = i - (m - 2) - 1;
      assert(0 <= start);
      assert(start + m - 1 < n);
      if (a[start].second != b[0].second) continue;
      if (a[start].first < b[0].first) continue;
      if (a[start + m - 1].second != b[m - 1].second) continue;
      if (a[start + m - 1].first < b[m - 1].first) continue;
      res++;
    }
  }
  cout << res << '\n';
  return 0;
}
