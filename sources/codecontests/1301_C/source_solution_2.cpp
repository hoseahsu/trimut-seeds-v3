#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (m == 0) {
      cout << 0 << endl;
      continue;
    }
    long long ans = (n * (n + 1)) / 2;
    if (m == n) {
      cout << ans << endl;
      continue;
    }
    n -= m;
    long long a = n / (m + 1), b = n % (m + 1);
    ans -= b * (((a + 1) * (a + 2)) / 2);
    ans -= (m + 1 - b) * ((a * (a + 1)) / 2);
    cout << ans << endl;
  }
}
