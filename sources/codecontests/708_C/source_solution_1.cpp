#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 22;
int n;
int ch[MAXN], dp[MAXN], dpu[MAXN], prob[MAXN], probup[MAXN];
pair<int, int> mx1[MAXN], mx2[MAXN];
vector<int> G[MAXN];
void dfs(int v, int par = n) {
  ch[v] = 1;
  for (int i = 0; i < G[v].size(); i++) {
    int u = G[v][i];
    if (u == par) continue;
    dfs(u, v);
    if (ch[u] > (n / 2)) prob[v] = u;
    dp[v] = max(dp[v], dp[u]);
    ch[v] += ch[u];
    if (dp[u] > mx1[v].first)
      mx2[v] = mx1[v], mx1[v] = make_pair(dp[u], u);
    else if (dp[u] > mx2[v].first)
      mx2[v] = make_pair(dp[u], u);
  }
  if (ch[v] <= (n) / 2) dp[v] = max(dp[v], ch[v]);
}
void dfsu(int v, int par = n) {
  for (int i = 0; i < G[v].size(); i++) {
    int u = G[v][i];
    if (u == par) continue;
    if (n - ch[u] > n / 2)
      probup[u] = v;
    else
      dpu[u] = n - ch[u];
    dpu[u] = max(dpu[u], dpu[v]);
    if (u != mx1[v].second)
      dpu[u] = max(dpu[u], mx1[v].first);
    else
      dpu[u] = max(dpu[u], mx2[v].first);
    dfsu(u, v);
  }
}
int main() {
  cin >> n;
  for (int i = (1); i < (n); i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  memset(prob, -1, sizeof(prob));
  memset(probup, -1, sizeof(probup));
  dfs(0);
  dfsu(0);
  for (int i = (0); i < (n); i++) {
    if (prob[i] == -1 && probup[i] == -1) {
      cout << 1 << " ";
      continue;
    }
    if (probup[i] == -1) {
      int u = prob[i];
      cout << !(ch[u] - dp[u] > (n / 2)) << " ";
      continue;
    }
    cout << !((n - ch[i]) - dpu[i] > (n / 2)) << " ";
  }
  return 0;
}
