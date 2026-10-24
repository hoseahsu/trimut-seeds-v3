#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[200005], w[200005];
const int N = 2e5;
struct ft {
  long long ft[N + 5];
  void update(int i, int v) {
    for (; i <= N; i += (i & -i)) {
      ft[i] += v;
    }
  }
  long long query(int i) {
    long long res = 0;
    for (; i > 0; i -= (i & -i)) res += ft[i];
    return res;
  }
} ft;
struct ft2 {
  long long ft[N + 5];
  void update(int i, int v) {
    for (; i <= N; i += (i & -i)) {
      ft[i] = (ft[i] + v + mod) % mod;
    }
  }
  long long query(int i) {
    long long res = 0;
    for (; i > 0; i -= (i & -i)) res = (res + ft[i]) % mod;
    return res;
  }
} ft2;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    ft.update(i, w[i]);
    ft2.update(i, (long long)a[i] * w[i] % mod);
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l < 0) {
      l = -l;
      ft.update(l, -w[l]);
      ft2.update(l, -((long long)w[l] * a[l] % mod));
      w[l] = r;
      ft.update(l, w[l]);
      ft2.update(l, (long long)w[l] * a[l] % mod);
    } else {
      long long Q = ft.query(r) - ft.query(l - 1);
      int lo = l, hi = r, res = l;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (2 * (ft.query(mid) - ft.query(l - 1)) >= Q)
          res = mid, hi = mid - 1;
        else
          lo = mid + 1;
      }
      long long res1 = 0, res2 = 0;
      res1 = ((ft.query(res) - ft.query(l - 1) + mod) % mod * a[res] % mod -
              (ft2.query(res) - ft2.query(l - 1) + mod) % mod + mod) %
             mod;
      res2 = ((ft2.query(r) - ft2.query(res) + mod) % mod -
              (ft.query(r) - ft.query(res) + mod) % mod * a[res] % mod + mod) %
             mod;
      long long ans = (res1 + res2) % mod;
      printf("%lld\n", ans);
    }
  }
}
