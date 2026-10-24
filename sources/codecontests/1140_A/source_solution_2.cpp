#include <bits/stdc++.h>
using namespace std;
void run_case() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int ans = 0;
  int Max = -1;
  for (int i = 1; i <= n; ++i) {
    Max = max(Max, a[i]);
    if (Max == i) ans++;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.flags(ios::fixed);
  cout.precision(2);
  run_case();
  cout.flush();
  return 0;
}
