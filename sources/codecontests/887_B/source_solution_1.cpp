#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int num[200];
int vis[10];
int tot;
void dfs(int sumn, int tt) {
  if (tt > 2) return;
  num[sumn]++;
  for (int i = 1; i <= tot; i++) {
    if (vis[i] == 0) {
      vis[i] = 1;
      for (int j = 1; j <= 6; j++) {
        dfs(sumn * 10 + a[i][j], tt + 1);
      }
      vis[i] = 0;
    }
  }
}
int main() {
  while (cin >> tot) {
    for (int i = 1; i <= tot; i++) {
      for (int j = 1; j <= 6; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(num, 0, sizeof(num));
    memset(vis, 0, sizeof(vis));
    dfs(0, 0);
    for (int i = 0; i <= 99; i++) {
      if (num[i] == 0) {
        printf("%d\n", i - 1);
        break;
      }
    }
  }
  return 0;
}
