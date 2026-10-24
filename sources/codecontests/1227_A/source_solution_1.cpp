#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, a[100001], b[100001];
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    sort(a, a + n, greater<int>());
    sort(b, b + n);
    if (n == 1 || (a[0] - b[0]) < 0)
      cout << 0 << endl;
    else
      cout << a[0] - b[0] << endl;
  }
}
