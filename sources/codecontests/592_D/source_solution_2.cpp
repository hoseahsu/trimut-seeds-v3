#include <bits/stdc++.h>
using namespace std;
const int MAXN = 123456 + 5;
vector<int> adj[MAXN];
vector<int> cities;
vector<int> par;
vector<int> need;
int n, m;
void dfs(int u, int p) {
  par[u] = p;
  int res = 0;
  if (cities[u]) res++;
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    res += need[v];
  }
  need[u] = res;
}
int memo[MAXN][2];
int dp(int u, int ret) {
  int &res = memo[u][ret];
  if (res != -1) return res;
  res = 0;
  if (ret) {
    for (int v : adj[u]) {
      if (v == par[u]) continue;
      if (need[v]) {
        res += 2 + dp(v, 1);
      }
    }
    return res;
  } else {
    int diff = 0;
    for (int v : adj[u]) {
      if (v == par[u]) continue;
      if (need[v]) {
        int re = 2 + dp(v, 1);
        int no = 1 + dp(v, 0);
        res += re;
        diff = max(diff, re - no);
      }
    }
    res -= diff;
    return res;
  }
}
const int INF = (int)1e9;
pair<int, int> findDiameter() {
  int st;
  for (int i = 0; i < n; i++) {
    if (cities[i]) {
      st = i;
      break;
    }
  }
  queue<int> q;
  q.push(st);
  vector<int> dist(n, INF);
  dist[st] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (cities[i] && dist[i] > cur) {
      cur = dist[i];
      st = i;
    }
  }
  dist.assign(n, INF);
  dist[st] = 0;
  q.push(st);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  cur = 0;
  int en = st;
  for (int i = 0; i < n; i++) {
    if (cities[i] && dist[i] > cur) {
      cur = dist[i];
      en = i;
    }
  }
  return pair<int, int>(st, en);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cities.assign(n, 0);
  int tmp;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    tmp--;
    cities[tmp] = 1;
  }
  pair<int, int> p = findDiameter();
  int st = p.first, en = p.second;
  par.assign(n, -1);
  need.assign(n, 0);
  dfs(st, -1);
  memset(memo, -1, sizeof memo);
  int r1 = dp(st, 0);
  par.assign(n, -1);
  need.assign(n, 0);
  dfs(en, -1);
  memset(memo, -1, sizeof memo);
  int r2 = dp(en, 0);
  int res, node;
  if (r1 < r2) {
    node = st + 1;
    res = r1;
  } else if (r2 < r1) {
    node = en + 1;
    res = r2;
  } else {
    node = min(st, en) + 1;
    res = r1;
  }
  cout << node << "\n" << res << "\n";
  return 0;
}
