#include <bits/stdc++.h>
using namespace std;
int a[100001];
int xval = 0, n;
void solve() {
  for (int i = 30; i >= 0; i--) {
    if (!(xval & ((1 << i)))) continue;
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << i)) cnt++;
    }
    if (cnt == 1) {
      cout << "WIN" << endl;
      return;
    }
    if (cnt == 3) {
      if ((n - cnt) % 2)
        cout << "WIN" << endl;
      else
        cout << "LOSE" << endl;
      return;
    }
    if (((cnt - 1) / 2) % 2) {
      if ((n - cnt) % 2)
        cout << "WIN" << endl;
      else
        cout << "LOSE" << endl;
    } else
      cout << "WIN" << endl;
    return;
  }
  cout << "DRAW" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    xval = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      xval ^= a[i];
    }
    solve();
  }
  return 0;
}
