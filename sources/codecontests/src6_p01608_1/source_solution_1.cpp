#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define chmax(a,b) (a<(b)?(a=b,1):0)
#define chmin(a,b) (a>(b)?(a=b,1):0)
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

void add_edge(Graph &g, int s, int d, Weight w){
  // cout << s << " " << d << " : " << w << endl;
  g[s].push_back(Edge(s,d,w));
  g[d].push_back(Edge(d,s,0));
}
// Dinic
#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight augment(const Graph &g, const Matrix &capacity, Matrix &flow,
    const vector<int> &level, vector<bool> &finished, int u, int t, Weight cur) {
  if (u == t || cur == 0) return cur;
  if (finished[u]) return 0;
  finished[u] = true;
  FOR(e, g[u]) if (level[e->dst] > level[u]) {
    Weight f = augment(g, capacity, flow, level, finished,
        e->dst, t, min(cur, RESIDUE(u, e->dst)));
    if (f > 0) {
      flow[u][e->dst] += f; flow[e->dst][u] -= f;
      finished[u] = false;
      return f;
    }
  }
  return 0;
}

Matrix flow, capacity;
Weight Dinic(const Graph &g, int s, int t) {
  int n = g.size();
  flow.assign(n,Array(n));
  capacity.assign(n,Array(n));
  REP(u,n) FOR(e,g[u]) capacity[e->src][e->dst] += e->weight;

  Weight total = 0;
  for (bool cont = true; cont; ) {
    cont = false;
    vector<int> level(n, -1); level[s] = 0; // make layered network
    queue<int> Q; Q.push(s);
    for (int d = n; !Q.empty() && level[Q.front()] < d; ) {
      int u = Q.front(); Q.pop();
      if (u == t) d = level[u];
      FOR(e, g[u]) if (RESIDUE(u,e->dst) > 0 && level[e->dst] == -1)
        Q.push(e->dst), level[e->dst] = level[u] + 1;
    }
    vector<bool> finished(n); // make blocking flows
    for (Weight f = 1; f > 0; ) {
      f = augment(g, capacity, flow, level, finished, s, t, INF);
      if (f == 0) break;
      total += f; cont = true;
    }
  }
  return total;
}

int y[1000];
int x[1000];
int a[1000];
int b[1000];

int tmp[1000];
int ans[1000];

bool visited[1002];
int n,w;

int solve(int f) {
  Graph g(n+2);
  int res = 0;
  REP(i,n) {
    if (i==0) {
      // y[0] != 1ならa[i]の損失
      add_edge(g,i,n+1,a[i]);
    } else if (i==n-1) {
      if ((i%2 == 0) ^ f) {
        add_edge(g,n,i-1,a[i]);
      } else {
        add_edge(g,i-1,n+1,a[i]);
      }
    } else {
      // y[i] != y[i-1] なら a[i]の損失
      add_edge(g,i,i-1,a[i]);
      add_edge(g,i-1,i,a[i]);
    }
    // y[i-w-1] != y[i+w]ならb[i]の損失
    int l = i-w-1;
    int r = i+w;
    if (l < 0 && r >= n-1) {
      if (!f) res += b[i];
      // if ( (abs(l)%2 == r%2) ^ f) res += b[i];
    } else if (l < 0) {
      if ( r%2 != 0 ) add_edge(g,n,r,b[i]);
      else add_edge(g,r,n+1,b[i]);
    } else if (r >= n-1) {
      if (( l%2 != 0 )^f) add_edge(g,n,l,b[i]);
      else add_edge(g,l,n+1,b[i]);
    } else {
      add_edge(g,l,r,b[i]);
      add_edge(g,r,l,b[i]);
    }
  }
  // cout << ":" << res << endl;
  res += Dinic(g,n,n+1);
  queue<int> Q;
  Q.push(n);
  memset(visited,0,sizeof(visited));
  visited[n] = 1;
  REP(i,n) y[i] = 1;
  while(!Q.empty()) {
    int p = Q.front(); Q.pop();
    if (p<n) y[p] = 0;
    FOR(e,g[p]) {
      if (flow[e->src][e->dst] < capacity[e->src][e->dst]) {
        if (!visited[e->dst]) {
          visited[e->dst] = 1;
          Q.push(e->dst);
        }
      }
    }
  }
  REP(i,n-1) x[i] = y[i] ^ (i%2);
  x[n-1] = f;
  // REP(i,n) cout << y[i] << " "; cout << endl;
  // REP(i,n) cout << x[i] << " "; cout << endl;
  bool p = 0;
  REP(i,n) {
    tmp[i] = x[i]^p;
    p ^= tmp[i];
  }
//    cout << ":" << res << endl;
  // REP(i,n) cout << tmp[i]; cout << endl;
  return res;
}

int main() {
  while(cin>>n>>w) {
    int sum = 0;
    REP(i,n) {
      cin >> a[i];
      sum += a[i];
    }
    REP(i,n) {
      cin >> b[i];
      sum += b[i];
    }
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    int ansv = solve(0);
    REP(i,n) ans[i] = tmp[i]; 
    int t = solve(1);
    if (chmin(ansv,t)) {
      REP(i,n) ans[i] = tmp[i];
    }
    // cout << "ans = " << sum - ansv << endl;
    REP(i,n) cout << ans[i]; cout << endl;
  }
}