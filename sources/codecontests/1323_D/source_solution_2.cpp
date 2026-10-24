#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long int N = 100005, M = 27;
void solve() {
  long long int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
  cin >> n;
  long long int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int res[M] = {};
  for (j = M - 1; j >= 0; j--) {
    long long int two_pow = (1ll << (j + 1));
    two_pow -= 1;
    for (i = 0; i < n; i++) {
      a[i] = a[i] & two_pow;
    }
    sort(a, a + n);
    for (i = 0; i < n; i++) {
      long long int tot1 =
          upper_bound(a + i + 1, a + n, (1ll << (j + 2)) - 2 - a[i]) -
          lower_bound(a + i + 1, a + n, (1ll << (j + 1)) + (1ll << j) - a[i]);
      long long int tot2 =
          upper_bound(a + i + 1, a + n, (1ll << (j + 1)) - 1 - a[i]) -
          lower_bound(a + i + 1, a + n, (1ll << j) - a[i]);
      res[j] += tot1;
      res[j] += tot2;
    }
  }
  for (i = 0; i < M; i++) {
    ans += (1ll << i) * (res[i] % 2 == 1);
  }
  cout << ans;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
