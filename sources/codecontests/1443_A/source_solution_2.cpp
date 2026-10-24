#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ;
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    long long cnt = 1;
    long long t = 4;
    for (long long i = 4 * n; i >= 2 * n + 2; i -= 2) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
