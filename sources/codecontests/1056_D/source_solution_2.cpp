#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int lcnt[100001];
void dfs(int x, int prev) {
  if (adj[x].size() == 1 && adj[x][0] == prev) {
    lcnt[x] = 1;
  }
  for (auto y : adj[x]) {
    if (y != prev) {
      dfs(y, x);
      lcnt[x] += lcnt[y];
    }
  }
}
int main() {
  int n, pi;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> pi;
    adj[i].push_back(pi);
    adj[pi].push_back(i);
  }
  adj[1].push_back(0);
  dfs(1, 0);
  sort(lcnt, lcnt + n + 1);
  for (int i = 1; i <= n; ++i) {
    cout << lcnt[i] << ' ';
  }
}
