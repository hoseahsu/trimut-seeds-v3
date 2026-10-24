#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
const long long maxn = 3e5 + 5, N = 100 + 20, SQ = 450, base = 1999,
                mod = 1e9 + 7, INF = 1e18, lg = 30;
const long double eps = 1e-4;
long long c[maxn];
vector<long long> edges[maxn];
long long dis[maxn];
void dfs(long long v, long long p, long long col) {
  if (p != -1) dis[v] = dis[p];
  if (p != -1 && c[v] != col && c[v]) {
    ++dis[v];
    col = c[v];
  }
  for (auto u : edges[v]) {
    if (u != p) {
      dfs(u, v, col);
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; ++i) edges[i].clear();
    long long cnt = 0;
    for (long long i = 0; i < n; ++i) {
      cin >> c[i];
      if (c[i] == 0) ++cnt;
    }
    for (long long i = 0; i < n - 1; ++i) {
      long long a, b;
      cin >> a >> b;
      --a;
      --b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    if (cnt == n) {
      cout << "1\n";
      continue;
    }
    for (long long i = 0; i < n; ++i) {
      if (c[i]) {
        dfs(i, -1, c[i]);
        break;
      }
    }
    long long maxi = -1, root;
    for (long long i = 0; i < n; ++i) {
      if (c[i]) {
        if (dis[i] > maxi) {
          maxi = dis[i];
          root = i;
        }
      }
    }
    for (long long i = 0; i < n; ++i) dis[i] = 0;
    dfs(root, -1, c[root]);
    long long ans = -1;
    for (long long i = 0; i < n; ++i) {
      ans = max(ans, dis[i]);
    }
    cout << (ans + 1) / 2 + 1 << '\n';
  }
}
