#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
char g[330][330];
int main() {
  int n, m, p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
  int cnt = 0;
  int px, py;
  int md = 10000;
  int limit = min(n, m);
  int flag = 0;
  int u, v;
  for (int k = 1; k <= limit; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (g[i][j] == '*') {
          int t = 0;
          for (int l = 0; l < 4; ++l) {
            u = i + dx[l] * k;
            v = j + dy[l] * k;
            if (u > 0 && u <= n && v > 0 && v <= m && g[u][v] == '*') t++;
          }
          if (t == 4) {
            cnt++;
            flag++;
            if (flag == p) {
              md = k;
              flag++;
              px = i;
              py = j;
            }
          }
        }
      }
    }
  }
  if (flag < p) {
    puts("-1");
  } else {
    printf("%d %d\n", px, py);
    for (int i = 0; i < 4; ++i)
      printf("%d %d\n", px + dx[i] * md, py + dy[i] * md);
  }
  return 0;
}
