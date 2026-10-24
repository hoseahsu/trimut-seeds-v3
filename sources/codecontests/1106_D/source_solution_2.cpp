#include <bits/stdc++.h>
using namespace std;
void Path(vector<vector<int> > AdjList, int n) {
  int ara[n], i, v, u;
  for (i = 0; i < n; i++) {
    ara[i] = -1;
  }
  ara[0] = 0;
  queue<int> road;
  priority_queue<int, vector<int>, greater<int> > pq;
  pq.push(0);
  while (!pq.empty()) {
    u = pq.top();
    pq.pop();
    road.push(u + 1);
    for (i = 0; i < AdjList[u].size(); i++) {
      v = AdjList[u][i];
      if (ara[v] == -1) {
        ara[v] = ara[u] + 1;
        pq.push(v);
      }
    }
  }
  while (!road.empty()) {
    cout << road.front() << " ";
    road.pop();
  }
}
int main() {
  int n, m, i, a, b;
  cin >> n >> m;
  vector<vector<int> > AdjList;
  AdjList.assign(n, vector<int>());
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    AdjList[a - 1].push_back(b - 1);
    AdjList[b - 1].push_back(a - 1);
  }
  Path(AdjList, n);
  return 0;
}
