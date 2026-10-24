#include <bits/stdc++.h>
const long long inf = 1000000000000000000;
using namespace std;
bool prime[1000005];
long long fact[1000005];
long long gcd(long long a, long long b) {
  if (a < b) gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long x = (a / gcd(a, b)) * b;
  return x;
}
long long power(long long x, long long n, long long m = inf) {
  if (x == 0) return 0;
  if (n == 0) return 1;
  long long ans;
  if (n % 2 == 0) {
    long long smallAns = power(x, n / 2, m);
    ans = (smallAns * smallAns) % m;
  } else {
    long long smallAns = power(x, n - 1, m);
    ans = x;
    ans = (ans * smallAns) % m;
  }
  return (ans + m) % m;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCr(long long n, long long r, long long p = LLONG_MAX) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) %
          p) %
         p;
}
void fillFact() {
  fact[0] = 1;
  for (int i = 1; i < 1000005; i += 1) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
}
void fillPrime() {
  long long i, j, n = 1000001;
  for (int i = 0; i < n; i += 1) {
    prime[i] = 1;
  }
  prime[0] = 0;
  prime[1] = 0;
  for (i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (j = i * i; j <= n; j += i) {
        prime[j] = 0;
      }
    }
  }
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long kadane(long long arr[], int n) {
  long long dp[n];
  dp[0] = arr[0];
  long long maxm = dp[0];
  for (int i = 1; i < n; i += 1) {
    if (dp[i - 1] > 0)
      dp[i] = arr[i] + dp[i - 1];
    else
      dp[i] = arr[i];
    maxm = max(maxm, dp[i]);
  }
  return maxm;
}
bool compare(pair<int, int> p1, pair<int, int> p2) {
  return p1.second < p2.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int y, k, n;
    cin >> y >> k >> n;
    int div = (y / k);
    div += 1;
    div *= k;
    if (div > n) {
      cout << -1 << '\n';
      exit(0);
    }
    while (div <= n) {
      cout << div - y << " ";
      div += k;
    }
    cout << '\n';
  }
  return 0;
}
