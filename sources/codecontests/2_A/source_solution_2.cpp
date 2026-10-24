#include <bits/stdc++.h>
using namespace std;
char name[1001][50], s[50], t[1001][50];
int i, n, j, y[1001], mx, imx, m = 0, x, a[1001], fl, b[1001];
int main() {
  cin >> n;
  for (i = 0; i < n; ++i) cin >> t[i] >> y[i];
  for (i = 0; i < n; i++) {
    strcpy(s, t[i]);
    x = y[i];
    fl = 0;
    for (j = 0; j < m; j++)
      if (!strcmp(s, name[j])) {
        fl++;
        a[j] += x;
        break;
      }
    if (!fl) {
      strcpy(name[m], s);
      a[m] = x;
      m++;
    }
  }
  for (i = 0; i < m; ++i)
    if (a[i] > mx) mx = a[i];
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j)
      if (!strcmp(name[j], t[i])) {
        b[j] += y[i];
        if (a[j] == mx && b[j] >= mx) {
          cout << name[j];
          return 0;
        }
      }
  }
  cout << name[imx];
  return 0;
}
