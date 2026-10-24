#include <bits/stdc++.h>

using namespace std;

struct StronglyConnectedComponents
{
  vector< vector< int > > gg, rg;
  vector< pair< int, int > > edges;
  vector< int > comp, order, used;

  StronglyConnectedComponents(size_t v) : gg(v), rg(v), comp(v, -1), used(v, 0) {}

  void add_edge(int x, int y)
  {
    gg[x].push_back(y);
    rg[y].push_back(x);
    edges.emplace_back(x, y);
  }

  int operator[](int k)
  {
    return (comp[k]);
  }

  void dfs(int idx)
  {
    if(used[idx]) return;
    used[idx] = true;
    for(int to : gg[idx]) dfs(to);
    order.push_back(idx);
  }

  void rdfs(int idx, int cnt)
  {
    if(comp[idx] != -1) return;
    comp[idx] = cnt;
    for(int to : rg[idx]) rdfs(to, cnt);
  }

  void build(vector< vector< int > > &t)
  {
    for(int i = 0; i < gg.size(); i++) dfs(i);
    reverse(begin(order), end(order));
    int ptr = 0;
    for(int i : order) if(comp[i] == -1) rdfs(i, ptr), ptr++;

    t.resize(ptr);
    set< pair< int, int > > connect;
    for(auto &e : edges) {
      int x = comp[e.first], y = comp[e.second];
      if(x == y) continue;
      if(connect.count({x, y})) continue;
      t[x].push_back(y);
      connect.emplace(x, y);
    }
  }
};


const int INF = 1 << 30;

struct edge
{
  int to, cost;
};

int MST_Arborescence(vector< vector< edge > > &g, int start, int sum = 0)
{
  int N = (int) g.size();

  vector< int > rev(N, -1), weight(N, INF);
  for(int idx = 0; idx < N; idx++) {
    for(auto &e : g[idx]) {
      if(e.cost < weight[e.to]) {
        weight[e.to] = e.cost;
        rev[e.to] = idx;
      }
    }
  }

  StronglyConnectedComponents scc(N);
  for(int idx = 0; idx < N; idx++) {
    if(start == idx) continue;
    scc.add_edge(rev[idx], idx);
    sum += weight[idx];
  }
  vector< vector< int > > renew;
  scc.build(renew);
  if(renew.size() == N) return (sum);
  vector< vector< edge > > fixgraph(renew.size());
  for(int i = 0; i < N; i++) {
    for(auto &e : g[i]) {
      if(scc[i] == scc[e.to]) continue;
      fixgraph[scc[i]].emplace_back((edge) {scc[e.to], e.cost - weight[e.to]});
    }
  }
  return (MST_Arborescence(fixgraph, scc[start], sum));
}

void solve()
{
  int V, E, R;
  cin >> V >> E >> R;
  vector< vector< edge > > g(V);
  while(E--) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].emplace_back((edge) {b, c});
  }
  cout << MST_Arborescence(g, R) << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}