#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> dxy[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long MAXN = 300 * 1000 + 100, MOD = 1000000007,
                INF = 4LL * 1000 * 1000 * 1000 * 1000;
long long int n, m;
vector<long long int> g[200];
vector<long long int> inv_g[200];
bool used[200];
long long int out[200];
long long int out_it;
long long int color[200];
long long int color_it = 1;
void top_sort(long long int v) {
  used[v] = true;
  for (long long int to : g[v])
    if (!used[to]) top_sort(to);
  out[out_it++] = v;
}
void dfs2(long long int v) {
  color[v] = color_it;
  for (long long int to : inv_g[v])
    if (color[to] == 0) dfs2(to);
}
void solve() {
  cin >> n >> m;
  long long int a, b, c;
  for (long long int i = 0; i < (m); ++i) {
    cin >> a >> b >> c;
    --a, --b;
    if (c == 1) {
      g[a].push_back(b);
      g[b].push_back(a);
      g[a + n].push_back(b + n);
      g[b + n].push_back(a + n);
    } else {
      g[a].push_back(b + n);
      g[b].push_back(a + n);
      g[a + n].push_back(b);
      g[b + n].push_back(a);
    }
  }
  for (long long int i = 0; i < (2 * n); ++i)
    for (long long int to : g[i]) inv_g[to].push_back(i);
  for (long long int i = 0; i < (2 * n); ++i)
    if (!used[i]) top_sort(i);
  reverse(out, out + 2 * n);
  for (long long int i = 0; i < (2 * n); ++i) {
    if (color[out[i]] == 0) dfs2(out[i]);
    ++color_it;
  }
  for (long long int i = 0; i < (n); ++i)
    if (color[i] == color[i + n]) {
      cout << "Impossible";
      return;
    }
  vector<long long int> ans;
  for (long long int i = 0; i < (n); ++i) {
    if (color[i] > color[i + n]) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for (long long int e : ans) cout << e + 1 << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
