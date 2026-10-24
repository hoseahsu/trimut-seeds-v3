#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, t, cont = 1, in[2 * 500005], out[2 * 500005];
long long dep[500005], k, x;
long long tree[2][2 * 500005];
vector<int> adj[500005];
void dfs(int u) {
  in[u] = cont++;
  for (auto v : adj[u]) dep[v] = 1 + dep[u], dfs(v);
  out[u] = cont++;
}
void update(int pos, int x, int mo) {
  for (int i = pos; i < 2 * 500005; i += (-i & i))
    tree[mo][i] = (tree[mo][i] + x) % MOD;
  return;
}
int query(int pos, int mo) {
  int res = 0;
  for (int i = pos; i > 0; i -= (i & -i)) res = (res + tree[mo][i]) % MOD;
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u; i < n; i++) {
    scanf("%d", &u);
    adj[--u].push_back(i);
  }
  dfs(0);
  scanf("%d", &m);
  int v;
  while (m--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%lld%lld", &v, &x, &k);
      v--;
      long long aux = (x + k * dep[v]) % MOD;
      update(in[v], aux, 0);
      update(out[v] + 1, -aux, 0);
      update(in[v], k, 1);
      update(out[v] + 1, -k, 1);
    } else {
      scanf("%d", &v);
      v--;
      cout << ((query(in[v], 0) - (dep[v] * (query(in[v], 1))) % MOD) % MOD +
               MOD) %
                  MOD
           << endl;
    }
  }
  return 0;
}
