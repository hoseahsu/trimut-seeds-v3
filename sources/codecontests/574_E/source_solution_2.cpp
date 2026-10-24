#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 5;
vector<int> w[nax];
bool del[nax];
int legs[nax];
void dfs(int a, int par = 0) {
  if (w[a].size() <= 2) {
    del[a] = true;
    for (int c = 0; c < w[a].size(); c++) {
      int b = w[a][c];
      if (b != par) dfs(b, a);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    w[a].push_back(b);
    w[b].push_back(a);
  }
  for (int a = 1; a <= n; ++a)
    if (w[a].size() == 1) dfs(a);
  for (int a = 1; a <= n; ++a)
    for (int c = 0; c < w[a].size(); c++) {
      int b = w[a][c];
      if (del[b]) legs[a] = min(legs[a] + 1, 2);
    }
  for (int a = 1; a <= n; ++a)
    if (!del[a]) {
      int cnt = 0;
      for (int c = 0; c < w[a].size(); c++) {
        int b = w[a][c];
        if (!del[b] && w[b].size() - legs[b] > 1) {
          ++cnt;
        }
      }
      if (cnt > 2) {
        puts("No");
        return 0;
      }
    }
  puts("Yes");
  return 0;
}
