#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100010;
int n;
int f[MAX_N], g[MAX_N], h[MAX_N];
int show[MAX_N];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
      if (f[i] != f[f[i]]) flag = 1;
    }
    if (flag)
      puts("-1");
    else {
      memset(show, -1, sizeof(show));
      int tot = 0;
      for (int i = 1; i <= n; ++i) {
        int& cur = show[f[i]];
        if (cur == -1) {
          cur = ++tot;
          h[tot] = f[i];
        }
        g[i] = cur;
      }
      printf("%d\n", tot);
      for (int i = 1; i <= n; ++i) printf("%d ", g[i]);
      puts("");
      for (int i = 1; i <= tot; ++i) printf("%d ", h[i]);
      puts("");
    }
  }
  return 0;
}
