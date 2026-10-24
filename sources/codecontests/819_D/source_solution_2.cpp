#include <bits/stdc++.h>
using namespace std;
const int SIZEN = 200010;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
void extend_gcd(long long a, long long b, long long &x, long long &y,
                long long &d) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
  } else {
    extend_gcd(b, a % b, y, x, d);
    y -= (a / b) * x;
  }
}
long long inverse(long long a, long long MOD) {
  long long x, y, d;
  extend_gcd(a, MOD, x, y, d);
  return (x + MOD) % MOD;
}
long long T, S, n;
long long d[SIZEN] = {0};
long long A[SIZEN] = {0};
map<long long, vector<int> > M;
long long ans[SIZEN] = {0};
long long G, L;
long long S1;
bool sp_sort(pair<long long, int> a, pair<long long, int> b) {
  if (a.first != b.first) return a.first < b.first;
  return A[a.second] > A[b.second];
}
void calc_ring(vector<int> &ids) {
  vector<pair<long long, int> > p;
  for (int i = 0; i < ids.size(); i++) {
    int t = ids[i];
    long long a = A[t] - A[t] % G;
    p.push_back(make_pair(a / G % L * S1 % L, t));
  }
  sort(p.begin(), p.end(), sp_sort);
  for (int i = 1; i < p.size(); i++) {
    ans[p[i - 1].second] = p[i].first - p[i - 1].first;
  }
  ans[p.back().second] = p[0].first + L - p.back().first;
}
void work(void) {
  G = gcd(T, S);
  L = T / G;
  S1 = inverse(S / G, L);
  for (int i = 1; i <= n; i++) {
    M[A[i] % G].push_back(i);
  }
  for (map<long long, vector<int> >::iterator key = M.begin(); key != M.end();
       key++) {
    calc_ring(key->second);
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
  printf("\n");
}
void read(void) {
  scanf("%I64d%I64d", &T, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &d[i]);
    A[i] = A[i - 1] + d[i];
    assert(A[i] > 0);
  }
  S = A[n];
}
int main() {
  read();
  work();
  return 0;
}
