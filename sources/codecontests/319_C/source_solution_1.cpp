#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
const long long maxn = 1e6 + 10, N = 500 + 10, SQRT = 300, base = 800287,
                mod = 1e9 + 7, INF = 1e9 + 1, lg = 23;
const long double eps = 1e-4;
long long n, x[maxn], y[maxn], dp[maxn], p;
vector<long long> st;
bool islower(long double a, long double b) { return a <= b; }
long double intersect(long long i, long long j) {
  long double type = (y[i] - y[j] < 0 ? -1 : 1);
  return (long double)(dp[j] - dp[i]) / (long double)(y[i] - y[j]);
}
void add_line(long long i) {
  while ((long long)st.size() && y[st.back()] >= y[i] &&
         dp[st.back()] >= dp[i]) {
    st.pop_back();
  }
  while ((long long)st.size() > 1 &&
         islower(intersect(i, st[(long long)st.size() - 2]),
                 intersect(st.back(), st[(long long)st.size() - 2]))) {
    st.pop_back();
  }
  st.push_back(i);
}
long long get_point(long long xx) {
  while (p + 1 < (long long)st.size() && intersect(st[p], st[p + 1]) <= xx) {
    p++;
  }
  return y[st[p]] * xx + dp[st[p]];
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> x[i];
  }
  for (long long i = 0; i < n; ++i) {
    cin >> y[i];
  }
  add_line(0);
  for (long long i = 1; i < n; ++i) {
    dp[i] = get_point(x[i]);
    add_line(i);
  }
  cout << dp[n - 1] << '\n';
}
