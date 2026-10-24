#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
void solve();
signed main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
int n, m, used[300000], u, v;
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 3 * n; i++) used[i] = 0;
  std::vector<int> e;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    if (used[u - 1] == 0 and used[v - 1] == 0) {
      used[u - 1] = 1;
      used[v - 1] = 1;
      e.push_back(i + 1);
    }
  }
  if (e.size() >= n) {
    printf("Matching\n");
    for (int i = 0; i < n; i++) {
      printf("%d ", e[i]);
    }
    printf("\n");
  } else {
    int cnt = 0;
    printf("IndSet\n");
    for (int i = 0; i < 3 * n; i++) {
      if (used[i] == 0) {
        printf("%d ", i + 1);
        cnt++;
        if (cnt == n) break;
      }
    }
    printf("\n");
  }
}
