#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)(1e18);
const long long inf = 1e9 + 7;
long double eps = 1e-5;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long mod = 998244853;
long long pows(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 1) return (a * pows(a, b - 1)) % mod;
  if (b % 2 == 0) {
    long long c = pows(a, b / 2);
    return (c * c) % mod;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> aa(n), bb(n);
    for (int i = 0; i < n; i++) cin >> aa[i] >> bb[i];
    vector<int> pref(n);
    vector<vector<int>> cc(n);
    for (int i = 0; i < n; i++) {
      cc[aa[i]].push_back(bb[i]);
    }
    pref[0] = cc[0].size();
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + cc[i].size();
    multiset<long long> st;
    int cnt = 0;
    long long res = 0;
    for (int i = n - 1; i > 0; i--) {
      if (cc[i].size() == 0) continue;
      for (auto it : cc[i]) st.insert(it);
      if (pref[i - 1] + cnt >= i) continue;
      int u = i - pref[i - 1];
      while (cnt < u) {
        res += *st.begin();
        st.erase(st.begin());
        cnt++;
      }
    }
    cout << res << endl;
  }
}
