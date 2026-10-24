#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
vector<long long> lastprime(N, -1);
vector<long long> factors[N];
void sieve_lastprime() {
  lastprime[0] = lastprime[1] = 0;
  for (long long i = 2; i < N; i++) {
    if (lastprime[i] == -1) {
      for (long long j = i * i; j < N; j += i) lastprime[j] = i;
      for (long long j = i; j < N; j += i) factors[j].push_back(i);
    }
  }
}
vector<long long> phi(N);
void sieve_phi() {
  for (long long i = 0; i < N; i++) phi[i] = i;
  for (long long i = 2; i < N; i++) {
    if (phi[i] == i)
      for (long long j = i; j < N; j += i) phi[j] -= (phi[j] / i);
  }
}
long long get2(long long p, long long x) {
  long long cnt = 0;
  long long sz = factors[p].size();
  for (long long i = 0; i < (1LL << sz); i++) {
    long long num = 1;
    for (long long j = 0; j < sz; j++)
      if ((i >> j) & 1) num *= factors[p][j];
    long long vals = (x / num);
    if (__builtin_popcount(i) & 1)
      cnt -= vals;
    else
      cnt += vals;
  }
  return cnt;
}
long long get(long long p, long long x) {
  long long res = 0;
  long long full = (x / p);
  res += full * phi[p];
  long long partial = (x % p);
  res += get2(p, partial);
  return res;
}
void solve() {
  long long x, p, k;
  cin >> x >> p >> k;
  long long coprimes_upto_x = get(p, x);
  k += coprimes_upto_x;
  long long l = 1;
  long long r = 1e9;
  long long res = r;
  vector<long long> add, rem;
  long long sz = factors[p].size();
  for (long long i = 0; i < (1 << sz); i++) {
    long long num = 1;
    for (long long j = 0; j < sz; j++)
      if ((i >> j) & 1) num *= factors[p][j];
    if (__builtin_popcount(i) & 1)
      rem.push_back(num);
    else
      add.push_back(num);
  }
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long cnt = 0;
    cnt += phi[p] * (mid / p);
    long long partial = (mid % p);
    for (auto x : add) cnt += (partial / x);
    for (auto x : rem) cnt -= (partial / x);
    if (cnt >= k) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << res << '\n';
}
signed main() {
  sieve_phi();
  sieve_lastprime();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
