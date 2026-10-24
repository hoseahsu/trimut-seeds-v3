#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
vector<int> adj[1000005];
vector<int> adj_r[1000005];
bool use[1000005];
bool use_r[1000005];
vector<int> ans;
void dfs(int node, stack<int> &s) {
  use[node] = 1;
  for (auto it : adj[node]) {
    if (use[it] == 0) {
      dfs(it, s);
    }
  }
  s.push(node);
  return;
}
void dfs_r(int node, stack<int> &sr) {
  use_r[node] = 1;
  for (auto it : adj_r[node]) {
    if (use_r[it] == 0) {
      dfs_r(it, sr);
    }
  }
  sr.push(node);
  return;
}
void init(int n) {
  memset(use, 0, sizeof(bool) * n);
  memset(use_r, 0, sizeof(bool) * n);
  ans.clear();
  for (int i = 0; i < n; i++) {
    adj[i].clear();
    adj_r[i].clear();
  }
  return;
}
int main() {
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d%d", &n, &m);
    for (int j = 0; j < m; j++) {
      int jm, cm;
      scanf("%d%d", &jm, &cm);
      if (jm == cm) continue;
      adj[jm].push_back(cm);
      adj_r[cm].push_back(jm);
    }
    stack<int> s;
    dfs(1, s);
    if (s.size() < n) {
      int ss = s.size();
      for (int j = 0; j < ss; j++) {
        ans.push_back(s.top());
        s.pop();
      }
      printf("Yes\n");
      printf("%d %d\n", ans.size(), n - ans.size());
      sort(ans.begin(), ans.end());
      for (int j = 0; j < ans.size(); j++) {
        printf("%d ", ans[j]);
      }
      printf("\n");
      for (int j = 1; j <= n; j++) {
        if (use[j] == 0) printf("%d ", j);
      }
      printf("\n");
      init(n + 1);
      continue;
    }
    int count = 0;
    unordered_set<int> off;
    for (int j = 0; j < n; j++) {
      int idx = s.top();
      s.pop();
      if (use_r[idx]) continue;
      stack<int> sr;
      dfs_r(idx, sr);
      if (sr.size() == n) {
        printf("No\n");
        init(n + 1);
        break;
      } else {
        count += sr.size();
        if (count == n) {
          int ssr = sr.size();
          for (int k = 0; k < ssr; k++) {
            ans.push_back(sr.top());
            off.insert(sr.top());
            sr.pop();
          }
          sort(ans.begin(), ans.end());
          printf("Yes\n");
          printf("%d %d\n", ans.size(), n - ans.size());
          for (int j = 0; j < ans.size(); j++) {
            printf("%d ", ans[j]);
          }
          printf("\n");
          for (int j = 1; j <= n; j++) {
            if (off.find(j) == off.end()) {
              printf("%d ", j);
            }
          }
          printf("\n");
          init(n + 1);
          break;
        }
      }
    }
  }
  return 0;
}
