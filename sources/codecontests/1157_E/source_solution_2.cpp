#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long power(long long a, long long b, long long p) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, val;
  multiset<long long> s;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> val;
    s.insert(val);
  }
  for (long long i = 0; i < n; i++) {
    val = v[i];
    auto it = s.lower_bound(n - val);
    if (it == s.end()) it = s.begin();
    val += *it;
    val %= n;
    cout << val << " ";
    s.erase(it);
  }
}
