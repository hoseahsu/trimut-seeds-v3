#include <bits/stdc++.h>
using namespace std;
int n, m;
int tota = 0, totb = 0, totc = 0;
long long a[100005], b[100005], c[100005];
long long qa[100005], qb[100005], qc[100005];
long long ans = 0;
inline bool cmp(long long x, long long y) { return x > y; }
inline void make() {
  sort(a + 1, a + tota + 1, cmp);
  sort(b + 1, b + totb + 1, cmp);
  sort(c + 1, c + totc + 1, cmp);
  for (register int i = 1; i <= tota; ++i) qa[i] = qa[i - 1] + a[i];
  for (register int i = 1; i <= totb; ++i) qb[i] = qb[i - 1] + b[i];
  for (register int i = 1; i <= totc; ++i) qc[i] = qc[i - 1] + c[i];
}
inline long long val(int x, int y) {
  return qc[x] + qb[y] + qa[min(tota, m - 3 * x - 2 * y)];
}
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; ++i) {
    long long W, C;
    scanf("%lld%lld", &W, &C);
    if (W == 1)
      a[++tota] = C;
    else if (W == 2)
      b[++totb] = C;
    else
      c[++totc] = C;
  }
  make();
  for (register int i = 0; i <= min(totc, m / 3); ++i) {
    int l = 0, r = min(totb, (m - i * 3) >> 1);
    while (l < r - 1) {
      int lmid = (l + r) >> 1, rmid = (lmid + r) >> 1;
      if (val(i, lmid) <= val(i, rmid))
        l = lmid;
      else
        r = rmid;
    }
    ans = max(ans, max(val(i, l), val(i, r)));
  }
  printf("%lld\n", ans);
  return 0;
}
