#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[200005], i, j, b, c, d, e, f, g, h;
  cin >> n;
  c = 0;
  d = 1;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; i++) {
    if (a[i] >= d) {
      c++;
      d++;
    }
  }
  cout << c;
}
