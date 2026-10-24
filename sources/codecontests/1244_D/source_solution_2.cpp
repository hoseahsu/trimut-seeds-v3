#include <bits/stdc++.h>
using namespace std;
mt19937 rng(0);
vector<vector<long long>> g;
long long max_d;
vector<long long> d;
bool bad;
long long new_root;
void dfs(long long v = 0, long long p = -1, long long h = 0) {
  d[v] = h;
  if (h > max_d) {
    max_d = h;
    new_root = v;
  }
  if ((long long)((g[v]).size()) >= 3) bad = 1;
  for (auto i : g[v]) {
    if (i == p) continue;
    dfs(i, v, h + 1);
  }
}
vector<long long> nums;
void dfs1(long long v, long long p) {
  nums.push_back(v);
  for (auto i : g[v]) {
    if (i != p) dfs1(i, v);
  }
}
void run() {
  long long n;
  cin >> n;
  vector<long long> c1(n), c2(n), c3(n);
  for (long long indd = 0; indd < c1.size(); indd++) cin >> c1[indd];
  ;
  for (long long indd = 0; indd < c2.size(); indd++) cin >> c2[indd];
  ;
  for (long long indd = 0; indd < c3.size(); indd++) cin >> c3[indd];
  ;
  g.resize(n);
  d.resize(n);
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> v >> u;
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs();
  if (bad) {
    cout << -1;
    return;
  }
  dfs1(new_root, -1);
  vector<long long> p = {0, 1, 2};
  vector<long long> colors(n);
  long long bans = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
  do {
    vector<long long> tc(n);
    long long tans = 0;
    for (long long i = 0; i < n; i++) {
      tc[nums[i]] = p[i % 3] + 1;
      if (p[i % 3] == 0) tans += c1[nums[i]];
      if (p[i % 3] == 1) tans += c2[nums[i]];
      if (p[i % 3] == 2) tans += c3[nums[i]];
    }
    if (tans < bans) {
      bans = tans;
      colors = tc;
    }
  } while (next_permutation((p).begin(), (p).end()));
  cout << bans << '\n';
  for (long long indd = 0; indd < colors.size(); indd++)
    cout << colors[indd] << ' ';
  cout << '\n';
}
signed main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 0; i < t; i++) run();
  return 0;
}
