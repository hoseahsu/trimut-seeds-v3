#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
using namespace std;
const int N = 1e6 + 5;
vector<pair<int, int> > ad[N], dl[N];
int n, k, m, l, r, c, p, up;
long long a[N], b[N];
void add(long long *bit, int x, long long a) {
  while (x < N) bit[x] += a, x += x & -x;
}
long long sum(long long *bit, int x) {
  long long res = 0;
  while (x) res += bit[x], x -= x & -x;
  return res;
}
int query(long long *bit) {
  int now = 0, tmp = 0;
  for (int i = 19; i >= 0; --i) {
    if (now + (1 << i) < N && tmp + bit[now + (1 << i)] <= up) {
      now += 1 << i;
      tmp += bit[now];
    }
  }
  return now + 1;
}
int main() {
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d %d", &l, &r, &c, &p);
    ad[l].push_back({p, c});
    dl[r + 1].push_back({p, c});
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (pair<int, int> p : ad[i]) {
      add(a, p.first, p.second);
      add(b, p.first, p.first * 1LL * p.second);
    }
    for (pair<int, int> p : dl[i]) {
      add(a, p.first, -p.second);
      add(b, p.first, -p.first * 1LL * p.second);
    }
    up = min(sum(a, N - 1), 1LL * k);
    int p = query(a);
    ans += sum(b, p - 1) + p * 1LL * (up - sum(a, p - 1));
  }
  printf("%lld\n", ans);
  return 0;
}
