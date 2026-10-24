#include <bits/stdc++.h>
using namespace std;
char s[2010];
int i, j, k, n, m, f[2010][2010], ans, a[2010];
void add(int &x, int y) { x = (x + y) % 1000000007; }
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  f[0][0] = 1;
  a[0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      add(f[i][j], 1ll * (s[i - 1] - 'a') * a[j] % 1000000007);
      add(a[j], 1ll * (s[i - 1] - 'a') * a[j] % 1000000007);
    }
    for (j = 0; j <= m; j++)
      for (k = i - 1; k >= 0 && j + (n - i + 1) * (i - k) <= m; k--) {
        add(f[i][j + (n - i + 1) * (i - k)],
            1ll * ('z' - s[i - 1]) * f[k][j] % 1000000007);
        add(a[j + (n - i + 1) * (i - k)],
            1ll * ('z' - s[i - 1]) * f[k][j] % 1000000007);
      }
  }
  for (i = 0; i <= n; i++) add(ans, f[i][m]);
  cout << ans << endl;
}
