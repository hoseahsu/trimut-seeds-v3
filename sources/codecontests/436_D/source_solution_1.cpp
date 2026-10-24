#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxm = 2005;
const int inf = 1e9;
int x[maxn];
int stx[maxm];
int ans[maxn], stop[maxn];
int left_sdf[maxn], right_sdf[maxn];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < m; i++) scanf("%d", &stx[i]);
  sort(x, x + n);
  sort(stx, stx + m);
  left_sdf[0] = 0;
  for (int i = 1; i < n; i++) {
    if (x[i] - 1 == x[i - 1])
      left_sdf[i] = left_sdf[i - 1];
    else
      left_sdf[i] = i;
  }
  right_sdf[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (x[i] + 1 == x[i + 1])
      right_sdf[i] = right_sdf[i + 1];
    else
      right_sdf[i] = i;
  }
  stx[m] = inf;
  ans[0] = 0;
  for (int i = 0; i < n; i++) {
    int starr = lower_bound(stx, stx + m, x[i]) - stx;
    bool onstar = stx[starr] == x[i];
    stop[i] = ans[i] + onstar;
    for (int j = 0; j < starr; j++) {
      int need = x[i] - stx[j];
      if (i >= need)
        stop[i] = max(stop[i], starr - j + ans[left_sdf[i - need]] + onstar);
    }
    ans[i + 1] = max(ans[i + 1], stop[i]);
    if (onstar) starr++;
    for (int j = starr; j < m; j++) {
      int need = stx[j] - x[i];
      if (n - i - 1 >= need) {
        ans[right_sdf[i + need] + 1] =
            max(ans[right_sdf[i + need] + 1], j - starr + 1 + stop[i]);
      }
    }
  }
  cout << ans[n] << endl;
  return 0;
}
