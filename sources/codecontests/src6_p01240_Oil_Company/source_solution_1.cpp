#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

template<class T> constexpr bool in_range(T y, T x, T H, T W) { return 0<=y&&y<H&&0<=x&&x<W; }

namespace flow {

struct edge {
  int to, cap, rev;
  edge(int t, int c, int r): to(t), cap(c), rev(r) {}
};

class dinic {

private:

  vector<vector<edge>> G;
  vector<int> level;
  vector<int> iter;

  void bfs(int s) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(auto& e: G[v]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  int dfs(int v, int t, int flow) {
    if(v == t) return flow;
    for(int& i = iter[v]; i < G[v].size(); i++) {
      auto& e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
        if(int d = dfs(e.to, t, min(flow, e.cap))) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

public:

  dinic(int N) : G(N), level(N), iter(N) {}

  void add_edge(int from, int to, int cap) {
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, 0, G[from].size()-1);
  }

  int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
      bfs(s);
      if(level[t] < 0) return flow;
      fill(iter.begin(), iter.end(), 0);
      int f;
      while((f = dfs(s, t, inf)) > 0) {
        flow += f;
      }
    }
  }

};
}

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main() {

  int TC; cin >> TC;
  rep(tc, TC) {

    int W, H; cin >> W >> H;

    vector<vector<int>> G(H);
    rep(i, H) G[i].resize(W);
    int total = 0;
    rep(i, H) rep(j, W) cin >> G[i][j], total += G[i][j];

    flow::dinic dn(H * W + 2);
    const int SRC = H * W, SINK = H * W + 1;
    rep(i, H) rep(j, W) {
      if((i + j) % 2) {
        dn.add_edge(SRC, i * W + j, G[i][j]);
      } else {
        rep(k, 4) {
          int ni = i + dy[k], nj = j + dx[k];
          if(!in_range(ni, nj, H, W)) continue;
          dn.add_edge(ni * W + nj, i * W + j, G[i][j]);
        }
        dn.add_edge(i * W + j, SINK, G[i][j]);
      }
    }

    cout << "Case " << tc + 1 << ": " << total - dn.max_flow(SRC, SINK) << endl;
  }
  
  return 0;
}