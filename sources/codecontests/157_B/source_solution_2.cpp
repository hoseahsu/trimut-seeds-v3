#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> radius(n, 0);
  for (int i = 0; i < n; i++) cin >> radius[i];
  sort(radius.begin(), radius.end());
  double ans = 0;
  if (n % 2 == 0) {
    for (int i = 1; i < n; i += 2) {
      int dist = radius[i] * radius[i];
      int minus = radius[i - 1] * radius[i - 1];
      ans += (double)(dist - minus);
    }
  } else {
    ans += (double)(radius[0] * radius[0]);
    for (int i = 2; i < n; i += 2) {
      int dist = radius[i] * radius[i];
      int minus = radius[i - 1] * radius[i - 1];
      ans += (double)(dist - minus);
    }
  }
  cout << fixed << setprecision(9) << ans * 3.141592653 << "\n";
  return 0;
}
