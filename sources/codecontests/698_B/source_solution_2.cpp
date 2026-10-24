#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
int a[N], cmp, ans;
vector<int> adj[N];
queue<int> q;
int visited[N];
void dfs(int u, int par = -1) {
  visited[u] = cmp;
  for (int v : adj[u]) {
    if (!visited[v]) {
      dfs(v, u);
    } else if (visited[v] == cmp) {
      q.push(v);
    }
  }
}
int main() {
  int n, x, root = -1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    a[i] = x;
    adj[i].push_back(x);
    if (x == i) {
      root = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      ++cmp;
      dfs(i);
    }
  }
  if (root == -1) {
    root = q.front();
    q.pop();
    a[root] = root;
    ++ans;
  }
  while (!q.empty()) {
    a[q.front()] = root;
    if (q.front() != root) ans++;
    q.pop();
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
