#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, z, a[500005], ans = 0, val = 0;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    cout << (val + x) / m - val / m << " ";
    val += x;
  }
  return 0;
}
