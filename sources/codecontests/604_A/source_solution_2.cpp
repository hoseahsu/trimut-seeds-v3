#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  int m[5], w[5], pt[5]{500, 1000, 1500, 2000, 2500};
  int ans = 0;
  int h1, h2;
  for (i = 0; i < 5; i++) cin >> m[i];
  for (i = 0; i < 5; i++) cin >> w[i];
  cin >> h1 >> h2;
  for (i = 1; i <= 5; i++) {
    ans += max(pt[i - 1] - pt[i - 1] * m[i - 1] / 250 - 50 * w[i - 1], 150 * i);
  }
  ans += h1 * 100 - h2 * 50;
  cout << ans;
  return 0;
}
