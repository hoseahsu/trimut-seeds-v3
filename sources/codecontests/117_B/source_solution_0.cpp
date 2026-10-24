#include <bits/stdc++.h>
using namespace std;
int const MAX = 1000 * 1000 * 1000;
int main() {
  long long a, b, m, i;
  cin >> a >> b >> m;
  if (m <= b + 1 || MAX % m == 0) {
    cout << 2;
    return 0;
  }
  for (i = 1; i <= min(m - 1, a); ++i) {
    int k = MAX * i % m;
    if (0 < k && k < m - b) {
      printf("1\n%09I64d", i);
      return 0;
    }
  }
  cout << 2;
  return 0;
}
