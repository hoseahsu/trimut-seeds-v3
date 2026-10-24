#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:667772160")
using namespace std;
struct __isoff {
  __isoff() {
    if (0) freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
  }
  ~__isoff() {}
} __osafwf;
const unsigned long long p1 = 31;
const unsigned long long p2 = 29;
const double eps = 1e-8;
const double pi = acos(-1.0);
const long long inf = 1e17 + 7;
const int infi = 1e9 + 7;
const long long dd = 3e2 + 7;
const long long mod = 1e9 + 9;
int F[dd], Z[dd], R[dd], G[dd];
pair<int, int> Q[25000][dd];
vector<long long> V;
map<long long, long long> P;
int main() {
  long long n, tt;
  cin >> n >> tt;
  for (long long i = 0; i < (long long)n; i++) {
    long long t;
    cin >> t;
    Z[t]++;
    V.push_back(t);
  }
  int z = min(tt - 1, n * 2) * n;
  for (long long i = 0; i < (long long)z; i++) V.push_back(V[i % n]);
  for (long long i = 0; i < (long long)V.size(); i++) {
    int t = 0;
    for (long long j = 0; j < (long long)V[i] + 1; j++) {
      if (F[t] < F[j]) t = j;
    }
    if (i)
      for (long long j = 0; j < (long long)dd; j++) Q[i][j] = Q[i - 1][j];
    Q[i][V[i]] = make_pair(t, G[t]);
    F[V[i]] = F[t] + 1;
    G[V[i]] = i;
  }
  int t = 0, zz = 0;
  for (long long i = 0; i < (long long)dd; i++) {
    if (F[i] > F[t]) t = i;
  }
  zz = F[t];
  int g = G[t];
  while (t) {
    int tq = Q[g][t].first;
    int tw = Q[g][t].second;
    R[t]++;
    g = tw;
    t = tq;
  }
  t = 0;
  for (long long i = 0; i < (long long)dd; i++) {
    if (R[i] > R[t]) t = i;
  }
  cout << zz + (tt - (z / n + 1)) * 1ll * Z[t];
}
