#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base ::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, total = 0;
    cin >> n >> m;
    int a[n];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      total = total + a[i];
    }
    if (total == m) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
