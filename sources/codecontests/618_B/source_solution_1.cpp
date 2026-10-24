#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n][n], i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  set<int> se;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      se.insert(a[i][j]);
    }
    if (se.size() == n) {
      for (k = 0; k < n; k++) {
        if (a[i][k] == 0) {
          cout << n << " ";
        } else {
          cout << a[i][k] << " ";
        }
      }
      break;
    } else {
      se.clear();
    }
  }
  return 0;
}
