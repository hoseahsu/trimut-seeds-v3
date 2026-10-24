#include <bits/stdc++.h>
using namespace std;
const long long int N = 1000000;
vector<long long int> g[N];
bool vis[N];
void solve() {
  long long int n, u, v;
  map<pair<long long int, long long int>, long long int> mp;
  vector<pair<long long int, long long int>> v1;
  cin >> n;
  for (long long int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    v1.push_back({u, v});
  }
  if (n < 4) {
    for (long long int i = n - 2; i >= 0; i--) cout << i << "\n";
  } else {
    long long int i = 0;
    for (i = 1; i <= n; i++) {
      if (g[i].size() > 2) break;
    }
    if (i > n) {
      for (long long int i = n - 2; i >= 0; i--) cout << i << "\n";
    } else {
      mp[{i, g[i][1]}] = 1;
      mp[{i, g[i][2]}] = 3;
      mp[{g[i][0], i}] = 2;
      mp[{g[i][1], i}] = 1;
      mp[{g[i][2], i}] = 3;
      mp[{i, g[i][0]}] = 2;
      long long int k = 3;
      for (long long int j = 0; j < n - 1; j++) {
        if (mp[v1[j]] > 0)
          cout << mp[v1[j]] % 3 << "\n";
        else {
          cout << k << "\n";
          k++;
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
