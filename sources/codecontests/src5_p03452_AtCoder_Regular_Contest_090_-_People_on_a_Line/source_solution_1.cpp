#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF=(int)(1<<30);
vector<pair<int, int> > graph[101010];
int vis[101010];
int d[101010];

void dfs(int cur, long long S) {
  if(vis[cur] == 1) {
    if(d[cur] != S) {
      cout << "No" << endl;
      exit(0);
    }
    return;
  }
  vis[cur] = 1;
  d[cur] = S;
  for(auto g:graph[cur]) dfs(g.first, S+g.second);
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> L(M), R(M), D(M);
  for(int i = 0; i < M; ++i) {
    cin >> L[i] >> R[i] >> D[i];
    L[i]--, R[i]--;
    graph[L[i]].push_back(make_pair(R[i], D[i]));
    graph[R[i]].push_back(make_pair(L[i], -D[i]));
  }
  for(int i = 0; i < N; ++i) {
    if(vis[i] == 0) dfs(i, 0);
  }
  cout << "Yes" << endl;
  return 0;
}