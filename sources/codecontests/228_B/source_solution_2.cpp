#include <bits/stdc++.h>
const unsigned long long P = 239017, MaxN = 2100000, INF = 100000000;
using namespace std;
int na, nb, ma, mb;
char a[510][501], b[510][510];
char s[1000];
int main() {
  scanf("%d%d", &na, &ma);
  for (int i = 1; i <= na; ++i) {
    scanf("%s", s);
    for (int j = 0; j < ma; ++j) a[i][j + 1] = s[j] - '0';
  }
  scanf("%d%d", &nb, &mb);
  for (int i = 1; i <= nb; ++i) {
    scanf("%s", s);
    for (int j = 0; j < mb; ++j) b[i][j + 1] = s[j] - '0';
  }
  int ans = 0, l = 0, r = 0;
  int f = max(na, nb), g = max(ma, mb);
  for (int x = -f; x <= f; ++x) {
    for (int y = -g; y <= g; ++y) {
      int k = 0;
      for (int i = 1; i <= na; ++i) {
        for (int j = 1; j <= ma; ++j) {
          if (i + x > 0 && j + y > 0) k += a[i][j] * b[i + x][j + y];
        }
      }
      if (k > ans) {
        ans = k;
        l = x, r = y;
      }
    }
  }
  printf("%d %d", l, r);
  return 0;
}
