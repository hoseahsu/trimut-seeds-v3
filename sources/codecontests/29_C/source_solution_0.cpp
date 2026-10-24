#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000 + 5;
int n;
map<int, bool> visited;
map<int, vector<int> > V;
queue<int> Q;
void Input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    V[x].push_back(y);
    V[y].push_back(x);
  }
}
void DFS(int s) {
  Q.push(s);
  visited[s] = true;
  for (int i = 0; i < V[s].size(); i++) {
    int t = V[s][i];
    if (visited[t] == false) DFS(t);
  }
}
void Solve() {
  int temp = 0, t = 0, s = 0;
  for (__typeof(V.begin()) i = V.begin(); i != V.end(); i++) {
    temp = i->first;
    s = i->second.size();
    if (i->second.size() == 1) t = i->first;
  }
  DFS(t);
  while (!Q.empty()) {
    cout << Q.front() << " ";
    Q.pop();
  }
}
int main() {
  Input();
  Solve();
  return 0;
}
