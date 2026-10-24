#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e12;
const long long INF = 1e15;
const int inf = 1e9 + 10;
const int N = 6500, M = 5e4 + 10;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
set<pair<int, int> > pq;
template <class T>
bool minimize(T &x, T y) {
  if (x > y)
    x = y;
  else
    return 0;
  return 1;
}
struct edge {
  int u, v, cap, flow, cost;
};
struct graph {
  static const int MAXN = 7000;
  int st, en, n;
  std::vector<edge> e;
  std::vector<int> V[MAXN];
  long long d[MAXN], prevEdge[MAXN];
  bool inQueue[MAXN];
  void init() {
    e.clear();
    for (int i = 0, _n = (MAXN); i < _n; i++) V[i].clear();
  }
  void make_edge(int u, int v, int cap, int cost) {
    e.push_back((edge){u, v, cap, 0, cost});
    e.push_back((edge){v, u, 0, 0, -cost});
    V[u].push_back(((int)e.size()) - 2);
    V[v].push_back(((int)e.size()) - 1);
  }
  bool spfa() {
    for (int i = 0, _n = (MAXN); i < _n; i++) d[i] = INF;
    d[st] = 0;
    queue<int> qu;
    qu.push(st);
    memset(inQueue, false, sizeof(inQueue));
    while (((int)qu.size())) {
      int u = qu.front();
      qu.pop();
      inQueue[u] = false;
      for (auto id : V[u]) {
        int v = e[id].v, cost = e[id].cost;
        if (e[id].cap - e[id].flow > 0 && d[v] > d[u] + cost) {
          d[v] = d[u] + cost;
          prevEdge[v] = id;
          if (!inQueue[v]) {
            inQueue[v] = true;
            qu.push(v);
          }
        }
      }
    }
    return d[en] < INF;
  }
  long long answer() {
    long long res = 0;
    while (spfa()) {
      std::vector<int> path(0);
      for (int cur = en; cur != st;) {
        int id = prevEdge[cur], v = e[id].u;
        path.push_back(id);
        cur = v;
      }
      int aug = 1e9;
      for (auto id : path) aug = min(aug, e[id].cap - e[id].flow);
      for (auto id : path) {
        e[id].flow += aug;
        e[id ^ 1].flow -= aug;
        res += 1LL * aug * e[id].cost;
      }
    }
    return res;
  }
} mygr;
int n, m, a[100][100];
bool check(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
void prepare() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", a[i] + j);
  mygr.n = n * m + 2;
  mygr.st = n * m + 1;
  mygr.en = n * m + 2;
  for (int i = 0; i < n; i++)
    for (int j = i & 1; j < m; j += 2) {
      mygr.make_edge(mygr.st, i * m + j + 1, 1, 0);
      for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir], nj = j + dy[dir];
        if (check(ni, nj))
          mygr.make_edge(i * m + j + 1, ni * m + nj + 1, 1,
                         a[i][j] != a[ni][nj]);
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = (i & 1) ^ 1; j < m; j += 2)
      mygr.make_edge(i * m + j + 1, mygr.en, 1, 0);
}
int main() {
  prepare();
  cout << mygr.answer();
}
