#include <bits/stdc++.h>
using namespace std;

int a[55], b[55], c[55], d[55];

int main() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (int i = 1; i <= m; i++) cin >> c[i] >> d[i];
  
  for (int i = 1; i <= n; i++) {
    int e = 1;
    for (int j = 2; j <= m; j++)
      if (abs(c[j] - a[i]) + abs(d[j] - b[i]) <
          abs(c[e] - a[i]) + abs(d[e] - b[i]))
        e = j;
    cout << e << endl;
  }
}