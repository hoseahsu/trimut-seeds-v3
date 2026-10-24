#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
const double PI = acos(-1.0);
const double EPS = 1e-9;
const unsigned long long mod = 1000000007;
const unsigned long long INF = 1e9;
const unsigned long long LINF = 1e15;
const unsigned long long MAX = 3e5 + 7;
const unsigned long long MAXN = 1e6 + 1;
int n;
int m;
vector<set<int>> g;
set<int> unused;
vector<int> ans;
int cnt = 0;
void dfs(int v) {
  unused.erase(v);
  ++cnt;
  int go = -1;
  while (1) {
    auto it = unused.upper_bound(go);
    if (it == unused.end()) return;
    go = *it;
    if (!g[v].count(go)) dfs(go);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int u, v;
  g.resize(n);
  for (int i = (0); i < (m); ++i) {
    cin >> u >> v;
    --u;
    --v;
    g[v].insert(u);
    g[u].insert(v);
  }
  for (int i = (0); i < (n); ++i) unused.insert(i);
  for (int i = (0); i < (n); ++i) {
    if (unused.count(i)) {
      dfs(i);
      ans.push_back(cnt);
      cnt = 0;
    }
  }
  sort(ans.begin(), ans.end());
  cout << (int)((ans).size()) << endl;
  for (auto i : ans) cout << i << " ";
  cin >> n;
  return 0;
}
