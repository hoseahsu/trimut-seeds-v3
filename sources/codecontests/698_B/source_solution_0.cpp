#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2e5 + 5;
int n, answer, root, curr;
int parent[NMAX];
int vis[NMAX];
vector<int> roots;
void dfs(int node) {
  if (vis[node] != 0) {
    if (vis[node] == curr) {
      parent[node] = node;
      roots.push_back(node);
    } else {
      return;
    }
  }
  vis[node] = curr;
  if (node != parent[node]) {
    dfs(parent[node]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> parent[i];
    if (parent[i] == i) {
      root = i;
      roots.push_back(i);
    }
  }
  if (roots.empty()) answer = 1;
  for (int i = 1; i <= n; ++i) {
    ++curr;
    dfs(i);
  }
  for (int &x : roots) {
    parent[x] = roots[0];
    ++answer;
  }
  --answer;
  cout << answer << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << parent[i] << ' ';
  }
  return 0;
}
