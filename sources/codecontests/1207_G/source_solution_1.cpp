#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 8e5 + 7;
const ll mod = 1e9 + 7;
vector<int> roots;
char ch[N];
vector<int> qu[N];
vector<int> adj[N], adj2[N];
int ans[N];
int col[N];
int st[N], en[N];
int T, cnt, n;
bool upper(int u, int v) { return st[u] <= st[v] && en[u] >= en[v]; }
struct node {
  int nxt[26];
  int link = -1;
  bool term = 0;
  int dil = 0;
  node() { memset(nxt, 0, sizeof nxt); }
  int &operator[](char c) { return nxt[c - 'a']; }
};
vector<node> aho(1);
void add(string x, int j) {
  int cur = 0;
  for (int i = 0; i < ((int)x.size()); ++i) {
    if (!aho[cur][x[i]]) {
      aho[cur][x[i]] = ((int)aho.size());
      aho.push_back(node());
    }
    cur = aho[cur][x[i]];
  }
  aho[cur].term = 1;
  col[j] = cur;
}
void push_links() {
  aho[0].link = 0;
  queue<int> q;
  for (int i = 'a'; i <= 'z'; ++i) {
    if (aho[0][i]) {
      aho[aho[0][i]].link = 0;
      q.push(aho[0][i]);
    }
  }
  while (((int)q.size())) {
    int tp = q.front();
    q.pop();
    for (int j = 'a'; j <= 'z'; ++j) {
      if (aho[tp][j]) {
        int go = aho[tp].link;
        int state = aho[tp][j];
        while (go && !aho[go][j]) {
          go = aho[go].link;
        }
        aho[state].link = aho[go][j];
        if (aho[aho[state].link].term) {
          aho[state].dil = aho[state].link;
        } else {
          aho[state].dil = aho[aho[state].link].dil;
        }
        q.push(state);
      }
    }
  }
}
int dp[N][26];
int transit(int x, char c) {
  if (~dp[x][c - 'a']) return dp[x][c - 'a'];
  return dp[x][c - 'a'] =
             (x && !aho[x][c] ? transit(aho[x].link, c) : aho[x][c]);
}
struct fenwick {
  int bit[N];
  fenwick() { memset(bit, 0, sizeof bit); }
  void add(int x, int v) {
    for (; x < N; x += x & -x) bit[x] += v;
  }
  int upto(int x) {
    int ret = 0;
    for (; x; x -= x & -x) ret += bit[x];
    return ret;
  }
  inline int get(int l, int r) { return upto(r) - upto(l - 1); }
} f1;
void dfs(int x, int cur) {
  cur = transit(cur, ch[x]);
  f1.add(st[cur], 1);
  for (auto v : qu[x]) ans[v] += f1.get(st[col[v]], en[col[v]]);
  for (auto u : adj[x]) dfs(u, cur);
  f1.add(st[cur], -1);
}
void dfs2(int x) {
  st[x] = ++T;
  for (auto u : adj2[x]) dfs2(u);
  en[x] = ++T;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      roots.push_back(i);
    } else {
      int par;
      cin >> par;
      adj[par].push_back(i);
    }
    cin >> ch[i];
  }
  int m;
  cin >> m;
  for (int j = 0; j < m; ++j) {
    int x;
    string st;
    cin >> x >> st;
    qu[x].push_back(j);
    add(st, j);
  }
  push_links();
  for (int i = 1; i < ((int)aho.size()); ++i) adj2[aho[i].link].push_back(i);
  dfs2(0);
  for (auto u : roots) dfs(u, 0);
  for (int i = 0; i < m; ++i) cout << ans[i] << "\n";
  return 0;
}
