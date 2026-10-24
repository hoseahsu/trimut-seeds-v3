#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 0 << endl;
    return 0;
  }
  int maxd = 0;
  int mind = 100;
  int ans = 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans *= i;
      int temp = 0;
      while (n % i == 0) {
        n /= i;
        temp++;
      }
      maxd = max(maxd, temp);
      mind = min(mind, temp);
    }
  }
  if (n > 1) {
    ans *= n;
    maxd = max(maxd, 1);
    mind = min(mind, 1);
  }
  int ans1 = 0;
  int t = 1;
  while (t < maxd) {
    t *= 2;
    ans1++;
  }
  if (t > maxd || mind < maxd) {
    ans1++;
  }
  cout << ans << " " << ans1 << endl;
  return 0;
}
