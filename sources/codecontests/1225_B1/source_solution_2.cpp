#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k, d, i, j, l, mi;
  cin >> t;
  for (i = 0; i < t; i++) {
    mi = 10000;
    cin >> n >> k >> d;
    int a[n];
    for (l = 0; l < n; l++) cin >> a[l];
    for (l = 0; l < n - d + 1; l++) {
      map<int, int> m;
      for (j = l; j < l + d; j++) m[a[j]]++;
      int I = 0;
      for (auto& j : m) I++;
      mi = min(mi, I);
    }
    cout << mi << endl;
  }
  return 0;
}
