#include <bits/stdc++.h>
using namespace std;
long long GCD(long long x, long long y) {
  if (y == 0) return x;
  return GCD(y, x % y);
}
long long LCM(long long x, long long y) { return (x * y) / (GCD(x, y)); }
long long LOGK(long long x, long long k) {
  if (x >= k) return 1 + LOGK(x / k, k);
  return 0;
}
long long MPOW(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long x = MPOW(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2 == 1) x = (x * a) % m;
  return x;
}
long long MINV(long long a, long long m) { return MPOW(a, m - 2, m); }
class pnc {
  long long FACT_MAX, MODU;
  vector<long long> fact;

 public:
  pnc(long long n, long long m) {
    FACT_MAX = n;
    fact.resize(FACT_MAX);
    MODU = m;
    MFACT_INIT(MODU);
  }
  void MFACT_INIT(long long m) {
    fact[0] = 1;
    for (long long i = 1; i < FACT_MAX; ++i) fact[i] = (i * fact[i - 1]) % MODU;
  }
  long long MFACT(long long n) { return fact[n]; }
  long long PERM(long long n, long long r) {
    return (fact[n] * ::MINV(fact[n - r], MODU)) % MODU;
  }
  long long COMB(long long n, long long r) {
    return (PERM(n, r) * ::MINV(fact[r], MODU)) % MODU;
  }
};
long long n;
long long ar[100005];
long long dp[100005];
long long spt[100005][20];
long long idx[100005][20];
void build() {
  for (long long i = 0; i < n; i++) {
    spt[i][0] = ar[i];
    idx[i][0] = i;
  }
  long long logn = log2(n);
  for (long long j = 1; j <= logn; j++) {
    for (long long i = 0; i <= n - (1 << j); i++) {
      if (spt[i][j - 1] >= spt[i + (1 << (j - 1))][j - 1]) {
        spt[i][j] = spt[i][j - 1];
        idx[i][j] = idx[i][j - 1];
      } else {
        spt[i][j] = spt[i + (1 << (j - 1))][j - 1];
        idx[i][j] = idx[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}
long long query(long long L, long long R) {
  long long k = log2(R - L + 1);
  if (spt[L][k] >= spt[R - (1 << k) + 1][k]) {
    return idx[L][k];
  } else {
    return idx[R - (1 << k) + 1][k];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) {
    cin >> n;
    for (long long i = 0; i < n - 1; i++) {
      cin >> ar[i];
      ar[i]--;
    }
    ar[n - 1] = n - 1;
    dp[n - 1] = 0;
    build();
    for (long long i = n - 2; i >= 0; i--) {
      long long m = query(i + 1, ar[i]);
      dp[i] = dp[m] + (n - 1 - i) - (ar[i] - m);
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) ans += dp[i];
    cout << ans;
  }
}
