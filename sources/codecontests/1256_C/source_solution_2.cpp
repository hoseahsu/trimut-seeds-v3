#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int c[MAX_N];
int rv[MAX_N];
int main() {
  int n, m, d, suml;
  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) cin >> c[i];
  for (int i = m, pos = n; i >= 1; i--) {
    for (int j = 0; j < c[i]; j++) {
      rv[pos - j] = i;
    }
    pos -= c[i];
  }
  int pos = 0, flag = false;
  for (int i = 1; i <= m; i++) {
    pos += d;
    if (pos > n || rv[pos]) {
      flag = true;
      break;
    }
    int plat = pos + 1;
    while (!rv[plat]) plat++;
    int len = c[rv[plat]];
    for (int j = 0; j < len; j++) {
      swap(rv[pos + j], rv[plat + j]);
    }
    pos += len - 1;
  }
  if (pos + d > n || flag) {
    cout << "YES\n";
    cout << rv[1];
    for (int i = 2; i <= n; i++) cout << ' ' << rv[i];
  } else
    cout << "NO";
  return 0;
}
