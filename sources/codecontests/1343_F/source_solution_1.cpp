#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MAX = 2e2 + 5;
const long long MAX2 = 11;
const long long MOD = 1000000000;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
long long tc, n, k[MAX], x[MAX][MAX], cnt[MAX], ans[MAX], mn, mx, rev[MAX];
vector<int> v;
bool st, vis[MAX];
set<int> cek;
int main() {
  cout << fixed << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  for (int ntc = 1; ntc <= tc; ++ntc) {
    cin >> n;
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    for (int i = 2; i <= n; ++i) {
      cin >> k[i];
      for (int j = 1; j <= k[i]; ++j) cin >> x[i][j], ++cnt[x[i][j]];
    }
    st = 1;
    for (long long i = n; i >= 2; --i) {
      v.clear();
      for (int j = 1; j <= n; ++j)
        if (cnt[j] == 1) v.push_back(j);
      if (v.empty()) {
        st = 0;
        break;
      }
      if (v.size() == 2) ans[1] = v[1], cnt[v[1]]--;
      ans[i] = v[0];
      for (int j = 2; j <= n; ++j)
        if (!vis[j]) {
          for (int o = 1; o <= k[j]; ++o)
            if (x[j][o] == v[0]) vis[j] = 1;
          if (vis[j]) {
            for (int o = 1; o <= k[j]; ++o) --cnt[x[j][o]];
            break;
          }
        }
    }
    if (st) {
      cek.clear();
      for (int i = 1; i <= n; ++i) rev[ans[i]] = i;
      for (int i = 2; i <= n; ++i) {
        mn = n, mx = 0;
        for (int j = 1; j <= k[i]; ++j)
          mx = max(mx, rev[x[i][j]]), mn = min(mn, rev[x[i][j]]);
        if (cek.count(mx) || mx - mn + 1 != k[i]) {
          st = 0;
          break;
        }
        cek.insert(mx);
      }
    }
    if (!st) {
      st = 1;
      memset(cnt, 0, sizeof cnt);
      memset(vis, 0, sizeof vis);
      for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= k[i]; ++j) ++cnt[x[i][j]];
      for (long long i = n; i >= 2; --i) {
        v.clear();
        for (int j = 1; j <= n; ++j)
          if (cnt[j] == 1) v.push_back(j);
        if (v.empty()) {
          st = 0;
          break;
        }
        if (v.size() == 2) swap(v[0], v[1]), ans[1] = v[1], cnt[v[1]]--;
        ans[i] = v[0];
        for (int j = 2; j <= n; ++j)
          if (!vis[j]) {
            for (int o = 1; o <= k[j]; ++o)
              if (x[j][o] == v[0]) vis[j] = 1;
            if (vis[j]) {
              for (int o = 1; o <= k[j]; ++o) --cnt[x[j][o]];
              break;
            }
          }
      }
      if (st) {
        cek.clear();
        for (int i = 1; i <= n; ++i) rev[ans[i]] = i;
        for (int i = 2; i <= n; ++i) {
          mn = n, mx = 0;
          for (int j = 1; j <= k[i]; ++j)
            mx = max(mx, rev[x[i][j]]), mn = min(mn, rev[x[i][j]]);
          if (cek.count(mx) || mx - mn + 1 != k[i]) {
            st = 0;
            break;
          }
          cek.insert(mx);
        }
      }
      if (!st) return 1;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << "\n";
  }
  return 0;
}
