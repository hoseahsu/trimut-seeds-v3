#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
struct sc {
  long long c, p;
};
vector<sc> l[maxn];
vector<sc> r[maxn];
long long n, k, m, M = 1, ma = 0, li, ri, ci, pi;
long long num[maxn << 2], sum[maxn << 2];
void update(long long p, long long c) {
  num[M + p] += (long long)c;
  sum[M + p] += (long long)c * p;
  int j = M + p;
  while (j >>= 1) {
    sum[j] = sum[j << 1] + sum[j << 1 | 1];
    num[j] = num[j << 1] + num[j << 1 | 1];
  }
}
long long ok(long long s, long long t) {
  long long ss = 0;
  long long tt = t;
  for (s += (M - 1), t += (M + 1); s ^ t ^ 1; s >>= 1, t >>= 1) {
    if (s % 2 == 0) ss += num[s ^ 1];
    if (t % 2 == 1) ss += num[t ^ 1];
  }
  if (ss >= k)
    return ss;
  else
    return 0;
}
long long q() {
  long long s = 1, t = ma, ans = ma, tep = 0;
  while (s <= t) {
    long long mid = (s + t) / 2;
    if (!ok(1, mid)) {
      s = mid + 1;
    } else {
      ans = mid;
      t = mid - 1;
    }
  }
  s = 1, t = ans;
  long long ss = 0;
  for (s += (M - 1), t += (M + 1); s ^ t ^ 1; s >>= 1, t >>= 1) {
    if (s % 2 == 0) ss += sum[s ^ 1];
    if (t % 2 == 1) ss += sum[t ^ 1];
  }
  if (ok(1, ans) <= k) return ss;
  return ss - ans * (ok(1, ans) - k);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> m;
  for (int i = 0; i < m; i++) {
    cin >> li >> ri >> ci >> pi;
    l[li].push_back({ci, pi});
    r[ri + 1].push_back({ci, pi});
    ma = max(pi, ma);
  }
  long long ans = 0;
  while (M <= ma) M <<= 1;
  for (long long i = 1; i <= n; i++) {
    for (int j = 0; j < l[i].size(); j++) update(l[i][j].p, l[i][j].c);
    for (int j = 0; j < r[i].size(); j++) update(r[i][j].p, -r[i][j].c);
    ans += q();
  }
  cout << ans << endl;
}
