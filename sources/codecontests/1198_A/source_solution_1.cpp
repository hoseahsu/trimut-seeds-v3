#include <bits/stdc++.h>
using namespace std;
const int dl = 1e9 + 7;
const int M = 4e5 + 10;
int a[M];
map<int, int> cnt;
int presum[M];
int tt[M];
int n;
long long s;
long long k;
int32_t main() {
  cin >> n >> s;
  long long t = (8 * s) / n;
  if (t >= 31) {
    cout << "0";
    return 0;
  }
  k = 1 << t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int sz = 1;
  for (auto x : cnt) {
    tt[sz] = x.first;
    presum[sz] = presum[sz - 1] + x.second;
    sz++;
  }
  int ans = n;
  for (int i = 1; i < sz; i++) {
    int y = i + k;
    if (i + k >= sz)
      ans = min(ans, presum[i - 1]);
    else {
      ans = min(ans, n - presum[y - 1] + presum[i - 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
