#include <bits/stdc++.h>
const int N = 1e5 + 100, M = 1e6 + 100, SQ = sqrt(2e5), LG = 23, base = 2,
          second = 1e2 + 100;
const long long mod = 1e9 + 7, MOD = 1e9 + 9, Inf = 9223372036854775807;
const long long INF = 1e9, inf = 1e18, super_inf = ~0ull / 4;
const long double Pi = (22 * 1.0) / (7 * 1.0);
using namespace std;
long long n, m, ans, a, b, c, q;
vector<pair<long long, long long> > v[second];
bool mark[second];
void dfs(long long a, long long b, int c) {
  mark[a] = 1;
  for (auto x : v[a]) {
    if (!mark[x.first] and x.second == c) dfs(x.first, b, c);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a >> b >> c, v[a].push_back(make_pair(b, c)),
        v[b].push_back(make_pair(a, c));
  cin >> q;
  while (q--) {
    cin >> a >> b;
    ans = 0;
    for (int i = 1; i <= m; i++) {
      fill(mark, mark + second, 0);
      dfs(a, b, i);
      if (mark[b]) ans++;
    }
    cout << ans << endl;
  }
}
