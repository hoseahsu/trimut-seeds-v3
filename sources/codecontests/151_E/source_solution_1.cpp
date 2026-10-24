#include <bits/stdc++.h>
using namespace std;
const int maxn = 150005;
const double inf = 1e30;
int n, m, c;
int x[maxn];
int p[maxn];
double s[maxn];
double sum[maxn];
struct SegTree {
  int l;
  int r;
  double max_l;
  double max_r;
  double max_s;
  double sum;
} T[maxn * 4 + 1];
void Build(int t, int l, int r) {
  T[t].l = l;
  T[t].r = r;
  T[t].max_l = -inf;
  T[t].max_r = -inf;
  T[t].max_s = -inf;
  T[t].sum = 0;
  if (T[t].l < T[t].r - 1) {
    int mid = (T[t].l + T[t].r) / 2;
    Build(2 * t, T[t].l, mid);
    Build(2 * t + 1, mid, T[t].r);
  }
  return;
}
void Adjust(int t, int l, int r) {
  if (T[t].l == T[t].r - 1) {
    T[t].max_l = s[T[t].l];
    T[t].max_r = s[T[t].l];
    T[t].max_s = s[T[t].l];
    T[t].sum = s[T[t].l];
    return;
  }
  int mid = (l + r) / 2;
  Adjust(2 * t, l, mid);
  Adjust(2 * t + 1, mid, r);
  T[t].sum = T[2 * t].sum + T[2 * t + 1].sum;
  T[t].max_l = max(T[2 * t].max_l, T[2 * t].sum + T[2 * t + 1].max_l);
  T[t].max_r = max(T[2 * t + 1].max_r, T[2 * t + 1].sum + T[2 * t].max_r);
  T[t].max_s =
      max(max(T[t].max_l, T[t].max_r), max(T[2 * t].max_s, T[2 * t + 1].max_s));
  T[t].max_s = max(T[t].max_s, T[2 * t].max_r + T[2 * t + 1].max_l);
  return;
}
SegTree Find_max(int t, int l, int r) {
  if (T[t].l == l && T[t].r == r) return T[t];
  int mid = (T[t].l + T[t].r) / 2;
  if (r <= mid)
    return Find_max(2 * t, l, r);
  else if (l >= mid)
    return Find_max(2 * t + 1, l, r);
  else {
    SegTree ans1 = Find_max(2 * t, l, mid);
    SegTree ans2 = Find_max(2 * t + 1, mid, r);
    SegTree ans;
    ans.max_l = max(ans1.max_l, sum[mid - 1] - sum[l - 1] + ans2.max_l);
    ans.max_r = max(ans2.max_r, sum[r - 1] - sum[mid - 1] + ans1.max_r);
    ans.max_s = max(max(ans.max_l, ans.max_r), max(ans1.max_s, ans2.max_s));
    ans.max_s = max(ans.max_s, ans1.max_r + ans2.max_l);
    return ans;
  }
}
int main() {
  int a, b;
  while (scanf("%d %d %d", &n, &m, &c) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= n - 1; i++) scanf("%d", &p[i]);
    Build(1, 1, n);
    sum[0] = 0.0;
    for (int i = 2; i <= n; i++) {
      s[i - 1] = (x[i] - x[i - 1]) / 2.0 - p[i - 1] / 100.0 * c;
      sum[i - 1] = sum[i - 2] + s[i - 1];
    }
    Adjust(1, 1, n);
    double ans = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d", &a, &b);
      SegTree temp = Find_max(1, a, b);
      if (temp.max_s > 0) ans += temp.max_s;
    }
    printf("%.6f\n", ans);
  }
  return 0;
}
