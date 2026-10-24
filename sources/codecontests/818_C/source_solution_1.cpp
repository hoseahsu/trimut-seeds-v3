#include <bits/stdc++.h>
using namespace std;
int L[100010], R[100010], T[100010], B[100010];
int xmin[100010], xmax[100010], ymin[100010], ymax[100010];
int main() {
  int d, n, m, cntl, cntr, cntt, cntb;
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1; i <= d; ++i) {
    int x_1, y_1, x_2, y_2;
    scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
    xmin[i] = min(x_1, x_2);
    xmax[i] = max(x_1, x_2);
    ymin[i] = min(y_1, y_2);
    ymax[i] = max(y_1, y_2);
    L[xmin[i]]++;
    R[xmax[i]]++;
    T[ymin[i]]++;
    B[ymax[i]]++;
  }
  scanf("%d%d%d%d", &cntl, &cntr, &cntt, &cntb);
  for (int i = 1; i <= n; ++i) L[i] += L[i - 1];
  for (int i = n; i; --i) R[i] += R[i + 1];
  for (int i = 1; i <= m; ++i) T[i] += T[i - 1];
  for (int i = m; i; --i) B[i] += B[i + 1];
  int ans = -1;
  for (int i = 1; i <= d; ++i) {
    int g = 0;
    if (L[xmax[i] - 1] - (xmax[i] != xmin[i]) == cntl) ++g;
    if (R[xmin[i] + 1] - (xmax[i] != xmin[i]) == cntr) ++g;
    if (T[ymax[i] - 1] - (ymax[i] != ymin[i]) == cntt) ++g;
    if (B[ymin[i] + 1] - (ymax[i] != ymin[i]) == cntb) ++g;
    if (g == 4) ans = i;
  }
  cout << ans;
}
