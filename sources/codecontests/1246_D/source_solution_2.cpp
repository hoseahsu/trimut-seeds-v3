#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int pre[N];
int dp[N][2];
int a[N];
int c[N];
int lastChild[N];
int lastHeight[N];
vector<int> ans;
int tot;
void dfsRun(int u, int offset, bool last) {
  a[offset] = u;
  vector<int> child;
  for (auto v : graph[u]) {
    if (v != lastChild[u]) {
      child.push_back(v);
    }
  }
  offset += 1;
  for (auto v : child) {
    dfsRun(v, offset, false);
    offset += c[v];
    ans.insert(ans.end(), lastHeight[v], offset);
    tot += lastHeight[v];
  }
  if (lastChild[u] != -1) {
    dfsRun(lastChild[u], offset, last);
  }
}
void dfsDp(int u) {
  c[u] = 1;
  dp[u][0] = 1;
  int minIdx = -1;
  int minValue = 1e9;
  for (auto v : graph[u]) {
    dfsDp(v);
    c[u] += c[v];
    dp[u][0] += dp[v][0];
    if (dp[v][1] - dp[v][0] < minValue) {
      minValue = dp[v][1] - dp[v][0];
      minIdx = v;
    }
  }
  lastChild[u] = minIdx;
  lastHeight[u] = 1;
  if (minIdx != -1) {
    dp[u][1] = dp[u][0] - 1 + minValue;
    lastHeight[u] = lastHeight[minIdx] + 1;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d", &pre[i]);
    graph[pre[i]].push_back(i);
  }
  dfsDp(0);
  dfsRun(0, 0, true);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  printf("%d\n", tot);
  for (auto e : ans) {
    printf("%d ", a[e]);
  }
  printf("\n");
  return 0;
}
