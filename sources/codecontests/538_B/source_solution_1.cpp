#include <bits/stdc++.h>
using namespace std;
int n;
int t[20], r[20], dp[20];
int x, y, z;
int mx, k = 1, a = 1;
int main() {
  cin >> n;
  t[0] = 1, x = n, y = n;
  while (x > 9) {
    t[k] = t[k - 1] * 10;
    x /= 10;
    a += t[k];
    k++;
  }
  for (int i = 0; i < k; i++) {
    z = y % 10;
    r[z] += t[i];
    mx = max(mx, z);
    y /= 10;
  }
  dp[0] = a - r[0];
  cout << mx << endl, cout << dp[0] << " ";
  for (int i = 1; i < mx; i++) {
    dp[i] = dp[i - 1] - r[i];
    cout << dp[i] << " ";
  }
  cout << endl;
}
