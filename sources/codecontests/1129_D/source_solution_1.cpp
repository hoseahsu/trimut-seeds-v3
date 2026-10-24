#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
struct bucket {
  long long size, minm;
  vector<long long> off;
  vector<long long> dps;
  vector<long long> pre;
  bucket(long long b) {
    size = b;
    off = vector<long long>(b);
    pre = vector<long long>(b);
    dps = vector<long long>(b);
    minm = 0;
  }
  void updoff(long long p, long long l, long long r) {
    assert(l >= 0 && l < size && r >= 0 && r < size && l <= r);
    long long nmnm = INT_MAX;
    for (long long j = l; j <= r; ++j) nmnm = min(nmnm, minm + off[j] + p);
    for (long long j = 0; j < l; ++j) nmnm = min(nmnm, minm + off[j]);
    for (long long j = r + 1; j < size; ++j) nmnm = min(nmnm, minm + off[j]);
    for (long long j = 0; j < l; ++j) off[j] = off[j] + minm - nmnm;
    for (long long j = l; j <= r; ++j) off[j] = off[j] + minm + p - nmnm;
    for (long long j = r + 1; j < size; ++j) off[j] = off[j] + minm - nmnm;
    minm = nmnm;
    pre = vector<long long>(size);
    for (long long j = 0; j < size; ++j)
      pre[off[j]] = (pre[off[j]] + dps[j]) % mod;
    for (long long j = 1; j < size; ++j) pre[j] = (pre[j] + pre[j - 1]) % mod;
  }
  void upddp(long long idx, long long newdp) {
    dps[idx] = newdp;
    pre = vector<long long>(size);
    for (long long j = 0; j < size; ++j)
      pre[off[j]] = (pre[off[j]] + dps[j]) % mod;
    for (long long j = 1; j < size; ++j) pre[j] = (pre[j] + pre[j - 1]) % mod;
  }
};
void update_offset(vector<bucket> &ds, long long n, long long l, long long r,
                   long long p, long long b) {
  assert(l <= r);
  long long j = r / b;
  ds[j].updoff(p, max(l, j * b) - j * b, r - j * b);
  j--;
  while (j * b > l) {
    ds[j].minm += p;
    j--;
  }
  if (l >= j * b && l < (j + 1) * b) ds[j].updoff(p, l - j * b, b - 1);
}
long long query(vector<bucket> &ds, long long n, long long r, long long b,
                long long k) {
  long long j = r / b;
  long long ret = 0;
  while (j >= 0) {
    long long idx = k - ds[j].minm;
    if (idx >= 0) ret = (ret + ds[j].pre[min(idx, b - 1)]) % mod;
    j--;
  }
  return ret;
}
int32_t main() {
  long long n, k;
  cin >> n >> k;
  long long b = sqrt(n);
  long long m = ceil((double)n / b);
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  vector<bucket> ds;
  for (long long i = 0; i < m; ++i) {
    bucket B = bucket(b);
    ds.push_back(B);
  }
  vector<long long> lo(n + 1, -1);
  vector<long long> llo(n + 1, -1);
  vector<long long> dp(n);
  dp[0] = 1;
  lo[a[0]] = 0;
  ds[0].updoff(1, 0, 0);
  ds[0].upddp(0, 1);
  if ((1 / b) < m) ds[1 / b].upddp(1 - (1 / b) * b, 1);
  for (long long i = 1; i < n; ++i) {
    if (lo[a[i]] != -1) update_offset(ds, n, llo[a[i]] + 1, lo[a[i]], -1, b);
    update_offset(ds, n, lo[a[i]] + 1, i, 1, b);
    dp[i] = query(ds, n, i, b, k);
    long long j = (i + 1) / b;
    if (j < m) ds[j].upddp((i + 1) - j * b, dp[i]);
    llo[a[i]] = lo[a[i]];
    lo[a[i]] = i;
  }
  cout << dp[n - 1];
}
