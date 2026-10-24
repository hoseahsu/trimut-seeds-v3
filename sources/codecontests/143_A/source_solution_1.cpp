#include <bits/stdc++.h>
using namespace std;
void solve() {
  int r1, r2, c1, c2, d1, d2;
  cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (i + j == r1 && i != j) {
        for (int k = 1; k < 10; k++) {
          if (i + k == c1 && k + j == d2 && j != k && i != k) {
            for (int l = 1; l < 10; l++) {
              if (l + k == r2 && l + i == d1 && l != k && l != i && j != l) {
                cout << i << " " << j << '\n';
                cout << k << " " << l << '\n';
                return;
              }
            }
          }
        }
      }
    }
  }
  cout << -1 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
