#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n;
  cin >> k;
  for (int v(100); v >= 3; --v) {
    if (v * (v - 1) * (v - 2) / 6 < k) {
      n = v;
      k -= v * (v - 1) * (v - 2) / 6;
      break;
    } else {
      if (v * (v - 1) * (v - 2) / 6 == k) {
        cout << v << endl;
        for (int i(0); i < v; ++i) {
          for (int j(0); j < v; ++j) {
            if (i == j)
              cout << 0;
            else
              cout << 1;
          }
          cout << endl;
        }
        return 0;
      }
    }
  }
  int data[104][104];
  for (int i(0); i < n; ++i)
    for (int j(0); j < n; ++j) data[i][j] = 1;
  int edge(2);
  while (k) {
    int i(1);
    for (;; ++i) {
      if (i * (i + 1) / 2 > k) break;
    }
    for (int j(0); j < i; ++j) {
      data[n][j] = data[j][n] = 1;
    }
    ++n;
    k -= i * (i - 1) / 2;
  }
  cout << n << endl;
  for (int i(0); i < n; ++i) {
    for (int j(0); j < n; ++j)
      if (i == j)
        cout << 0;
      else
        cout << data[i][j];
    cout << endl;
  }
  return 0;
}
