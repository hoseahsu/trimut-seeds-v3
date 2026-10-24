#include <bits/stdc++.h>
using namespace std;
int ans[1010][1010];
int al[1010];
struct node {
  int id;
  int v;
} den[1010], qian[1010];
int dl = 0;
int ql = 0;
bool cmp(node a, node b) { return a.v > b.v; }
int main() {
  int n;
  scanf("%d", &n);
  ;
  int m;
  scanf("%d", &m);
  ;
  double cost = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    ;
    int y;
    scanf("%d", &y);
    ;
    if (y == 1) {
      den[dl].id = i;
      den[dl++].v = x;
    } else {
      qian[ql].id = i;
      qian[ql++].v = x;
    }
  }
  sort(den, den + dl, cmp);
  int i;
  for (i = 0; i < m - 1 && i < dl; i++) {
    ans[i][0] = den[i].id;
    al[i] = 1;
    cost += den[i].v / 2.0;
  }
  if (i < m - 1) {
    int j;
    for (j = 0; i < m - 1; i++, j++) {
      ans[i][0] = qian[j].id;
      al[i] = 1;
      cost += qian[j].v;
    }
    for (; j < ql; j++) {
      ans[m - 1][al[m - 1]++] = qian[j].id;
      cost += qian[j].v;
    }
  } else {
    int vmin = 0x3FFFFFFF;
    for (int j = 0; i < dl; i++, j++) {
      ans[m - 1][j] = den[i].id;
      al[m - 1]++;
      cost += den[i].v;
      if (den[i].v < vmin) vmin = den[i].v;
    }
    for (int j = 0; j < ql; j++) {
      ans[m - 1][al[m - 1]++] = qian[j].id;
      cost += qian[j].v;
      if (vmin != 0x3FFFFFFF && qian[j].v < vmin) vmin = qian[j].v;
    }
    if (vmin != 0x3FFFFFFF) cost -= vmin / 2.0;
  }
  printf("%.1lf\n", cost);
  for (int i = 0; i < m; i++) {
    printf("%d", al[i]);
    for (int j = 0; j < al[i]; j++) {
      printf(" %d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
