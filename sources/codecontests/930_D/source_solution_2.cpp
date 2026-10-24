#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, s, n, m, L[4][500005], R[4][500005], x, y, ma[4], mi[4];
long long ans;
struct node {
  int x, y, s;
} a[500005];
inline bool cmp(const node &x, const node &y) { return x.x < y.x; }
inline bool cmp1(const node &x, const node &y) { return x.x > y.x; }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d%d", &x, &y), a[i].x = x + y, a[i].y = x - y,
                           a[i].s = (a[i].y % 4 + 4) % 4;
  sort(a + 1, a + 1 + n, cmp);
  for (k = 0; k < 4; k++) ma[k] = -1000000000, mi[k] = 1000000000;
  j = 1;
  for (i = a[1].x; i <= a[n].x; i++) {
    if (i & 1) {
      L[1][i + 200000] = max(ma[0] + 1, ma[2] + 3);
      L[3][i + 200000] = max(ma[0] + 3, ma[2] + 1);
      R[1][i + 200000] = min(mi[0] - 3, mi[2] - 1);
      R[3][i + 200000] = min(mi[0] - 1, mi[2] - 3);
    } else {
      L[0][i + 200000] = max(ma[3] + 1, ma[1] + 3);
      L[2][i + 200000] = max(ma[3] + 3, ma[1] + 1);
      R[0][i + 200000] = min(mi[3] - 3, mi[1] - 1);
      R[2][i + 200000] = min(mi[3] - 1, mi[1] - 3);
    }
    while (j <= n && a[j].x <= i)
      ma[a[j].s] = max(ma[a[j].s], a[j].y),
      mi[a[j].s] = min(mi[a[j].s], a[j].y), j++;
  }
  sort(a + 1, a + 1 + n, cmp1);
  for (k = 0; k < 4; k++) ma[k] = -1000000000, mi[k] = 1000000000;
  j = 1;
  for (i = a[1].x; i >= a[n].x; i--) {
    if (i & 1) {
      L[1][i + 200000] = min(L[1][i + 200000], max(ma[0] + 1, ma[2] + 3));
      L[3][i + 200000] = min(L[3][i + 200000], max(ma[0] + 3, ma[2] + 1));
      R[1][i + 200000] = max(R[1][i + 200000], min(mi[0] - 3, mi[2] - 1));
      R[3][i + 200000] = max(R[3][i + 200000], min(mi[0] - 1, mi[2] - 3));
    } else {
      L[0][i + 200000] = min(L[0][i + 200000], max(ma[3] + 1, ma[1] + 3));
      L[2][i + 200000] = min(L[2][i + 200000], max(ma[3] + 3, ma[1] + 1));
      R[0][i + 200000] = max(R[0][i + 200000], min(mi[3] - 3, mi[1] - 1));
      R[2][i + 200000] = max(R[2][i + 200000], min(mi[3] - 1, mi[1] - 3));
    }
    while (j <= n && a[j].x == i)
      ma[a[j].s] = max(ma[a[j].s], a[j].y),
      mi[a[j].s] = min(mi[a[j].s], a[j].y), j++;
  }
  for (i = a[n].x; i <= a[1].x; i++) {
    if (i & 1) {
      ans += max(0, (L[1][i + 200000] - R[1][i + 200000] - 1) / 4);
      ans += max(0, (L[3][i + 200000] - R[3][i + 200000] - 1) / 4);
    } else {
      ans += max(0, (L[0][i + 200000] - R[0][i + 200000] - 1) / 4);
      ans += max(0, (L[2][i + 200000] - R[2][i + 200000] - 1) / 4);
    }
  }
  printf("%I64d\n", ans);
}
