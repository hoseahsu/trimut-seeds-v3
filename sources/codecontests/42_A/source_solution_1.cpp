#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  int a[n], b[n];
  double x = 1000000000;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    x = min(x, b[i] / (1. * a[i]));
  }
  double ans = min((double)v, x * sum);
  cout << ans << endl;
  return 0;
}
