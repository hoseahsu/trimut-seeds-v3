#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
long long a, b, tmp;
long long vis[300000 + 5];
vector<long long> path[300000 + 5];
stack<long long> cir;
long long p[300000 + 5], pre[300000 + 5];
void DFS(long long u, long long pa) {
  long long t;
  tmp++;
  vis[u] = tmp;
  cir.push(u);
  for (auto v : path[u]) {
    if (v == pa) continue;
    if (!vis[v])
      DFS(v, u);
    else if (vis[v] < vis[u]) {
      long long mx = u, mn = u;
      while (!cir.empty()) {
        t = cir.top();
        cir.pop();
        mx = max(mx, t);
        mn = min(mn, t);
        if (t == v) break;
      }
      p[mn] = mx - 1;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> a >> b;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  for (long long i = 1; i <= n; i++) {
    p[i] = n;
  }
  for (long long i = 1; i <= n; i++) {
    if (!vis[i]) DFS(i, 0);
  }
  tmp = n;
  for (long long i = n; i >= 1; i--) {
    tmp = min(tmp, p[i]);
    p[i] = tmp;
  }
  for (long long i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + p[i] - i + 1;
  }
  cin >> q;
  for (long long i = 0; i < q; i++) {
    cin >> a >> b;
    tmp = upper_bound(p + a, p + b + 1, b) - p;
    cout << (b - tmp + 2) * (b - tmp + 1) / 2 + pre[tmp - 1] - pre[a - 1]
         << endl;
  }
  return 0;
}
