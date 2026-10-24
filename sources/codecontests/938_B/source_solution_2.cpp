#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = max(sum, min(abs(1 - a[i]), abs(1000000 - a[i])));
  }
  cout << sum;
  return 0;
}
