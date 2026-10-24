#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 5], mn = 1e10, cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      mn = min(mn, a[i]);
      if (mn < a[i]) cnt++;
    }
    cout << cnt << endl;
  }
}
