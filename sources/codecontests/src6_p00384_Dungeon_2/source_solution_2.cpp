#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> p;
vector<vector<i64>> G;

vector<i64> go;
vector<i64> ba;

void dfs(i64 v, i64 f) {
  i64 DIFF = 0;
  i64 SUM = 0;
  for(auto x: G[v]) {
    if(x == f) continue;
    dfs(x, v);
    if(ba[x] - 2 <= 0) {
      DIFF = max(DIFF, go[x] - 1);
    }
    else {
      SUM += ba[x] - 2;
      DIFF = max(DIFF, go[x] - 1 - (ba[x] - 2));
    }
  }
  ba[v] = SUM + p[v];
  go[v] = SUM + DIFF + p[v];

  //cout << v << " " << ba[v] << " " << go[v] << endl;
}

vector<i64> ans;

void rerooting(i64 v, i64 f, i64 fgo, i64 fba) {
  vector<pair<i64, i64>> diff;
  diff.push_back({ 0, -1 });
  i64 SUM = 0;
  i64 DIFF = 0;
  for(auto x: G[v]) {
    i64 g, b;
    if(x == f) {
      g = fgo;
      b = fba;
    }
    else {
      g = go[x];
      b = ba[x];
    }
    if(b - 2 <= 0) {
      DIFF = max(DIFF, g - 1);
      diff.push_back({ g - 1, x });
    }
    else {
      SUM += b - 2;
      DIFF = max(DIFF, g - 1 - (b - 2));
      diff.push_back({ g - 1 - (b - 2), x });
    }
  }
  ans[v] = SUM + DIFF + p[v];
  sort(begin(diff), end(diff));
  reverse(begin(diff), end(diff));
  for(auto x: G[v]) {
    if(x == f) continue;
    i64 s = SUM;
    if(ba[x] - 2 > 0) {
      s -= ba[x] - 2;
    }
    i64 g = s;
    if(diff.front().second != x) {
      g += diff.front().first;
    }
    else {
      g += diff[1].first;
    }
    rerooting(x, v, g + p[v], s + p[v]);
  }
}

int main() {
  i64 N;
  cin >> N;
  p.resize(N);
  ans.resize(N);
  for(i64 i = 0;i < N;i++) cin >> p[i];
  G.resize(N);
  for(i64 i = 0;i < N - 1;i++) {
    i64 s, t;
    cin >> s >> t;
    s--;
    t--;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  go.resize(N, -1e18);
  ba.resize(N, -1e18);
  dfs(0, -1);
  rerooting(0, -1, 0, 0);
  cout << *max_element(begin(ans), end(ans)) << endl;
}

