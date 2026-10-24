#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
  cin >> k;
  for (int i = 1; i < k; ++i) {
    for (int j = 1; j < k; ++j) {
      int res = i * j;
      res = (res / k) * 10 + (res % k);
      cout << res << ' ';
    }
    cout << endl;
  }
  return 0;
}
