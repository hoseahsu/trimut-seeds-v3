#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
using Graph = vector<vector<P>>;
const ll INF = 1e18;
int main(){
  int n, m;
  cin >> n >> m;
  Graph G(n);
  /*コスト０の逆辺 */
  for (int i = n-1; i > 0; i--) {
    G[i].push_back({0,i-1});
  }
  rep(i,m) {
    int l, r, c;
    cin >> l >> r >> c;
    l--; r--;
    G[l].push_back({c,r});
  }

  auto dijkstra = [&] {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> que;
    vector<ll> d(n,INF);
    d[0] = 0;
    que.push({0,0});
    while (!que.empty()) {
      auto p = que.top();
      que.pop();
      if (d[p.second] < p.first) continue;
      for (auto v : G[p.second]) {
        if (d[v.second] <= d[p.second] + v.first) continue;
        que.push({d[p.second] + v.first, v.second});
        d[v.second] = d[p.second] + v.first;
      }
    }
    return d[n-1];
  };
  ll res = dijkstra();
  cout << (res == INF ? -1 : res) << endl;
  return 0;
} 