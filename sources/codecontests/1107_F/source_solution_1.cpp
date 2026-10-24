#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n;
long long s[N], f[N], ans;
struct gp {
  long long a, b, k;
} p[N];
bool cmp(gp x, gp y) { return x.b > y.b; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &p[i].a, &p[i].b, &p[i].k);
  }
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 0; j--) {
      f[j] = max(f[j], f[j] + p[i].a - p[i].b * p[i].k);
      if (j == 0) continue;
      f[j] = max(f[j], f[j - 1] + p[i].a - p[i].b * (j - 1));
    }
  }
  for (int i = 0; i <= n; i++) ans = max(ans, f[i]);
  printf("%lld\n", ans);
}
