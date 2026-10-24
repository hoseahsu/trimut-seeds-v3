#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool sortbyval(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool sortbyth(const tuple<long long, long long, long long> &a,
              const tuple<long long, long long, long long> &b) {
  return get<1>(a) < get<1>(b);
}
bool p[1000000];
void sieve() {
  memset(p, true, sizeof(p));
  p[0] = false;
  p[1] = false;
  for (long long i = 2; i * i <= 1000000; i++) {
    if (p[i] == true) {
      for (long long j = i * i; j <= 1000000; j += i) {
        if (p[j] == true) p[j] = false;
      }
    }
  }
}
long long powr(long long n, long long m) {
  if (m == 0) return 1;
  long long temp = powr(n, m / 2) % 1000000007;
  if (m & 1) {
    return ((temp * temp) % 1000000007 * n % 1000000007) % 1000000007;
  } else {
    return (temp * temp) % 1000000007;
  }
}
long long pown(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b % 2 == 1) {
      r = (r * a) % 1000000007;
    }
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return r;
}
long long fact(long long n) {
  if (n == 0 or n == 1) return 1;
  return n * fact(n - 1);
}
long long power(long long x, long long n, long long M) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return power((x * x) % M, n / 2, M);
  else
    return (x * power((x * x) % M, (n - 1) / 2, M)) % M;
}
vector<long long> par(101, -1);
long long find(long long a) {
  if (par[a] < 0)
    return a;
  else
    return par[a] = find(par[a]);
}
void merge(long long a, long long b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    par[a] += par[b];
    par[b] = a;
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v[n];
  for (long long i = 0; i < n; i++) {
    long long t;
    cin >> t;
    for (long long j = 0; j < t; j++) {
      long long a;
      cin >> a;
      v[i].push_back(a);
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long k : v[i]) {
      for (long long j = i + 1; j < n; j++) {
        if (find(v[j].begin(), v[j].end(), k) != v[j].end()) {
          merge(i, j);
        }
      }
    }
  }
  long long ct = 0;
  for (long long i = 0; i < n; i++)
    if (v[i].size() == 0) ct++;
  if (ct == n) {
    cout << n << "\n";
    return;
  }
  ct = 0;
  for (long long i = 0; i < n; i++)
    if (par[i] < 0) ct++;
  cout << abs(ct) - 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
