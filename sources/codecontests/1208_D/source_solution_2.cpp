#include <bits/stdc++.h>
using namespace std;
long long n, a[500001], f[500001], ans[500001], mn;
int lowbit(int x) { return x & (-x); }
void ins(long long x, long long w) {
  long long i;
  for (i = x; i <= n; i += lowbit(i)) f[i] += w;
}
long long query(long long x) {
  long long xlh = 0, i;
  for (i = x; i; i -= lowbit(i)) xlh += f[i];
  return xlh;
}
int main() {
  long long i, l, r, mid;
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (i = 1; i <= n; i++) ins(i, i);
  for (i = n; i; i--) {
    l = 1;
    r = n;
    mn = 1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (query(mid - 1) <= a[i])
        mn = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    ins(mn, -mn);
    ans[i] = mn;
  }
  for (i = 1; i <= n; i++) printf("%lld ", ans[i]);
}
