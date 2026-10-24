#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
int cnt = 1, n, m, ptr, H[N], king[N], up[N], is[N], mark[N], leaf[N], d[N],
    St[N];
vector<pair<int, int> > G[N];
void dfs(int v, int last) {
  mark[v] = 1;
  up[v] = H[v];
  for (auto y : G[v]) {
    int u = y.first, id = y.second;
    if (id == last) continue;
    if (mark[u]) {
      up[v] = min(up[v], H[u]);
    } else {
      H[u] = H[v] + 1;
      dfs(u, id);
      if (up[u] > H[v]) is[id] = 1;
      up[v] = min(up[v], up[u]);
    }
  }
}
void calc(int v) {
  St[v] = ++ptr;
  mark[v] = 1;
  for (auto y : G[v]) {
    int u = y.first, id = y.second;
    if (mark[u]) continue;
    if (is[id] == 1) {
      cnt++;
      king[u] = u;
      calc(u);
    } else {
      king[u] = king[v];
      calc(u);
    }
  }
}
bool cmp(int v, int u) { return St[v] < St[u]; }
int main() {
  scanf("%d%d", &n, &m);
  if (n == 2) return !printf("-1");
  H[1] = 1;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(make_pair(b, i));
    G[b].push_back(make_pair(a, i));
  }
  dfs(1, -1);
  memset(mark, 0, sizeof mark);
  king[1] = 1;
  calc(1);
  if (cnt == 1) return !printf("0");
  for (int i = 1; i <= n; i++) {
    if (!leaf[king[i]])
      leaf[king[i]] = i;
    else if (H[i] > H[leaf[king[i]]])
      leaf[king[i]] = i;
    for (auto y : G[i]) {
      if (king[y.first] != king[i]) d[king[i]]++;
    }
  }
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (king[i] == i && d[i] == 1) vec.push_back(leaf[i]);
  }
  sort((vec).begin(), (vec).end(), cmp);
  int sz = (int)vec.size();
  printf("%d\n", (sz + 1) >> 1);
  for (int i = 0; i < ((sz + 1) >> 1); i++) {
    printf("%d %d\n", vec[i], vec[i + sz / 2]);
  }
  return 0;
}
