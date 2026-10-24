#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> k;
  if (k < n / 2 || (n == 1 && k)) {
    cout << -1;
    return 0;
  }
  if (n == 1 && k == 0) {
    cout << 1;
    return 0;
  }
  k = k - (n - 2) / 2;
  cout << k << " " << k * 2 << " ";
  k = k * 2 + 1;
  for (int i = 0; i <= n - 3; i++) cout << k + i << " ";
  return 0;
}
