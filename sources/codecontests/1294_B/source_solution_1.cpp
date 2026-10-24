#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tc, n;
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<long long> v[1001];
    long long i, a[1001] = {}, b, c[1001] = {};
    for (i = 0; i < n; i++) {
      cin >> a[i] >> b;
      c[a[i]]++;
      v[a[i]].push_back(b);
    }
    sort(a, a + n);
    bool r = false;
    for (i = 0; i < n; i += c[a[i]]) {
      sort(v[a[i]].begin(), v[a[i]].end());
      if (i) {
        if (v[a[i - 1]][c[a[i - 1]] - 1] > v[a[i]][0]) {
          r = true;
          break;
        }
      }
    }
    if (r) {
      cout << "NO\n";
    } else {
      long long h = 0, x = 0, j = 0;
      cout << "YES\n";
      for (i = 0; i < n; i += c[a[i]]) {
        for (j = x; j < a[i]; j++) {
          cout << "R";
          x++;
        }
        for (j = h; j < v[a[i]][c[a[i]] - 1]; j++) {
          cout << "U";
          h++;
        }
      }
      cout << "\n";
    }
  }
}
