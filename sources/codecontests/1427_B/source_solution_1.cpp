#include <bits/stdc++.h>
using namespace std;
long long Min(long long a, long long b) { return (a < b) ? a : b; }
long long Max(long long a, long long b) { return (a < b) ? b : a; }
long long gcd(long long m, long long n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
long long dx[6] = {-1, 0, 1, 0, 0, 0}, dy[6] = {0, 1, 0, -1, 0, 0},
          dz[6] = {0, 0, 0, 0, 1, -1};
void solve() {
  long long n, k;
  string s;
  cin >> n >> k >> s;
  long long cnt = 0, ccnt = 0, ans = 0;
  deque<long long> v;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L')
      cnt++, ccnt++;
    else {
      if (ccnt > 0) v.push_back(ccnt);
      ccnt = 0;
    }
    if (s[i] == 'W') {
      if (i > 0 && s[i - 1] == 'W')
        ans += 2;
      else
        ans++;
    }
  }
  if (ccnt > 0) v.push_back(ccnt);
  if (!v.empty() && s[0] == 'L') v.pop_front();
  if (!v.empty() && s[n - 1] == 'L') v.pop_back();
  if (cnt <= k) {
    cout << 2 * n - 1 << "\n";
    return;
  }
  if (cnt == n) {
    if (k == 0)
      cout << "0\n";
    else
      cout << 2 * k - 1 << '\n';
    return;
  }
  sort((v).begin(), (v).end());
  ans += 2 * k;
  long long idx = 0;
  while (k > 0) {
    if (idx < v.size() && k >= v[idx]) {
      k -= v[idx];
      ans++;
    } else {
      break;
    }
    idx++;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  cin >> tc;
  while (tc--) solve();
  exit(0);
}
