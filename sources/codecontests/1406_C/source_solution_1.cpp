#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 1;
vector<long long> adj[N];
long long n;
vector<long long> Centroid() {
  vector<long long> centroid;
  vector<long long> sz(n + 2);
  function<void(long long, long long)> dfs = [&](long long u, long long prev) {
    sz[u] = 1;
    bool is_centroid = true;
    for (auto v : adj[u])
      if (v != prev) {
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > n / 2) is_centroid = false;
      }
    if (n - sz[u] > n / 2) is_centroid = false;
    if (is_centroid) centroid.push_back(u);
  };
  dfs(1, -1);
  return centroid;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) adj[i].clear();
    vector<pair<long long, long long>> edges;
    for (long long i = 1; i <= n - 1; i++) {
      long long u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges.push_back({u, v});
    }
    vector<long long> ans = Centroid();
    long long nn = (long long)ans.size();
    if (nn <= 1) {
      cout << edges[0].first << " " << edges[0].second << "\n";
      cout << edges[0].first << " " << edges[0].second << "\n";
    } else {
      long long u = ans[0];
      long long v = ans[1];
      cout << u << " ";
      long long d1;
      for (auto &x : adj[u]) {
        if (x != v) {
          d1 = x;
          break;
        }
      }
      cout << d1 << "\n";
      cout << v << " " << d1 << "\n";
    }
  }
}
