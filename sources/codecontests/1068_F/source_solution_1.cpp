#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int z = (i + 3) / 4;
    int m = i % 4;
    if (m == 0) cout << 0 << ' ' << z << '\n';
    if (m == 1) cout << z << ' ' << 0 << '\n';
    if (m == 2) cout << 0 << ' ' << -z << '\n';
    if (m == 3) cout << -z << ' ' << 0 << '\n';
  }
  return (0);
}
