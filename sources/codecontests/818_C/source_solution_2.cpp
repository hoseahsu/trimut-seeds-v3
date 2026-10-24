#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000000LL;
const int maxn = 1e5 + 10;
const int mod = 1000000007;
int d, n, m;
int xa[maxn], xb[maxn], ya[maxn], yb[maxn];
int cx1[maxn], cx2[maxn], cy1[maxn], cy2[maxn];
int xc, xd, yc, yd;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> d;
  cin >> n >> m;
  for (int i = 0; i < d; i++) {
    cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
    if (make_pair(xa[i], ya[i]) > make_pair(xb[i], yb[i])) {
      swap(xa[i], xb[i]);
      swap(ya[i], yb[i]);
    }
    cx1[i] = xa[i];
    cx2[i] = xb[i];
    cy1[i] = ya[i];
    cy2[i] = yb[i];
  }
  sort(cx1, cx1 + d);
  sort(cy1, cy1 + d);
  sort(cx2, cx2 + d);
  sort(cy2, cy2 + d);
  cin >> xc >> xd >> yc >> yd;
  int t1, t2;
  for (int i = 0; i < d; i++) {
    t1 = lower_bound(cx1, cx1 + d, xb[i]) - cx1;
    if (xa[i] < xb[i]) t1--;
    if (t1 != xc) continue;
    t1 = lower_bound(cy1, cy1 + d, yb[i]) - cy1;
    if (ya[i] < yb[i]) t1--;
    if (t1 != yc) continue;
    t1 = cx2 + d - upper_bound(cx2, cx2 + d, xa[i]);
    if (xa[i] < xb[i]) t1--;
    if (t1 != xd) continue;
    t1 = cy2 + d - upper_bound(cy2, cy2 + d, ya[i]);
    if (ya[i] < yb[i]) t1--;
    if (t1 != yd) continue;
    cout << i + 1 << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
