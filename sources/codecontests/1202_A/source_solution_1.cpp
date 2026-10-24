#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, i, j, k, t, yaz, T;
  cin >> T;
  for (i = 1; i <= T; i++) {
    string x, y;
    cin >> x >> y;
    t = 0;
    yaz = 0;
    for (j = y.length() - 1; j >= 0 && y[j] == '0'; j--, t++)
      ;
    for (k = x.length() - 1 - t; k >= 0 && x[k] == '0'; k--, yaz++)
      ;
    cout << yaz << endl;
  }
  return 0;
}
