#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
bool ins[N];
stack<int> st;
int p[N], noww[N], goal[N];
int to[N], dfn[N], low[N], col[N], deg[N];
long long cc[N], nc[N], ans;
int n, cnt, c, tot;
void link(int f, int t) {
  noww[++cnt] = p[f];
  goal[cnt] = t, p[f] = cnt;
}
void Tarjan_SCC(int nde) {
  dfn[nde] = low[nde] = ++tot;
  st.push(nde), ins[nde] = true;
  for (int i = p[nde]; i; i = noww[i])
    if (!dfn[goal[i]])
      Tarjan_SCC(goal[i]), low[nde] = min(low[nde], low[goal[i]]);
    else if (ins[goal[i]])
      low[nde] = min(low[nde], low[goal[i]]);
  if (dfn[nde] == low[nde]) {
    int tmp;
    c++;
    do {
      tmp = st.top(), st.pop();
      ins[tmp] = false, col[tmp] = c;
      nc[c] = min(nc[c], cc[tmp]);
    } while (tmp != nde);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &cc[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &to[i]), link(i, to[i]);
  memset(nc, 0x3f, sizeof nc);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) Tarjan_SCC(i);
  for (int i = 1; i <= n; i++)
    for (int j = p[i]; j; j = noww[j])
      if (col[i] != col[goal[j]]) deg[col[i]]++;
  for (int i = 1; i <= c; i++)
    if (!deg[i]) ans += nc[i];
  printf("%lld", ans);
  return 0;
}
