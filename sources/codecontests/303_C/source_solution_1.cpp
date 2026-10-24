#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
int num[maxn];
int a[5500];
bool flag[maxn];
int dif(int a, int b) { return a > b ? a - b : b - a; }
int main() {
  int n, k, i, j, maxa, m, mark, sum, cn, mod;
  maxa = -1;
  while (scanf("%d%d", &n, &k) != EOF) {
    memset(num, 0, sizeof(num));
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      maxa = (a[i]) > (maxa) ? (a[i]) : (maxa);
    }
    for (i = 1; i < n; i++) {
      for (j = 0; j < i; j++) {
        num[dif(a[i], a[j])]++;
      }
    }
    for (m = 1; m <= maxa; m++) {
      sum = 0;
      for (i = m; i <= maxa; i += m) {
        sum += num[i];
        if (sum > k * (k + 1) / 2) {
          break;
        }
      }
      if (sum > k * (k + 1) / 2) {
        continue;
      }
      cn = 0, mark = 0;
      for (j = 0; j < n && (!mark); j++) {
        mod = a[j] % m;
        if (!flag[mod]) {
          flag[mod] = 1;
        } else {
          cn++;
          if (cn > k) {
            mark = 1;
          }
        }
      }
      for (j = 0; j < n; j++) {
        flag[a[j] % m] = 0;
      }
      if (!mark) {
        mark = m;
        break;
      }
    }
    printf("%d\n", mark);
  }
  return 0;
}
