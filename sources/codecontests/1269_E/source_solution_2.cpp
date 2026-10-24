#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
long long a[N], id[N];
pair<long long, long long> G[N];
void Upd(int x, int y) {
  while (x <= n) {
    G[x].first++;
    G[x].second += y;
    x += (x & -x);
  }
}
pair<long long, long long> Get(int x) {
  pair<long long, long long> res;
  res.first = res.second = 0;
  while (x > 0) {
    res.first += G[x].first;
    res.second += G[x].second;
    x -= (x & -x);
  }
  return res;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    id[a[i]] = i;
  }
  long long inv = 0;
  for (int i = 1; i <= n; i++) {
    long long idx = id[i], ans = 0;
    inv += Get(n).first - Get(idx).first;
    ans = inv;
    Upd(idx, idx);
    long long l = 1, r = n, mid, res = -1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (Get(mid).first >= (i + 1) / 2) {
        res = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    long long totR = res + Get(n).first - Get(res).first;
    ans += Get(n).second - Get(res).second -
           (totR * (totR + 1) / 2 - res * (res + 1) / 2);
    long long totL = res - Get(res - 1).first;
    ans += (res - 1) * res / 2 - (totL - 1) * totL / 2 - Get(res - 1).second;
    printf("%lld ", ans);
  }
}
