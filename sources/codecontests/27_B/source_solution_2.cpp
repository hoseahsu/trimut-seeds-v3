#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[3000][2];
int cnt[100] = {0};
vector<vector<int> > AL;
vector<int> dfs_num;
bool ans = false;
void dfs(int u, int y) {
  dfs_num[u] = 1;
  if (u == y) {
    ans = true;
    return;
  }
  for (auto &v : AL[u]) {
    if (dfs_num[v] == -1 && !ans) {
      dfs(v, y);
    }
  }
}
int main() {
  scanf("%d", &n);
  AL.assign(n + 1, vector<int>());
  x = (n * (n - 1)) / 2 - 1;
  for (int i = 1; i <= x; i++) {
    scanf("%d %d", &a[i][0], &a[i][1]);
    cnt[a[i][0]]++;
    cnt[a[i][1]]++;
    AL[a[i][0]].emplace_back(a[i][1]);
  }
  int p1 = -1, p2 = -1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] != n - 1) {
      if (p1 == -1) {
        p1 = i;
      } else {
        p2 = i;
      }
    }
  }
  dfs_num.assign(n + 1, -1);
  dfs(p1, p2);
  if (ans) {
    printf("%d %d\n", p1, p2);
    return 0;
  }
  printf("%d %d\n", p2, p1);
}
