#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int maxn = 2e5 + 5;
int T, n, m, k, tmp[maxn];
int num[maxn], vis[maxn];
vector<int> g[maxn], ans2;
unordered_set<int> mp[maxn];
set<pair<int, int> > st;
int gao() {
  while (st.size()) {
    int u = (*st.begin()).second;
    if (num[u] >= k) return 1;
    if (num[u] == k - 1) {
      int f = 1, cnt = 0;
      tmp[++cnt] = u;
      for (auto v : g[u])
        if (!vis[v]) tmp[++cnt] = v;
      for (register int i = 1; i <= cnt; ++i) {
        for (register int j = 1; j <= cnt; ++j)
          if (!mp[tmp[i]].count(tmp[j])) {
            f = 0;
            break;
          }
        if (!f) break;
      }
      if (f) {
        ans2.clear();
        for (int i = 1; i <= cnt; i++) ans2.push_back(tmp[i]);
        return 2;
      }
    }
    vis[u] = 1;
    st.erase({num[u], u});
    for (auto v : g[u]) {
      if (vis[v]) continue;
      st.erase({num[v], v});
      st.insert({--num[v], v});
    }
  }
  return 0;
}
signed main() {
  scanf("%d", &T);
  while (T--) {
    st.clear();
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      mp[i].clear();
      mp[i].insert(i);
      num[i] = vis[i] = 0, g[i].clear();
    }
    for (int i = 1, u, v; i <= m; i++) {
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
      num[u]++, num[v]++;
      mp[u].insert(v);
      mp[v].insert(u);
    }
    for (int i = 1; i <= n; i++) st.insert({num[i], i});
    int f = gao();
    if (f == 0) puts("-1");
    if (f == 1) {
      printf("%d %d\n", 1, st.size());
      for (auto i : st) printf("%d ", i.second);
      puts("");
    }
    if (f == 2) {
      puts("2");
      for (auto i : ans2) printf("%d ", i);
      puts("");
    }
  }
}
