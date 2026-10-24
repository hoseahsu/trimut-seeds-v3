#include <bits/stdc++.h>
using namespace std;
const int N = 5010, inf = 1 << 30;
int f[N][N], la[200], lb[200];
char a[N], b[N], str[N];
int main() {
  int ti, td, tr, te, n1, n2, x;
  scanf("%d%d%d%d", &ti, &td, &tr, &te);
  scanf("%s", str);
  n1 = strlen(str);
  for (int i = 1; i <= n1; ++i) a[i] = str[i - 1];
  scanf("%s", str);
  n2 = strlen(str);
  for (int i = 1; i <= n2; ++i) b[i] = str[i - 1];
  memset(lb, -1, sizeof(lb));
  for (int i = 0; i <= n1; ++i) f[i][0] = td * i;
  for (int i = 1; i <= n2; ++i) f[0][i] = ti * i;
  for (int j = 1; j <= n2; ++j) {
    memset(la, -1, sizeof(la));
    for (int i = 1; i <= n1; ++i) {
      if (a[i] == b[j])
        f[i][j] = f[i - 1][j - 1];
      else
        f[i][j] = inf;
      f[i][j] = min(f[i][j], f[i][j - 1] + ti);
      f[i][j] = min(f[i][j], f[i - 1][j] + td);
      f[i][j] = min(f[i][j], f[i - 1][j - 1] + tr);
      if (a[i] != b[j] && la[b[j]] != -1 && lb[a[i]] != -1) {
        x = f[la[b[j]] - 1][lb[a[i]] - 1] + te;
        x += td * (i - la[b[j]] - 1) + ti * (j - lb[a[i]] - 1);
        f[i][j] = min(f[i][j], x);
      }
      la[a[i]] = i;
    }
    lb[b[j]] = j;
  }
  printf("%d\n", f[n1][n2]);
}
