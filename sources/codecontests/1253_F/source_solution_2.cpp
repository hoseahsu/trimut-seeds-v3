#include <bits/stdc++.h>
using namespace std;
struct dataEdge {
  long long u, v, w;
  dataEdge(){};
  dataEdge(long long u, long long v, long long w) : u(u), v(v), w(w){};
  bool operator<(const dataEdge &a) const { return w < a.w; }
};
struct dataHeap {
  long long u, type, val;
  dataHeap(){};
  dataHeap(long long u, long long type, long long val)
      : u(u), type(type), val(val){};
  bool operator>(const dataHeap &u) const { return val > u.val; }
};
const long long N = 3e5 + 4, oo = 1e17 + 4;
long long n, m, k, QQues;
vector<pair<long long, long long> > adj[N];
vector<dataEdge> Edge;
long long par[N];
vector<long long> lsNode;
long long getRoot(long long u) {
  return (par[u] < 0) ? u : (par[u] = getRoot(par[u]));
}
bool Merge(long long u, long long v) {
  u = getRoot(u);
  v = getRoot(v);
  if (u == v) return false;
  if (par[u] > par[v]) swap(u, v);
  par[u] += par[v];
  par[v] = u;
  return true;
}
long long d[N][2], root[N][2];
priority_queue<dataHeap, vector<dataHeap>, greater<dataHeap> > pq;
void Dijkstra0() {
  for (long long u = 1; u <= (long long)n; ++u)
    d[u][0] = d[u][1] = oo, root[u][0] = root[u][1] = -1;
  for (long long u = 1; u <= (long long)k; ++u) {
    d[u][0] = 0;
    root[u][0] = u;
    pq.push(dataHeap(u, 0, d[u][0]));
  }
  while (pq.size()) {
    long long u = pq.top().u, type = pq.top().type, val = pq.top().val;
    pq.pop();
    if (d[u][type] != val) continue;
    for (pair<long long, long long> foo : adj[u]) {
      long long v = foo.second, cost = foo.first;
      if (d[v][0] > val + cost) {
        d[v][0] = val + cost;
        root[v][0] = root[u][type];
        pq.push(dataHeap(v, 0, d[v][0]));
      }
    }
  }
}
void Dijkstra1() {
  for (long long u = 1; u <= (long long)n; ++u)
    pq.push(dataHeap(u, 0, d[u][0]));
  while (pq.size()) {
    long long u = pq.top().u, type = pq.top().type, val = pq.top().val;
    pq.pop();
    if (d[u][type] != val) continue;
    for (pair<long long, long long> foo : adj[u]) {
      long long v = foo.second, cost = foo.first;
      if (d[v][1] > val + cost &&
          getRoot(root[v][0]) != getRoot(root[u][type])) {
        d[v][1] = val + cost;
        root[v][1] = root[u][type];
        pq.push(dataHeap(v, 1, d[v][1]));
      }
    }
  }
}
dataEdge Trace[N];
vector<dataEdge> Tree, CC;
long long Time, debug, best[N];
void sol() {
  for (long long u = 1; u <= (long long)n; ++u) {
    par[u] = -1;
    if (u <= k) lsNode.push_back(u);
  }
  while (true) {
    if ((long long)lsNode.size() == 1) return;
    Dijkstra0();
    Dijkstra1();
    for (long long u = 1; u <= (long long)n; ++u)
      best[u] = oo, Trace[u] = dataEdge(-1, -1, -1);
    for (long long u = 1; u <= (long long)k; ++u) {
      long long v = root[u][1], w = d[u][1], topo_u = getRoot(u),
                topo_v = getRoot(v);
      if (v == -1) continue;
      if (best[topo_u] > d[u][1]) {
        best[topo_u] = d[u][1];
        Trace[topo_u] = dataEdge(u, v, w);
      }
      if (best[topo_v] > d[u][1]) {
        best[topo_v] = d[u][1];
        Trace[topo_v] = dataEdge(u, v, w);
      }
    }
    CC.clear();
    for (long long topo : lsNode) {
      long long u = Trace[topo].u, v = Trace[topo].v, w = Trace[topo].w;
      if (u != -1) CC.push_back(dataEdge(u, v, w));
    }
    sort(CC.begin(), CC.end());
    for (dataEdge foo : CC) {
      long long u = foo.u, v = foo.v;
      if (Merge(u, v)) Tree.push_back(foo);
    }
    lsNode.clear();
    for (long long u = 1; u <= (long long)k; ++u)
      if (par[u] < 0) lsNode.push_back(u);
  }
}
long long Low[N], High[N], ans[N];
vector<long long> needCheck[N];
pair<long long, long long> ques[N];
void Answer_Query() {
  assert((long long)Tree.size() == k - 1);
  sort(Tree.begin(), Tree.end());
  for (long long i = 1; i <= (long long)QQues; ++i)
    cin >> ques[i].first >> ques[i].second;
  for (long long i = 1; i <= (long long)QQues; ++i)
    Low[i] = 0, High[i] = k - 1, ans[i] = -1;
  while (true) {
    bool isEnd = true;
    for (long long i = 1; i <= (long long)QQues; ++i)
      if (Low[i] <= High[i]) {
        long long mid = (Low[i] + High[i]) / 2;
        needCheck[mid].push_back(i);
        isEnd = false;
      }
    if (isEnd) break;
    for (long long u = 1; u <= (long long)n; ++u) par[u] = -1;
    for (long long i = 0; i < (long long)Tree.size(); ++i) {
      long long u = Tree[i].u, v = Tree[i].v, w = Tree[i].w;
      Merge(u, v);
      for (long long id : needCheck[i]) {
        long long u = ques[id].first, v = ques[id].second;
        u = getRoot(u);
        v = getRoot(v);
        if (u == v) {
          High[id] = i - 1;
          ans[id] = w;
        } else
          Low[id] = i + 1;
      }
      needCheck[i].clear();
    }
  }
  for (long long i = 1; i <= (long long)QQues; ++i) cout << ans[i] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cin >> n >> m >> k >> QQues;
  long long u, v, w;
  for (long long i = 1; i <= (long long)m; ++i) {
    cin >> u >> v >> w;
    adj[u].push_back(pair<long long, long long>(w, v));
    adj[v].push_back(pair<long long, long long>(w, u));
    Edge.push_back(dataEdge(u, v, w));
  }
  sol();
  Answer_Query();
  return 0;
}
