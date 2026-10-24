#include <bits/stdc++.h>
using namespace std;
int a[10001];
int i, j, k, s, t, n;
map<int, int> m;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) m[a[i]]++;
  if (m.size() == 1) {
    cout << "Exemplary pages." << endl;
    return 0;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      if (a[i] <= a[j]) continue;
      s = a[i] - a[j];
      if (s % 2 == 1) continue;
      t = a[j] + s / 2;
      if (m[t] == n - 2) {
        cout << s / 2 << " ml. from cup #" << j << " to cup #" << i << "."
             << endl;
        return 0;
      }
    }
  cout << "Unrecoverable configuration." << endl;
  return 0;
}
