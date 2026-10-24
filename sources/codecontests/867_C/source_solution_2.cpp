#include <bits/stdc++.h>
using namespace std;
const int inf = ~0u >> 1, MOD = 1e9 + 7;
inline int rd() {
  int x = 0, c = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar()) f = c != '-';
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return f ? x : -x;
}
const int N = 100010;
int n, m, s[N], a[N], b[N];
vector<pair<int, int> > f, g;
int main() {
  scanf("%d%d", &n, &m);
  long long cnt = 0, cnta = 0, cntb = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", s + i, a + i, b + i);
    cnt += s[i];
    if (a[i] > b[i]) {
      cnta += s[i];
      ans += 1LL * s[i] * a[i];
      f.push_back(pair<int, int>(a[i] - b[i], s[i]));
    } else {
      cntb += s[i];
      ans += 1LL * s[i] * b[i];
      g.push_back(pair<int, int>(b[i] - a[i], s[i]));
    }
  }
  sort((f).begin(), (f).end());
  sort((g).begin(), (g).end());
  long long bought = (cnt / m) + bool(cnt % m);
  long long boughta = (cnta / m) + bool(cnta % m);
  long long boughtb = (cntb / m) + bool(cntb % m);
  if (boughta + boughtb > bought) {
    long long t_233a = cnta % m, ansa = ans;
    long long t_233b = cntb % m, ansb = ans;
    for (int i = 0; i < (int)f.size() && t_233a; ++i) {
      long long t_233 = min(t_233a, (long long)f[i].second);
      ansa -= (long long)f[i].first * t_233;
      t_233a -= t_233;
    }
    for (int i = 0; i < (int)g.size() && t_233b; ++i) {
      long long t_233 = min(t_233b, (long long)g[i].second);
      ansb -= (long long)g[i].first * t_233;
      t_233b -= t_233;
    }
    ans = max(ansa, ansb);
  }
  cout << ans << endl;
}
