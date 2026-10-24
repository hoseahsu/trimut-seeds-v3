#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio();
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m, i, x, y, p;
  cin >> n >> m;
  vector<int> a, b;
  for (i = 0; i < n; i++) {
    cin >> p;
    a.push_back(p);
  }
  for (i = 0; i < m; i++) {
    cin >> p;
    b.push_back(p);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        cout << a[i];
        return 0;
      }
    }
  }
  x = *min_element(a.begin(), a.end());
  y = *min_element(b.begin(), b.end());
  cout << min(x, y) << max(x, y);
}
