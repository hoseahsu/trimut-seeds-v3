#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9;
long long sum[maxn << 2];
int mn[maxn << 2], mx[maxn << 2], lazy[maxn << 2], a[maxn];
inline void pushup(int rt) {
  int r1 = (rt << 1), r2 = (rt << 1 | 1);
  mn[rt] = min(mn[r1], mn[r2]);
  mx[rt] = max(mx[r1], mx[r2]);
  sum[rt] = sum[r1] + sum[r2];
}
inline void pushdown(int l, int r, int rt) {
  if (lazy[rt]) {
    int r1 = (rt << 1), r2 = (rt << 1 | 1), mid = (l + r) >> 1;
    sum[r1] = (mid - l + 1LL) * lazy[rt];
    sum[r2] = (long long)(r - mid) * lazy[rt];
    mx[r1] = mx[r2] = lazy[rt];
    mn[r1] = mn[r2] = lazy[rt];
    lazy[r1] = lazy[r2] = lazy[rt];
    lazy[rt] = 0;
  }
}
inline void build(int l, int r, int rt) {
  if (l == r)
    sum[rt] = mx[rt] = mn[rt] = a[l];
  else {
    int mid = (l + r) >> 1;
    build(l, mid, (rt << 1));
    build(mid + 1, r, (rt << 1 | 1));
    pushup(rt);
  }
}
inline void update(int l, int r, int x, int y, int rt) {
  if (r <= x && mx[rt] < y) {
    mx[rt] = mn[rt] = lazy[rt] = y;
    sum[rt] = (r - l + 1LL) * y;
    return;
  }
  pushdown(l, r, rt);
  int mid = (l + r) >> 1;
  if (mn[(rt << 1)] < y) update(l, mid, x, y, (rt << 1));
  if (x > mid && mn[(rt << 1 | 1)] < y) update(mid + 1, r, x, y, (rt << 1 | 1));
  pushup(rt);
}
inline int query(int l, int r, int L, int R, int k, int rt) {
  if (l == r) return mn[rt] <= k ? l : -1;
  pushdown(l, r, rt);
  int mid = (l + r) >> 1, ans = -1;
  if (L <= mid && mn[(rt << 1)] <= k)
    ans = query(l, mid, L, R, k, (rt << 1));
  else if (R > mid && mn[(rt << 1 | 1)] <= k)
    ans = query(mid + 1, r, L, R, k, (rt << 1 | 1));
  pushup(rt);
  return ans;
}
inline int getsum(int l, int r, int L, int R, int &y, int rt) {
  if (L <= l && r <= R && sum[rt] <= y) {
    y -= sum[rt];
    return r - l + 1;
  }
  if (l == r || !y) return 0;
  pushdown(l, r, rt);
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid && mn[(rt << 1)] <= y) ans += getsum(l, mid, L, R, y, (rt << 1));
  if (R > mid) ans += getsum(mid + 1, r, L, R, y, (rt << 1 | 1));
  pushup(rt);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, q, t, x, y;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, n, 1);
  while (q--) {
    cin >> t >> x >> y;
    if (t == 1) {
      update(1, n, x, y, 1);
    } else {
      int s = query(1, n, x, n, y, 1);
      if (~s)
        cout << getsum(1, n, s, n, y, 1) << '\n';
      else
        cout << 0 << '\n';
    }
  }
}
