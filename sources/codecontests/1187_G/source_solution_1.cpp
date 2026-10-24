#include <bits/stdc++.h>
using namespace std;
struct edge {
  int y, c, f, cost;
  edge(){};
  edge(int y, int c, int f, int cost) : y(y), c(c), f(f), cost(cost){};
};
vector<edge> e;
const int N = 14043;
vector<int> g[N];
long long ans = 0;
long long d[N];
int p[N];
int pe[N];
int inq[N];
const long long INF64 = (long long)(1e18);
int s = N - 2;
int t = N - 1;
int rem(int x) { return e[x].c - e[x].f; }
void push_flow() {
  for (int i = 0; i < N; i++) d[i] = INF64, p[i] = -1, pe[i] = -1, inq[i] = 0;
  d[s] = 0;
  queue<int> q;
  q.push(s);
  inq[s] = 1;
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    inq[k] = 0;
    for (auto x : g[k]) {
      if (!rem(x)) continue;
      int c = e[x].cost;
      int y = e[x].y;
      if (d[y] > d[k] + c) {
        d[y] = d[k] + c;
        p[y] = k;
        pe[y] = x;
        if (inq[y] == 0) {
          inq[y] = 1;
          q.push(y);
        }
      }
    }
  }
  int cur = t;
  while (cur != s) {
    e[pe[cur]].f++;
    e[pe[cur] ^ 1].f--;
    cur = p[cur];
  }
  ans += d[t];
}
void add_edge(int x, int y, int c, int cost) {
  g[x].push_back(e.size());
  e.push_back(edge(y, c, 0, cost));
  g[y].push_back(e.size());
  e.push_back(edge(x, 0, 0, -cost));
}
int main() {
  int n, m, k, c, d;
  cin >> n >> m >> k >> c >> d;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    --x;
    add_edge(s, x, 1, 0);
  }
  int tt = 101;
  for (int i = 0; i < tt; i++) add_edge(0 + i * n, t, k, i * c);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    for (int i = 0; i < tt - 1; i++)
      for (int j = 0; j < k; j++)
        add_edge(x + i * n, y + i * n + n, 1, d * (j * 2 + 1));
    for (int i = 0; i < tt - 1; i++)
      for (int j = 0; j < k; j++)
        add_edge(y + i * n, x + i * n + n, 1, d * (j * 2 + 1));
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < tt - 1; j++) add_edge(i + j * n, i + j * n + n, k, 0);
  for (int i = 0; i < k; i++) push_flow();
  cout << ans << endl;
}
