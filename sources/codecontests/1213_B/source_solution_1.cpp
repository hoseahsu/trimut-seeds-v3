#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, min = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > min)
        ans++;
      else
        min = a[i];
    }
    cout << ans << endl;
  }
}
