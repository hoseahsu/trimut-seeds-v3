#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string to_string(string s) { return s; }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return (string)s; }
template <class A, class B>
string to_string(pair<A, B> p);
template <class T>
string to_string(T v) {
  string s = "{", sep = "";
  for (auto x : v) {
    s += sep;
    sep = ", ";
    s += to_string(x);
  }
  return s + "}";
}
template <class A, class B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void dbgPrint() { cerr << endl; }
template <class A, class... B>
void dbgPrint(A a, B... b) {
  cerr << " " << to_string(a);
  dbgPrint(b...);
}
const int N = 1e5 + 2;
const int K = 101;
const long long INF = 1e17;
long long a[N];
long long pr[N];
long long dp[K][N];
long long get(int l, int r) { return a[r - 1] * (r - l) - (pr[r] - pr[l]); }
int calc(int i, int j, int o_l, int o_r) {
  int ans = -1;
  for (int k = o_l; k <= min(o_r, j - 1); ++k) {
    long long x = dp[i - 1][k] + get(k, j);
    if (dp[i][j] >= x) {
      ;
      dp[i][j] = x;
      ans = k;
    }
  }
  return ans;
}
void dnq(int i, int l, int r, int o_l, int o_r) {
  if (r == l) return;
  int m = (r + l) / 2;
  int t = calc(i, m, o_l, o_r);
  dnq(i, l, m, o_l, t);
  dnq(i, m + 1, r, t, o_r);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(30);
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> pref(n);
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    pref[i + 1] = pref[i] + x;
  }
  for (int i = 0; i < m; ++i) {
    long long t, b;
    cin >> t >> b;
    a[i] = b - pref[t - 1];
  }
  sort(a, a + m);
  for (int i = 0; i < m; ++i) pr[i + 1] = pr[i] + a[i];
  for (int i = 0; i < K; ++i)
    for (int j = 0; j < N; ++j) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 1; i <= k; ++i) dnq(i, 1, m + 1, 0, m + 1);
  cout << dp[k][m] << "\n";
  return 0;
}
